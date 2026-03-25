#ifndef POSTITBOARD_HPP
#define POSTITBOARD_HPP

#include <vector>
#include <string>
#include "PostIt.hpp"

class PostItBoard {
private:
    std::vector<PostIt> postits;
    int next_id;

public:
    PostItBoard();

    void createPostIt();
    void listPostIts() const;
    void displayLogo();
};

#endif
