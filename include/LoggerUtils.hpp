#ifndef LOGGER_UTILS_HPP
#define LOGGER_UTILS_HPP

#include <thread>
#include <string>
#include <filesystem>

class LoggerUtils {
public:
    std::thread::id getThreadID();
    std::string extractFileName(const char* file);
};

#endif /* LOGGER_UTILS_HPP */