#ifndef POSTIT_HPP
#define POSTIT_HPP

#include <string>

struct PostIt {
    int id;
    std::string title;
    std::string message;
    std::string color;
    bool pinned;
};

#endif
