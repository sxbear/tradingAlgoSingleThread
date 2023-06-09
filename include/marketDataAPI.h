#ifndef MARKETDATAAPI_H
#define MARKETDATAAPI_H

#include <string>
#include <optional>
#include "nlohmann/json.hpp"

class MarketDataAPI {
public:
    MarketDataAPI(const std::string& apiKey);

    // Method to fetch historical market data
    std::optional<std::vector<MarketDataPoint>> MarketDataAPI::getHistoricalData(const std::string& symbol, const std::string& interval);

private:
    std::string apiKey;
};

struct MarketDataPoint {
    std::string time;
    double open;
    double high;
    double low;
    double close;
    long volume;
};

#endif
