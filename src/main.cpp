#include "Logger.hpp"

int main() {
    LOGINFO() << "Hello information" << std::endl;
    LOGDEBUG() << "Debugging message" << std::endl;
    LOGERROR() << "An error occurred" << std::endl;
    LOGWARNING() << "This is a warning" << std::endl;
    LOGCRITICAL() << "This is a critical error" << std::endl;

    return 0;
}