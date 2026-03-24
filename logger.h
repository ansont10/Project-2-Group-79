// logger.h
// logger for catching errors or problems with the program
#pragma once
#include <string>
#include <fstream>

class RunLogger
{
private:
    std::ofstream openLogFile;
    bool fileIsOpen;
    std::string getCurrentTimestamp();

public:
    RunLogger(std::string logFileName = "");
    ~RunLogger();

    void write(std::string msg);
    void writeLabeled(std::string label, long long numberVal);
    void writeLabeled(std::string label, double numberVal);
    void writeLabeled(std::string label, std::string textVal);
    void writeSeparator();
    void writeBlankLine();
}; 
// logger.h
