#include "DataParser.h"
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>

double DataParser::parseStringToDouble(const std::string& str) {
    try {
        if (str.empty()) {
            // Return some default value or handle the empty case as needed
            return 0.0;
        }
        return std::stod(str);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return 0.0;  // or some other default value
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 0.0;  // or some other default value
    }
}


long DataParser::parseStringToLong(const std::string& str) {
    try {
        if (str.empty()) {
            // Return some default value or handle the empty case as needed
            return 0;
        }
        return std::stol(str);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return 0;  // or some other default value
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return 0;  // or some other default value
    }
}


std::map<std::string, std::vector<double>> DataParser::parseCSV(const std::string& data) {
    std::map<std::string, std::vector<double>> result;

    std::stringstream ss(data);
    std::string line;
    std::string header;
    getline(ss, header); // skipping the header line

    while (getline(ss, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::string date;
        std::vector<double> values;
        
        // getting date as the first value before comma
        getline(lineStream, date, ',');
        while (getline(lineStream, cell, ',')) {
            // converting string to double and storing in vector
            values.push_back(std::stod(cell)); // converting string to double and storing in vector
        }
        
        result[date] = values;
    }

    return result;
}

std::map<std::string, std::map<std::string, double>> DataParser::parseJSON(const std::string& data) {
    std::map<std::string, std::map<std::string, double>> result;
    
    // parse string to JSON
    nlohmann::json jsonData = nlohmann::json::parse(data);

    // parse each sub-JSON object to a map of string and double
    for(auto& [date, value] : jsonData.items()){
        for(auto& [field, num] : value.items()){
            result[date][field] = num.get<double>();
        }
    }

    return result;
}

