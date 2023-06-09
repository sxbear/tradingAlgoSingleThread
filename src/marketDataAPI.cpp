#include <nlohmann/json.hpp>
#include <optional>
#include <iostream>
#include "MarketDataAPI.h"
#include <include/curl/curl.h>

//helper function to handle the data returned by libcurl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

MarketDataAPI::MarketDataAPI(const std::string& apiKey) : apiKey(apiKey) {}

std::optional<std::vector<MarketDataPoint>> MarketDataAPI::getHistoricalData(const std::string& symbol, const std::string& interval) {
    // Initialize libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return std::nullopt;
    }

    // Create the URL for the API request
    std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" + symbol + "&apikey=" + apiKey;


    // Set up libcurl to make the request
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Set up a string to store the response
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Make the request
    CURLcode res = curl_easy_perform(curl);
    
    // Check for errors in curl execution
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return std::nullopt;
    }
    
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    
    // Check for non-200 HTTP response
    if (response_code != 200) {
        std::cerr << "API request failed with response code: " << response_code << std::endl;
        curl_easy_cleanup(curl);
        return std::nullopt;
    }

    // Clean up curl
    curl_easy_cleanup(curl);

    // Parse the JSON response
    try {
        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        std::vector<MarketDataPoint> dataPoints;
    
        for (const auto& [key, value] : jsonResponse["Time Series (Daily)"].items()) {
            MarketDataPoint point;
            point.time = key;
            point.open = std::stod(value["1. open"].get<std::string>());
            point.high = std::stod(value["2. high"].get<std::string>());
            point.low = std::stod(value["3. low"].get<std::string>());
            point.close = std::stod(value["4. close"].get<std::string>());
            point.volume = std::stol(value["5. volume"].get<std::string>());
            dataPoints.push_back(point);
        }
    
        return dataPoints;
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
        return std::nullopt;
    }
}