#ifndef POSTITBOARD_HPP
#define POSTITBOARD_HPP

#include <vector>
#include <string>
#include "PostIt.hpp"

class PostItBoard {
private:
    std::string filename = "postits.txt";
    std::vector<PostIt> postits;
    const PostIt* searchPostIt(int id) const;
    PostIt* searchPostIt(int id);
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

    void setPostItColor(int id, const std::string& color);
    void setPostItTitle(int id, const std::string& title);
    void setPostItMessage(int id, const std::string& message);


    void saveToFile() const;
    void loadFromFile();
};

#endif
