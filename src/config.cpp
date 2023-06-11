#include "../include/config.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/nlohmann/json.hpp"

Config::Config() : fileReadSuccessfully(false) {}  // Default constructor implementation

Config::Config(const std::string& filename) : fileReadSuccessfully(false) {
    // Open the file
    std::ifstream file(filename);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return;
    }

    try {
        // Parse the file into a JSON object
        nlohmann::json j;
        file >> j;

        // Set the API keys
        marketDataAPIKey = j["marketDataAPIKey"];
        tradingAPIKey = j["tradingAPIKey"];

        // Set the API URLs
        for (const auto& url : j["apiUrls"]) {
            apiUrls.push_back(url);
        }

        fileReadSuccessfully = true;
    }
    catch (const std::exception& e) {
        // Handle any exceptions that might occur while reading the JSON
        // For now, just print the exception
        std::cerr << "Exception while reading config file: " << e.what() << std::endl;
    }
}

std::string Config::getMarketDataAPIKey() const {
    return marketDataAPIKey;
}

std::string Config::getTradingAPIKey() const {
    return tradingAPIKey;
}

std::string Config::getApiUrl() const {
    if(!apiUrls.empty()) {
        return apiUrls.back(); // return the last element
    }
    else {
        return ""; // return an empty string if the vector is empty
    }
}

std::vector<std::string> Config::getAllApiUrls() const {
    return apiUrls;
}

bool Config::isFileRead() const {
    return fileReadSuccessfully;
}
