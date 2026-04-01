#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

class Utils {
public:
    static void printColor(const std::string& text, const std::string& color = "");
    static std::string getCurrentTime();
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static void clearScreen();
    static void pressAnyKey();
    static std::string center(const std::string& text, int width);
    static std::string getUserInput(const std::string& prompt);
    static std::string getPassword(const std::string& prompt);
};

#endif
