#include "LoggerUtils.hpp"

std::thread::id LoggerUtils::getThreadID() {
    return std::this_thread::get_id();
}

std::string LoggerUtils::extractFileName(const char* file) {
    std::filesystem::path filePath(file);
    return filePath.filename().string();
}