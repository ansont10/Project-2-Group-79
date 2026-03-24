// logger.cpp
// prints messages with timestamp to screen and to the log file

#include "logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

RunLogger::RunLogger(std::string logFileName)
    : fileIsOpen(false)
{
    if (!logFileName.empty())
    {
        openLogFile.open(logFileName, std::ios::out | std::ios::app);
        if (openLogFile.is_open())
            fileIsOpen = true;
    }
}

RunLogger::~RunLogger()
{
    if (fileIsOpen)
        openLogFile.close();
}

std::string RunLogger::getCurrentTimestamp()
{
    auto nowPoint = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(nowPoint);
    std::ostringstream buf;
    std::tm tmBuf{};
    localtime_s(&tmBuf, &nowTime);
    buf << std::put_time(&tmBuf, "%H:%M:%S");
    return buf.str();
}

void RunLogger::write(std::string msg)
{
    std::string fullLine = "[" + getCurrentTimestamp() + "] " + msg;
    std::cout << fullLine << std::endl;
    if (fileIsOpen)
        openLogFile << fullLine << "\n";
}

void RunLogger::writeLabeled(std::string label, long long numberVal)
{
    write(label + ": " + std::to_string(numberVal));
}

void RunLogger::writeLabeled(std::string label, double numberVal)
{
    std::ostringstream buf;
    buf << std::fixed << std::setprecision(4) << numberVal;
    write(label + ": " + buf.str());
}

void RunLogger::writeLabeled(std::string label, std::string textVal)
{
    write(label + ": " + textVal);
}

void RunLogger::writeSeparator()
{
    std::string line = "------------------------------------------";
    std::cout << line << std::endl;
    if (fileIsOpen)
        openLogFile << line << "\n";
}

void RunLogger::writeBlankLine()
{
    std::cout << " " << std::endl;
    if (fileIsOpen)
        openLogFile << "\n";
} 
// logger.cpp
