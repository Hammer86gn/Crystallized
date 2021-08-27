//======== EngineLogger.h ========
//Purpose: A class made to log Engine activity in console and file
//================================

#pragma once

#include <fstream>
#include <string>
#include <iostream>

enum LogLevel {
    INFO = 0,
    WARN,
    CONFIG,
    ERROR
};

class EngineLogger {

public:
    explicit EngineLogger(std::string prefix);

    void log(LogLevel level, std::string message);

    void logFileOnly(LogLevel level, std::string message);

    void info(std::string message);

    void warn(std::string message);

    void config(std::string message);

    void err(std::string message);
private:
    std::string m_prefix;
    std::ofstream m_loggingFile;
    std::string m_path;

    bool useFile;

    static std::string logLevelToString(int level) {
        switch(level) {
            case 0:
                return "INFO";
            case 1:
                return "WARN";
            case 2:
                return "CONFIG";
            case 3:
                return "ERROR";
            default:
                return "INFO"; //This is a fallback even though it realistically is impossible
        }
    }

};

