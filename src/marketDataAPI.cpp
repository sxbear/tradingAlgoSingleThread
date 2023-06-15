#include <optional>
#include <iostream>
#include <vector>
#include <regex>
#include "../include/nlohmann/json.hpp"
#include "../include/marketDataAPI.h"
#include "../include/dataParser.h"
#include "curl/curl.h"

MarketDataAPI::MarketDataAPI(std::string const& apiKey, Config const& config) : apiKey(apiKey), config(config){}

//helper function to handle the data returned by libcurl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

//helper function regex for user menu options
std::vector<std::string> menuChoices(const std::vector<std::string>& apiUrls) {
    std::vector<std::string> results;
    std::regex r("function=([^&]*)");

    for (const auto& url : apiUrls) {
        std::smatch match;
        if (std::regex_search(url, match, r) && match.size() > 1) {
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            results.push_back(match.str(1));
        }
    }
    return results;
}

//helper function for user api choice
int getUserSelection(const std::vector<std::string>& apiUrls) {
    int userSelection = -1;

    // Get the function parts of the URLs
    std::vector<std::string> apiFunctions = menuChoices(apiUrls);

    while (userSelection < 0 || userSelection >= apiFunctions.size()) {
        std::cout << "Please select an API (enter the number): " << std::endl;
        for (int i = 0; i < apiFunctions.size(); ++i) {
            // Display the function part of the URL instead of "API i+1"
            std::cout << i+1 << ". " << apiFunctions[i] << std::endl;
        }
        std::cin >> userSelection;
        // Adjust for 0-based indexing
        userSelection--;
        if (userSelection < 0 || userSelection >= apiFunctions.size()) {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }
    }
    return userSelection;
}


//helper function for selecting api url
std::string MarketDataAPI::selectApiUrl(const Config& config) {
    // Get the URLs from the config
    std::vector<std::string> apiUrls = config.getAllApiUrls();
    int userSelection = getUserSelection(apiUrls);
    return apiUrls[userSelection];
}

//helper to complete api url
std::string promptForApiDetails(const std::vector<std::string>& apiUrls, const Config& config) {
    int selection = getUserSelection(apiUrls);
    std::string selectedApi = menuChoices(apiUrls)[selection];

    std::string formattedUrl = apiUrls[selection];
    std::string apiKey = config.getMarketDataAPIKey();

    if (selectedApi.find("INTRADAY_EXTENDED") != std::string::npos) {
        std::string symbol;
        std::string interval;
        std::string slice;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        std::cout << "Please enter the time interval for " << selectedApi << " (e.g., 1min, 5min, 15min, 30min, 60min): ";
        std::cin >> interval;
        std::cout << "Please enter a time slice for " << selectedApi << " (e.g., year1month1, year2month7 (30 day window, recent is 1,1)): ";
        std::cin >> slice;
        formattedUrl += "&symbol=" + symbol + "&interval=" + interval + "&slice=" + slice;
    }
    else if (selectedApi.find("INTRADAY") != std::string::npos) {
        std::string symbol;
        std::string interval;
        std::string len;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        std::cout << "Please enter the time interval for " << selectedApi << " (e.g., 1min, 5min, 15min, 30min, 60min): ";
        std::cin >> interval;
        std::cout << "Please enter 'full' or 'compact' for response length for " << selectedApi << " (e.g., full for full-length, compact for 100 data points): ";
        std::cin >> len;
        formattedUrl += "&symbol=" + symbol + "&interval=" + interval + "&outputsize=" + len;
    }
    else if (selectedApi.find("DAILY_ADJUSTED") != std::string::npos) {
        std::string symbol;
        std::string len;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        std::cout << "Please enter 'full' or 'compact' for response length for " << selectedApi << " (e.g., full for full-length, compact for 100 data points): ";
        std::cin >> len;
        formattedUrl += "&symbol=" + symbol + "&outputsize=" + len;
    }
    else if (selectedApi.find("DAILY") != std::string::npos) {
        std::string symbol;
        std::string len;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        std::cout << "Please enter 'full' or 'compact' for response length for " << selectedApi << " (e.g., full for full-length, compact for 100 data points): ";
        std::cin >> len;
        formattedUrl += "&symbol=" + symbol + "&outputsize=" + len;
    }
    else if (selectedApi.find("WEEKLY_ADJUSTED") != std::string::npos) {
        std::string symbol;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
    }
    else if (selectedApi.find("WEEKLY") != std::string::npos) {
        std::string symbol;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
    }
    else if (selectedApi.find("MONTHLY_ADJUSTED") != std::string::npos) {
        std::string symbol;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
    }
    else if (selectedApi.find("MONTHLY") != std::string::npos) {
        std::string symbol;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
    }
    else if (selectedApi.find("GLOBAL_QUOTE") != std::string::npos) {
        std::string symbol;
        std::cout << "Please enter a symbol for " << selectedApi << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
    }

    // You can continue adding more conditions here to handle different APIs
    formattedUrl += "&apikey=" + apiKey;
    return formattedUrl;
}

std::vector<MarketDataPoint> parseIntradayResponse(const std::string& response) {
    // Try to parse the response as JSON
    std::cout << "parsing JSON intra" << std::endl;
    std::vector<MarketDataPoint> dataPoints;
    return dataPoints;
}

std::vector<MarketDataPoint> parseDailyResponse(const std::string& response) {
    // Try to parse the response as JSON
    std::cout << "parsing JSON daily" << std::endl;
    std::vector<MarketDataPoint> dataPoints;
    return dataPoints;
}

