#ifndef INDICATORS_API_H
#define INDICATORS_API_H

#include <optional>
#include <vector>
#include "../include/config.h"

struct IndicatorInfo {
    std::string time;
    double open;
};

class IndicatorsAPI {
    std::string apiKey;
    Config config;

public:
    IndicatorsAPI(std::string const& apiKey, Config const& config);
    std::optional<std::vector<IndicatorInfo>> getIndicatorData();
    std::string selectApiUrl(const Config& config);
};

#endif
