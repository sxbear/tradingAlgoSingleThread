#ifndef MARKETDATAAPI_H
#define MARKETDATAAPI_H

#include <string>
#include "../include/config.h"
#include "../include/nlohmann/json.hpp"
#include "../include/dataParser.h"

struct GlobalQuoteDataPoint {
    std::string symbol;
    double open;
    double high;
    double low;
    double price;
    long volume;
    std::string latestTradingDay;
    double previousClose;
    double change;
    std::string changePercent;
};

#endif
