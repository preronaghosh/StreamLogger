#include "../include/Logger.hpp"

Logger::Logger(LogLevel level, const char* file = "", int line = 0) : logLevel{level} {
    std::cout << file << ": " << line << ": ";
    switch (logLevel) {
        case LogLevel::INFO:
            std::cout << "[info] ";
            break;
        case LogLevel::DEBUG:
            std::cout << "[debug] ";
            break;
        case LogLevel::ERROR:
            std::cerr << "[error] ";
            break;
        case LogLevel::WARNING:
            std::cerr << "[warning] ";
            break;
        case LogLevel::CRITICAL:
            std::cerr << "[critical] ";
            break;
    }
}
