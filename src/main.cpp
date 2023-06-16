#include "../include/config.h"
#include "../include/nlohmann/json.hpp"
#include "../include/marketDataAPI.h"
#include "../include/globalQuote.h"
#include <iostream>
#include <fstream>
#include <string>

int historicalOption(Config config) {
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

std::string menuOptions() {
    std::string option = "";
    while(option != "0" && option != "1" && option != "2" && option != "3") {
        option = "";
        std::cout << "-----------------MENU-----------------" << std::endl;
        std::cout << "1. Print Quote Endpoint" << std::endl;
        std::cout << "2. Pull & Print Historical Data On Stocks" << std::endl;
        std::cout << "3. Pull Basic Indicator Information on Stocks" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> option;
    }
    return option;
}

void followThroughOption(std::string option, Config config) {
    if(option == "1") {
        std::cout << "Coming soon..." << std::endl;
        return;
    }
    else if(option == "2") {
        historicalOption(config);
        return;
    }
    else if(option == "3") {
        std::cout << "Coming soon..." << std::endl;
        return;
    }
    else {
        return;
    }
}

int main() {
    std::string option = "";
    // Load configuration
    Config config("../JSON/config.json");
    // Verify if the file was read successfully
    if (!config.isFileRead()) {
        std::cerr << "Failed to read config file" << std::endl;
        return 1;
    }
    
    while(option != "0") {
        option = menuOptions();
        if(option != "0") {
            followThroughOption(option, config);
        }
    }

    return 0;
}
