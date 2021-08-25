//======== EngineLogger.cpp ========
//Purpose: Implementation of EngineLogger.h
//==================================

#include <cryst/logging/EngineLogger.h>
#include <ctime>
#include <sstream>

EngineLogger::EngineLogger(bool useFile) {
    this->useFile = useFile;

    if (useFile) {
        std::time_t t = std::time(0);

        tm* ltm = localtime(&t);

        int day = ltm->tm_mday;
        int month = ltm->tm_mon + 1;
        int year = ltm->tm_year + 1900;

        std::stringstream ss;
        ss << month; ss << "-"; ss << day; ss << "-"; ss << year; ss << "-engineLog.log";

        this->m_path = ss.str();
        this->m_loggingFile = std::ofstream(ss.str(), std::ios::app);
    } else {
        std::cout << "Crystallized Currently only supports logging with files and console or just files\n";
    }

}

EngineLogger::EngineLogger() {
    this->useFile = true;

    std::time_t t = std::time(0);

    tm* ltm = localtime(&t);

    int day = ltm->tm_mday;
    int month = ltm->tm_mon + 1;
    int year = ltm->tm_year + 1900;



    std::stringstream ss;
    ss << month; ss << "-"; ss << day; ss << "-"; ss << year; ss << "-engineLog.log";

    this->m_path = ss.str();
    this->m_loggingFile = std::ofstream(ss.str(), std::ios::app);
    this->m_loggingFile << "==================================================" << "\n" << "Crystallized Log" << "\n";
    this->m_loggingFile.close();
}

void EngineLogger::log(LogLevel level, std::string message) {
    std::string output = "[" + logLevelToString(level) + "]: " + message;

    std::cout << output + "\n";

    if (this->m_loggingFile.is_open()) {
        m_loggingFile << output << "\n";
        this->m_loggingFile.close();
    } else {
        this->m_loggingFile.open(this->m_path, std::ios::app);
        this->m_loggingFile << output << "\n";
        this->m_loggingFile.close();
    }
}

void EngineLogger::logFileOnly(LogLevel level, std::string message) {
    std::string output = "[" + logLevelToString(level) + "]: " + message;

    if (this->m_loggingFile.is_open()) {
        m_loggingFile << output << "\n";
        this->m_loggingFile.close();
    } else {
        this->m_loggingFile.open(this->m_path, std::ios::app);
        this->m_loggingFile << output << "\n";
        this->m_loggingFile.close();
    }
}

void EngineLogger::info(std::string message) {
    log(LogLevel::INFO, message);
}

void EngineLogger::warn(std::string message) {
    log(LogLevel::WARN, message);
}

void EngineLogger::config(std::string message) {
    log(LogLevel::CONFIG, message);
}

void EngineLogger::err(std::string message) {
    log(LogLevel::ERROR, message);
}
