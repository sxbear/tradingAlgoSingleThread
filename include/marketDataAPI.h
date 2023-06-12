#ifndef MARKETDATAAPI_H
#define MARKETDATAAPI_H

#include <string>
#include <optional>
#include <vector>
#include "../include/config.h"
#include "../include/nlohmann/json.hpp"
#include "../include/dataParser.h"

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
    MarketDataAPI(std::string const& apiKey, const Config& config);

    // Method to fetch historical market data
    std::optional<std::vector<MarketDataPoint>> getHistoricalData();
    std::string selectApiUrl(const Config& config);

private:
    std::string apiKey;
    Config config;
};

#endif
