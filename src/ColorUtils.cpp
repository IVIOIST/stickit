#include "ColorUtils.hpp"
#include <algorithm>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

std::string colorToAnsi(Color color) {
    switch (color) {
        case Color::Red: return "\033[31m";
        case Color::Green: return "\033[32m";
        case Color::Yellow: return "\033[33m";
        case Color::Blue: return "\033[34m";
        case Color::Magenta: return "\033[35m";
        case Color::Cyan: return "\033[36m";
        case Color::White: return "\033[37m";
        default: return "\033[0m";
    }
}

Color stringToColor(const std::string& color) {
    const std::string s = toLower(color);

    if (s == "red") {
        return Color::Red;
    }
    if (s == "green") {
        return Color::Green;
    }
    if (s == "yellow") {
        return Color::Yellow;
    }
    if (s == "blue") {
        return Color::Blue;
    }
    if (s == "magenta") {
        return Color::Magenta;
    }
    if (s == "cyan") {
        return Color::Cyan;
    }
    if (s == "white") {
        return Color::White;
    }
    return Color::Default;
}

std::string colorToString(Color color) {
    switch (color) {
        case Color::Red: return "red";
        case Color::Green: return "green";
        case Color::Yellow: return "yellow";
        case Color::Blue: return "blue";
        case Color::Magenta: return "magenta";
        case Color::Cyan: return "cyan";
        case Color::White: return "white";
        default : return "default";
    }
}