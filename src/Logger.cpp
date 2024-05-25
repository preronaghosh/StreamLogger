#include "Logger.hpp"
#include "LoggerUtils.hpp"

#include <iomanip>
#include <thread>
#include <string>

Logger::Logger(LogLevel level, const char* file = "", int line = 0) : logLevel{level} {
    // Extract only file name out of the full path and add current thread details
    LoggerUtils utils;
    std::cout << "threadID: " << utils.getThreadID() << " " << ": " << utils.extractFileName(file) << " " << line << ": ";
    switch (logLevel) {
        case LogLevel::INFO:
            setColor(static_cast<int>(LogLevelColor::GREEN)); 
            std::cout << "[info] ";
            break;
        case LogLevel::DEBUG:
            setColor(static_cast<int>(LogLevelColor::BLUE)); 
            std::cout << "[debug] ";
            break;
        case LogLevel::ERROR:
            setColor(static_cast<int>(LogLevelColor::RED)); 
            std::cerr << "[error] ";
            break;
        case LogLevel::WARNING:
            setColor(static_cast<int>(LogLevelColor::YELLOW));  
            std::cerr << "[warning] ";
            break;
        case LogLevel::CRITICAL:
            setColor(static_cast<int>(LogLevelColor::RED)); 
            std::cerr << "[critical] ";
            break;
    }
    resetColor();
}

void Logger::setColor(int code) {
    // ANSI escape code for setting text color
    std::cout << "\033[" << code << "m";
}

void Logger::resetColor() {
    // ANSI escape code for resetting text color to default
    std::cout << "\033[0m"; 
}
