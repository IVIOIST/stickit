#ifndef POSTITBOARD_HPP
#define POSTITBOARD_HPP

#include <vector>
#include <string>
#include "PostIt.hpp"

class PostItBoard {
private:
    std::vector<PostIt> postits;
    const PostIt* searchPostIt(int id) const;
    int next_id;

public:
    PostItBoard();

    void createPostIt();
    void listPostIts() const;
    void displayLogo();
    void displayPostIt(const PostIt& src) const;
    void displayPostIt(int id) const;
    void deletePostIt(int id);
    void pinPostIt(int id);
    void unpinPostIt(int id);
};

#endif
