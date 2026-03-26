#include <iostream>
#include <limits>
#include "PostItBoard.hpp"

int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    PostItBoard board;

    board.displayLogo();

    while (true) {
        int choice = readInt("\n1. Create Post-it"
                             "\n2. List Post-its\n"
                             "3. Search Post It\n"
                             "4. Quit\nEnter Choice: ");

        if (choice == 1) {
            board.createPostIt();
        } else if (choice == 2) {
            board.listPostIts();
        } else if (choice == 3) {
            const int id = readInt("Enter Post-it ID to search: ");
            board.displayPostIt(id);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Please enter a number from 1 to 4.\n";
        }
    }

    return 0;
}
