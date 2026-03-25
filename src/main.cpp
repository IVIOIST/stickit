#include <iostream>
#include "PostItBoard.hpp"

int main() {
    PostItBoard board;
    int choice;
    
    board.displayLogo();

    while (true) {
        std::cout << "\n1. Create Post-it\n";
        std::cout << "2. List Post-its\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter Choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            board.createPostIt();
        } else if (choice == 2) {
            board.listPostIts();
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
