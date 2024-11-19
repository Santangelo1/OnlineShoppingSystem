#include "Logger.h"
#include <iostream>
#include <fstream>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message) {
    std::ofstream file("log.txt", std::ios::app); // Open log file in append mode
    if (file.is_open()) {
        file << message << "\n"; // Write message to file
        file.close();
    } else {
        std::cerr << "Unable to open log file.\n"; // Print error if file cannot be opened
    }
}