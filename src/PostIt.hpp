#ifndef POSTIT_HPP
#define POSTIT_HPP

#include <string>

enum class Color {
    Default,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

struct PostIt {
    int id;
    std::string title;
    std::string message;
    Color color;
    bool pinned;
};

#endif
