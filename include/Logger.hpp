#ifndef LOG_LEVELS_HPP
#define LOG_LEVELS_HPP

#include <iostream>

enum class LogLevel { 
    INFO, 
    DEBUG, 
    ERROR, 
    WARNING, 
    CRITICAL 
};

enum class LogLevelColor {
    RED = 31,
    GREEN,
    YELLOW, 
    BLUE,
};

class Logger {
public:
    Logger(LogLevel level, const char* file, int line);

    template <typename T>
    Logger& operator<<(const T& msg) {
        std::cout << msg;
        return *this;
    }

    // Overload for endl
    Logger& operator<<(std::ostream& (*manipulator)(std::ostream&)) {
        manipulator(std::cout);
        return *this;
    }

private:
    LogLevel logLevel;

    void setColor(int code);
    void resetColor();
};

#define LOGINFO() Logger(LogLevel::INFO, __FILE__, __LINE__)
#define LOGDEBUG() Logger(LogLevel::DEBUG, __FILE__, __LINE__)
#define LOGERROR() Logger(LogLevel::ERROR, __FILE__, __LINE__)
#define LOGWARNING() Logger(LogLevel::WARNING, __FILE__, __LINE__)
#define LOGCRITICAL() Logger(LogLevel::CRITICAL, __FILE__, __LINE__)

#endif /* LOG_LEVELS_HPP */