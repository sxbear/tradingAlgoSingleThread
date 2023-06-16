#include "../include/indicators.h"
#include "../include/utility.h"
#include "../include/dataParser.h"
#include <iostream>
#include <regex>
#include "../include/nlohmann/json.hpp"
#include "curl/curl.h"

IndicatorsAPI::IndicatorsAPI(std::string const& apiKey, Config const& config) : apiKey(apiKey), config(config) {}

//helper to complete api url
std::string promptForIndicatorInfo(const std::vector<std::string>& apiUrls, const Config& config) {
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

    // You can continue adding more conditions here to handle different APIs
    formattedUrl += "&apikey=" + apiKey;
    return formattedUrl;
}

//retrieves indicator data
