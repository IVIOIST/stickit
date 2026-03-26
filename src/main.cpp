#include <iostream>
#include <limits>
#include "PostItBoard.hpp"

int main() {
    PostItBoard board;
    int choice;
    
    board.displayLogo();

    while (true) {
        std::cout << "\n1. Create Post-it\n";
        std::cout << "2. List Post-its\n";
        std::cout << "3. Search Post It\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter Choice: ";
        
        if (std::cin >> choice) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (choice == 1) {
            board.createPostIt();
        } else if (choice == 2) {
            board.listPostIts();
        } else if (choice == 3) {
            board.searchPostIt();
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
