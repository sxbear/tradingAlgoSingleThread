#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    Config();  // Default constructor
    Config(const std::string& filename);  // Constructor with arguments

    std::string getMarketDataAPIKey() const;
    std::string getTradingAPIKey() const;

    // to check if the file was read successfully
    bool isFileRead() const;

private:
    // stored in config.json
    std::string marketDataAPIKey;
    std::string tradingAPIKey;

    // to keep track of successful file read
    bool fileReadSuccessfully;

    // Add other config parameters as needed
};

#endif
