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

    for (const auto& p : postits) {
        std::cout << "[" << p.id << "] ";
        if (p.pinned) {
            std::cout << "[PINNED] ";
        }
        std::cout << "[" << p.color << "]\n";
        std::cout << p.title << " - " << p.message << "\n\n";
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
