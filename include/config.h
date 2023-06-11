#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

class Config {
public:
    // Default constructor
    Config();
    // Constructor with arguments
    Config(const std::string& filename);

    std::string getMarketDataAPIKey() const;
    std::string getTradingAPIKey() const;
    std::string getApiUrl() const;
    std::vector<std::string> getAllApiUrls() const;

    // to check if the file was read successfully
    bool isFileRead() const;

private:
    // stored in config.json
    std::string marketDataAPIKey;
    std::string tradingAPIKey;
    std::vector<std::string> apiUrls;

    // to keep track of successful file read
    bool fileReadSuccessfully;

    // Add other config parameters as needed
};

#endif
