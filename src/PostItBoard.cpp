#include "PostItBoard.hpp"
#include <iostream>
#include <fstream>

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

PostIt *PostItBoard::searchPostIt(int id) {
    for (auto & p : postits) {
        if (p.id == id) {
            return &p;
        }
    }
    return nullptr;
}

void PostItBoard::deletePostIt(int id) {
    for (size_t i = 0; i < postits.size(); i++) {
        if (postits[i].id == id) {
            postits.erase(postits.begin() + i);
            std::cout << "Post-it with ID " << id << " deleted.\n";
            return;
        }
    }
    std::cout << "Post-it with ID " << id << " not found.\n";
}

void PostItBoard::unpinPostIt(int id) {
    PostIt *p = searchPostIt(id);
    if (p) {
        p->pinned = false;
        std::cout << "Post-it with ID " << id << " unpinned.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::pinPostIt(int id) {
    PostIt* p = searchPostIt(id);
    if (p) {
        p->pinned = true;
        std::cout << "Post-it with ID " << id << " pinned.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::setPostItColor(int id, const std::string& color) {
    PostIt* p = searchPostIt(id);
    if (p) {
        p->color = color;
        std::cout << "Post-it with ID " << id << " color updated.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::setPostItTitle(int id, const std::string& title) {
    PostIt* p = searchPostIt(id);
    if (p) {
        p->title = title;
        std::cout << "Post-it with ID " << id << " title updated.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::setPostItMessage(int id, const std::string& message) {
    PostIt* p = searchPostIt(id);
    if (p) {
        p->message = message;
        std::cout << "Post-it with ID " << id << " message updated.\n";
    } else {
        std::cout << "Post-it with ID " << id << " not found.\n";
    }
}

void PostItBoard::saveToFile() const {
    std::fstream out(filename.c_str(), std::ios::out);
    if (!out) {
        std::cerr << "Error opening file for writing: " << filename << "\n";
        return;
    }

    for (const auto& p : postits) {
        out << p.id << "|" << p.title << "|" << p.message << "|" << p.color << "|" << p.pinned << "\n";
    }
}

void PostItBoard::loadFromFile() {
   std::fstream in(filename, std::ios::in);
    if (!in) {
        std::cerr << "Error opening file for reading: " << filename << "\n";
        return;
    }

    postits.clear();
    std::string line;

    while (std::getline(in, line)) {
        PostIt p;
        size_t pos = 0;
        std::string token;

        // ID
        pos = line.find('|');
        p.id = std::stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Title
        pos = line.find('|');
        p.title = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Message
        pos = line.find('|');
        p.message = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Color
        pos = line.find('|');
        p.color = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Pinned
        p.pinned = (line == "1");

        postits.push_back(p);
    }
}