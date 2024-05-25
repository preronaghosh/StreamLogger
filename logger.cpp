#include <iostream>

enum class LogLevel { INFO, DEBUG, ERROR, WARNING, CRITICAL };

class Logger {
public:
    Logger(LogLevel level, const char* file = "", int line = 0) : logLevel(level) {
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
        }
    }

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
};

#define LOGINFO() Logger(LogLevel::INFO, __FILE__, __LINE__)
#define LOGDEBUG() Logger(LogLevel::DEBUG, __FILE__, __LINE__)
#define LOGERROR() Logger(LogLevel::ERROR, __FILE__, __LINE__)
#define LOGWARNING() Logger(LogLevel::WARNING, __FILE__, __LINE__)
#define LOGCRITICAL() Logger(LogLevel::CRITICAL, __FILE__, __LINE__)

int main() {
    LOGINFO() << "Hello information" << std::endl;
    LOGDEBUG() << "Debugging message" << std::endl;
    LOGERROR() << "An error occurred" << std::endl;
    LOGWARNING() << "This is a warning" << std::endl;
    LOGCRITICAL() << "This is a critical error" << std::endl;

    return 0;
}
