#ifndef MARKETDATAAPI_H
#define MARKETDATAAPI_H

#include <string>
#include <optional>
#include "../include/nlohmann/json.hpp"

struct MarketDataPoint {
    std::string time;
    double open;
    double high;
    double low;
    double close;
    long volume;
};

class MarketDataAPI {
public:
    MarketDataAPI(const std::string& apiKey);

    // Method to fetch historical market data
    std::optional<std::vector<MarketDataPoint>> getHistoricalData(const std::string& symbol, const std::string& interval);

private:
    std::string apiKey;
};

#endif
