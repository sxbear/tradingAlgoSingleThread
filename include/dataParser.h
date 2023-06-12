#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <string>
#include <map>
#include <vector>

class DataParser {
public:
    double parseStringToDouble(const std::string& str);
    long parseStringToLong(const std::string& str);
    std::map<std::string, std::vector<double>> parseCSV(const std::string& data);
    std::map<std::string, std::map<std::string, double>> parseJSON(const std::string& data);
};

#endif
