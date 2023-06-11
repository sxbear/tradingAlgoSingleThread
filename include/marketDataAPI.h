#ifndef MARKETDATAAPI_H
#define MARKETDATAAPI_H

#include <string>
#include <optional>
#include <vector>
#include "../include/config.h"
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
    MarketDataAPI(const std::string& apiKey, const Config& config);

    // Method to fetch historical market data
    std::optional<std::vector<MarketDataPoint>> getHistoricalData(const std::string& symbol, const std::string& interval);
    std::string selectApiUrl(const Config& config);

private:
    std::string apiKey;
    Config config;
};

#endif
