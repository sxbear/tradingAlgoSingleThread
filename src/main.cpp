#include "../include/config.h"
#include "../include/nlohmann/json.hpp"
#include "../include/marketDataAPI.h"
#include <iostream>
#include <fstream>

int main() {
    // Load configuration
    Config config("../JSON/config.json"); // Pass in the config filename here
    // Verify if the file was read successfully
    if (!config.isFileRead()) {
        std::cerr << "Failed to read config file" << std::endl;
        return 1;
    }
    // Get API key from configuration
    std::string apiKey = config.getMarketDataAPIKey();
    // Create MarketDataAPI object
    MarketDataAPI marketDataAPI(apiKey, config);

    // Make API call
    std::string symbol = "MSFT";
    auto dataPoints = marketDataAPI.getHistoricalData(symbol, "Daily");

    // Check if API call was successful
    if (!dataPoints) {
        std::cerr << "Failed to get historical data" << std::endl;
        return 1;
    }
    // Print out data points
    for (const auto& point : *dataPoints) {
        std::cout << "Time: " << point.time << std::endl;
        std::cout << "Open: " << point.open << std::endl;
        std::cout << "High: " << point.high << std::endl;
        std::cout << "Low: " << point.low << std::endl;
        std::cout << "Close: " << point.close << std::endl;
        std::cout << "Volume: " << point.volume << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
