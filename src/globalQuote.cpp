#include "../include/globalQuote.h"
#include <iostream>

GlobalQuoteDataPoint handleGlobalQuote(nlohmann::json& globalQuote) {
    GlobalQuoteDataPoint point;
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
    return point;
}

std::string formGqURL(){
        std::string formattedUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE";
        std::string symbol;
        std::cout << "Please enter a symbol" << " (e.g., MSFT, AAPL, AMZN, NVDA, TSLA): ";
        std::cin >> symbol;
        formattedUrl += "&symbol=" + symbol;
        return formattedUrl;
}