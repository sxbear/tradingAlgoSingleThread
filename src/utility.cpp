#include "../include/utility.h"
#include <iostream>
#include <optional>
#include "curl/curl.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::vector<std::string> menuChoices(const std::vector<std::string>& apiUrls) {
    std::vector<std::string> results;
    std::regex r("function=([^&]*)");

    for (const auto& url : apiUrls) {
        std::smatch match;
        if (std::regex_search(url, match, r) && match.size() > 1) {
            results.push_back(match.str(1));
        }
    }
    return results;
}

int getUserSelection(const std::vector<std::string>& apiUrls) {
    int userSelection = -1;

    std::vector<std::string> apiFunctions = menuChoices(apiUrls);

    while (userSelection < 0 || userSelection >= apiFunctions.size()) {
        std::cout << "Please select an API (enter the number): " << std::endl;
        for (int i = 0; i < apiFunctions.size(); ++i) {
            std::cout << i+1 << ". " << apiFunctions[i] << std::endl;
        }
        std::cin >> userSelection;
        userSelection--;
        if (userSelection < 0 || userSelection >= apiFunctions.size()) {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }
    }
    return userSelection;
}

std::string selectApiUrl(const Config& config) {
    std::vector<std::string> apiUrls = config.getAllApiUrls();
    int userSelection = getUserSelection(apiUrls);
    return apiUrls[userSelection];
}

std::optional<std::string> makeApiRequest(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        return std::nullopt;
    }

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

    return response;
}