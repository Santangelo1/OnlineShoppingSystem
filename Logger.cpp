#include "Logger.h"
#include <iostream>
#include <fstream>

//Define the static instance variable
Logger& Logger::getInstance() {
    static Logger instance;  //Static instance of the logger
    return instance;
}

//Constructor
Logger::Logger() {
file.open("log.txt", std::ios::app); //Open log file in append mode
if (!file.is_open()) {
    std::cerr << "Unable to open log file.\n";
//Print error if file cannot be opened.
}
}

//Destructor
Logger::~Logger() {
    if (!file.is_open()) {
        file.close(); //Close the log file if it was opened
    }
}

//Log a message to the file
void Logger::log(const std::string& message) {
    if (file.is_open()) {
        file << message <<  "\n";  //Write message to file
    } else {
        std::cerr << "Log file is not open. Unable to log message.\n";
        //Handle logging failure
    }
}

//Prevent copying
Logger::Logger(const Logger&) = delete;
Logger& Logger::operator=(const Logger&) = delete;





