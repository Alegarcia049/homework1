#pragma once

#include <iostream>
#include <string>
using namespace std;

enum class Severity {DEBUG = 0, INFO, WARNING, ERROR, CRITICAL, RUNTIME_ERROR};

void logMessage(const char* message, Severity severity);
void logMessage(const char* message, const char* file, int line);
void logMessage(const char* message, const char* user);
void file_logger(string &log);