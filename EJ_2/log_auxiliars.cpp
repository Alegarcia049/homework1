#include <iostream>
#include <string>
#include <fstream>
#include "log_auxiliars.hpp"
#define LOG_FILE "log.txt"

void file_logger(string &log) {
    ofstream logFile(LOG_FILE, ios::app);
    if (logFile.is_open()) {
        logFile << log << endl;
        logFile.close();
    }
    else cerr << "Error abriendo el archivo de log\n";
}

void logMessage(const char* message, Severity severity){
    string message_to_log;
    switch (severity) {
        case Severity::DEBUG: message_to_log = "[DEBUG]"; break;
        case Severity::INFO: message_to_log = "[INFO]"; break;
        case Severity::WARNING: message_to_log = "[WARNING]"; break;
        case Severity::ERROR: message_to_log = "[ERROR]"; break;
        case Severity::CRITICAL: message_to_log = "[CRITICAL]"; break;
        case Severity::RUNTIME_ERROR: message_to_log = "[RUNTIME_ERROR]"; break;
    }
    message_to_log += "<" + string(message) + ">";
    file_logger(message_to_log);
}

void logMessage(const char* message, const char* file, int line){
    string message_to_log = "<" + string(message) + ">" + "FILE_NAME: " + string(file) + " (LINE: " + to_string(line) + ")";
    file_logger(message_to_log);
}

void logMessage(const char* message, const char* user){
    string message_to_log = "[SECURITY]<" + string(user) + ">" + "(" + string(message) + ")";
    file_logger(message_to_log);
}