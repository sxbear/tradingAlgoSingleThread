#include "../include/config.h"
#include "../include/nlohmann/json.hpp"
#include "../include/marketDataAPI.h"
#include <iostream>
#include <fstream>

int main() {
    // Load configuration
    Config config("../JSON/config.json");
    // Verify if the file was read successfully
    if (!config.isFileRead()) {
        std::cerr << "Failed to read config file" << std::endl;
        return 1;
    }
    // Get API key from configuration
    std::string apiKey = config.getMarketDataAPIKey();
    // Create MarketDataAPI object
    MarketDataAPI marketDataAPI(apiKey, config);

    auto dataPoints = marketDataAPI.getHistoricalData();

    // Check if API call was successful
    if (!dataPoints) {
        std::cerr << "Failed to get historical data" << std::endl;
        return 1;
    }
    // Print out data points
    for (const auto& dataPoint : *dataPoints) {
        std::cout << "Time: " << dataPoint.time << '\n'
                << "Open: " << dataPoint.open << '\n'
                << "High: " << dataPoint.high << '\n'
                << "Low: " << dataPoint.low << '\n'
                << "Close: " << dataPoint.close << '\n'
                << "Volume: " << dataPoint.volume << '\n';

        if (dataPoint.adjustedClose) {
            std::cout << "Adjusted Close: " << *dataPoint.adjustedClose << '\n';
        }
        if (dataPoint.dividendAmount) {
            std::cout << "Dividend Amount: " << *dataPoint.dividendAmount << '\n';
        }
        if (dataPoint.splitCoefficient) {
            std::cout << "Split Coefficient: " << *dataPoint.splitCoefficient << '\n';
        }
        if (dataPoint.symbol) {
            std::cout << "Symbol: " << *dataPoint.symbol << '\n';
        }
        if (dataPoint.price) {
            std::cout << "Price: " << *dataPoint.price << '\n';
        }
        if (dataPoint.latestTradingDay) {
            std::cout << "Latest Trading Day: " << *dataPoint.latestTradingDay << '\n';
        }
        if (dataPoint.previousClose) {
            std::cout << "Previous Close: " << *dataPoint.previousClose << '\n';
        }
        if (dataPoint.change) {
            std::cout << "Change: " << *dataPoint.change << '\n';
        }
        if (dataPoint.changePercent) {
            std::cout << "Change Percent: " << *dataPoint.changePercent << '\n';
        }

        std::cout << std::endl;  // End each data point with a newline for readability
    }


    return 0;
}
