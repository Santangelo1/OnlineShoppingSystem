#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::ofstream file("log.txt", std::ios::app);
        if (file.is_open()) {
            file << message << "\n";
            file.close();
        } else {
            std::cerr << "Unable to open log file.\n";
        }
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H