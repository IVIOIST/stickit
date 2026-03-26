#include <iostream>
#include <limits>
#include "PostItBoard.hpp"

int readInt(const std::string& prompt);

int main() {
    PostItBoard board;

    board.displayLogo();

    while (true) {
        int choice = readInt("\n1. Create Post-it"
                             "\n2. List Post-its\n"
                             "3. Search Post It\n"
                             "4. Delete Post It\n"
                             "5. Pin Post It\n"
                             "6. Quit\nEnter Choice: ");

        switch (choice) {
            case 1:
                board.createPostIt();
                break;
            case 2:
                board.listPostIts();
                break;
            case 3: {
                int id = readInt("Enter Post-it ID to search: ");
                board.displayPostIt(id);
                break;
            }
            case 4: {
                int id = readInt("Enter Post-it ID to delete: ");
                board.deletePostIt(id);
                break;
            }
            case 5: {
                int id = readInt("Enter Post-it ID to pin: ");
                board.pinPostIt(id);
                break;
            }
            case 6: {
                std::cout << "GOODBYE";
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

}

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