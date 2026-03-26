#include "PostItBoard.hpp"
#include <iostream>

PostItBoard::PostItBoard() : next_id(1) {}

void PostItBoard::createPostIt() {
    PostIt p;
    p.id = next_id++;
    p.pinned = false;

    std::cout << "Enter title: ";
    std::getline(std::cin, p.title);

    std::cout << "Enter message: ";
    std::getline(std::cin, p.message);

    std::cout << "Enter color: ";
    std::getline(std::cin, p.color);

    postits.push_back(p);
}

void PostItBoard::listPostIts() const {
    std::cout << "\n===== POST-IT BOARD =====\n";
    std::vector<PostIt> pinned, unpinned;

    for (const auto& p : postits) {
        if (p.pinned) {
            pinned.push_back(p);
        } else {
            unpinned.push_back(p);
        }
    }

    for (const auto& p : pinned) {
        displayPostIt(p);
    }

    for (const auto& p : unpinned) {
        displayPostIt(p);
    }

    std::cout << "=========================\n";
}

void PostItBoard::displayLogo() {
    std::cout << "   _____ _   _      _    _ _   \n"
             "  / ____| | (_)    | |  (_) |  \n"
             " | (___ | |_ _  ___| | ___| |_ \n"
             "  \\___ \\| __| |/ __| |/ / | __|\n"
             "  ____) | |_| | (__|   <| | |_ \n"
             " |_____/ \\__|_|\\___|_|\\_\\_|\\__|\n";
}

void PostItBoard::displayPostIt(const PostIt& src) const {
    std::cout << "[" << src.id << "] ";
    if (src.pinned) {
        std::cout << "[PINNED] ";
    }

    std::cout << "[" << src.color << "]\n";
    std::cout << src.title << " - " << src.message << "\n\n";
}

void PostItBoard::displayPostIt(int id) const {
    PostIt p;
    if (const PostIt* found = searchPostIt(id)) {
            displayPostIt(*found);
        } else {
            std::cout << "Post-it with ID " << id << " not found.\n";
        }
}


const PostIt* PostItBoard::searchPostIt(int id) const {
    for (const auto& p : postits) {
        if (p.id == id) {
            return &p;
        }
    }
    return nullptr;
}

void PostItBoard::deletePostIt(int id) {
    for (int i = 0; i < postits.size(); i++) {
        if (postits[i].id == id) {
            postits.erase(postits.begin() + i);
            std::cout << "Post-it with ID " << id << " deleted.\n";
            return;
        }
    }
    std::cout << "Post-it with ID " << id << " not found.\n";
}

void PostItBoard::unpinPostIt(int id) {
    const PostIt* p = searchPostIt(id);
    if (p) {
        const_cast<PostIt*>(p)->pinned = false;
        std::cout << "Post-it with ID " << id << " unpinned.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::pinPostIt(int id) {
    const PostIt* p = searchPostIt(id);
    if (p) {
        const_cast<PostIt*>(p)->pinned = true;
        std::cout << "Post-it with ID " << id << " pinned.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}