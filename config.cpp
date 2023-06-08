#include "Config.h"
#include <fstream>
#include <iostream>
#include <packages/json.hpp>

Config::Config(const std::string& filename) : fileReadSuccessfully(false) {
    // Open the file
    std::ifstream file(filename);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        return;
    }

    try {
        // Parse the file into a JSON object
        nlohmann::json j;
        file >> j;

        // Set the API keys
        marketDataAPIKey = j["marketDataAPIKey"];
        tradingAPIKey = j["tradingAPIKey"];

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

bool Config::isFileRead() const {
    return fileReadSuccessfully;
}
