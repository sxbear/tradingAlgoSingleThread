#include <string>
#include <vector>
#include <regex>
#include "../include/config.h"

// Forward declaration of the MarketDataAPI class
class MarketDataAPI;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

std::vector<std::string> menuChoices(const std::vector<std::string>& apiUrls);

int getUserSelection(const std::vector<std::string>& apiUrls);

std::string selectApiUrl(const Config& config);