std::vector<MarketDataPoint> parseWeeklyResponse(const std::string& response) {
    // Try to parse the response as JSON
    std::cout << "parsing JSON weekly" << std::endl;
    std::vector<MarketDataPoint> dataPoints;
    return dataPoints;
}

std::vector<MarketDataPoint> parseMonthlyResponse(const std::string& response) {
    // Try to parse the response as JSON
    std::cout << "parsing JSON monthly" << std::endl;
    std::vector<MarketDataPoint> dataPoints;
    return dataPoints;
}

std::vector<MarketDataPoint> parseGqResponse(const std::string& response) {
    // Try to parse the response as JSON
    std::cout << "parsing JSON gq" << std::endl;
    std::vector<MarketDataPoint> dataPoints;
    return dataPoints;
}

std::vector<MarketDataPoint> parseResponseBasedOnURL(const std::string& url, const std::string& response) {
    std::cout << "parsing on url..." + url << std::endl;
    if (url.find("INTRADAY") != std::string::npos) {
        return parseIntradayResponse(response);
    } 
    else if (url.find("DAILY") != std::string::npos) {
        return parseDailyResponse(response);
    } 
    else if (url.find("WEEKLY") != std::string::npos) {
        return parseWeeklyResponse(response);
    } 
    else if (url.find("MONTHLY") != std::string::npos) {
        return parseMonthlyResponse(response);
    }
    else if (url.find("GLOBAL_QUOTE") != std::string::npos) {
        return parseGqResponse(response);
    }
    else { 
        std::vector<MarketDataPoint> dataPoints;
        return dataPoints;
    }
}

//retrieves historical data
std::optional<std::vector<MarketDataPoint>> MarketDataAPI::getHistoricalData() {
    // Initialize libcurl
    CURL* curl = curl_easy_init();
    DataParser dp;
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return std::nullopt;
    }

    // Create the URL for the API request
    std::string url = promptForApiDetails(config.getAllApiUrls(), config);

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

    if (response.find("premium") != std::string::npos) {
        std::cout << "This is a premium endpoint.  An upgraded API key will need to be used." << std::endl;
        return std::nullopt;
    }
    // Clean up curl
    curl_easy_cleanup(curl);
    // Try to parse the response as JSON
    try {
        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        std::vector<MarketDataPoint> dataPoints;
        //std::cout << "Formatted JSON response: " << jsonResponse.dump(4) << std::endl;

        for (auto& element : jsonResponse.items()) {
            std::string key = element.key();
            
            // Global Quote handling
            if (key == "Global Quote") {
                auto globalQuote = element.value();
                
                MarketDataPoint point;
                point.symbol = globalQuote.at("01. symbol").get<std::string>();
                point.open = std::stod(globalQuote.at("02. open").get<std::string>());
                point.high = std::stod(globalQuote.at("03. high").get<std::string>());
                point.low = std::stod(globalQuote.at("04. low").get<std::string>());
                point.price = std::stod(globalQuote.at("05. price").get<std::string>());
                point.volume = std::stod(globalQuote.at("06. volume").get<std::string>());
                point.latestTradingDay = globalQuote.at("07. latest trading day").get<std::string>();
                point.previousClose = std::stod(globalQuote.at("08. previous close").get<std::string>());
                point.change = std::stod(globalQuote.at("09. change").get<std::string>());
                point.changePercent = globalQuote.at("10. change percent").get<std::string>();

                dataPoints.push_back(point);
            } 
            // Time Series handling
            else if (key.find("Time Series") != std::string::npos && element.value().is_object()) {
                auto timeSeries = element.value();

                for (const auto& pair : timeSeries.items()) {
                    const auto& date = pair.key();
                    const auto& value = pair.value();

                    MarketDataPoint point;
                    point.time = date;
                    point.open = std::stod(value.at("1. open").get<std::string>());
                    point.high = std::stod(value.at("2. high").get<std::string>());
                    point.low = std::stod(value.at("3. low").get<std::string>());
                    point.close = std::stod(value.at("4. close").get<std::string>());

                    if (value.contains("5. volume")) {
                        point.volume = std::stod(value.at("5. volume").get<std::string>());
                    }
                    if (value.contains("5. adjusted close")) {
                        point.adjustedClose = std::stod(value.at("5. adjusted close").get<std::string>());
                    }
                    if (value.contains("6. volume")) {
                        point.volume = std::stod(value.at("6. volume").get<std::string>());
                    }
                    if (value.contains("7. dividend amount")) {
                        point.dividendAmount = std::stod(value.at("7. dividend amount").get<std::string>());
                    }
                    if (value.contains("8. split coefficient")) {
                        point.splitCoefficient = std::stod(value.at("8. split coefficient").get<std::string>());
                    }

                    dataPoints.push_back(point);
                }
            }
        }     
        return dataPoints;
    }
    // If JSON parsing fails, try CSV parsing
    catch (nlohmann::json::parse_error& e) {
        try {
            auto csvResponse = dp.parseCSV(response);
            std::vector<MarketDataPoint> dataPoints;

            for (const auto& [date, values] : csvResponse) {
                if (values.size() < 5) {
                    std::cerr << "Invalid CSV data: insufficient values for date " << date << std::endl;
                    continue;
                }
                MarketDataPoint point;
                point.time = date;
                point.open = values[0];
                point.high = values[1];
                point.low = values[2];
                point.close = values[3];
                point.volume = values[4];
                dataPoints.push_back(point);
            }

            return dataPoints;
        }
        catch (std::exception& e) {
            std::cerr << "Failed to parse the response: " << e.what() << std::endl;
            return std::nullopt;
        }
    }
}

