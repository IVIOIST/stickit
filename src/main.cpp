#include <iostream>
#include <limits>
#include "PostItBoard.hpp"

int readInt(const std::string& prompt);
std::string readString(const std::string& prompt);

int main() {
    PostItBoard board;

    board.displayLogo();

    while (true) {
        int choice = readInt("\n1. Create Post-it"
                             "\n2. Edit Post-it"
                             "\n3. List Post-its\n"
                             "4. Search Post It\n"
                             "5. Delete Post It\n"
                             "6. Pin Post It\n"
                             "7. Quit\nEnter Choice: ");

        switch (choice) {
            case 1:
                board.createPostIt();
                break;
            case 2: {
                int editChoice = readInt("1. Edit Title\n2. Edit Message\n3. Edit Color\nEnter Choice: ");
                int id = readInt("Enter Post-it ID to edit: ");
                if (editChoice == 1) {
                    std::string newTitle = readString("Enter new title: ");
                    board.setPostItTitle(id, newTitle);
                } else if (editChoice == 2) {
                    std::string newMessage = readString("Enter new message: ");
                    board.setPostItMessage(id, newMessage);
                } else if (editChoice == 3) {
                    std::string newColor = readString("Enter new color: ");
                    board.setPostItColor(id, newColor);
                } else {
                    std::cout << "Invalid edit choice.\n";
                }
                break;
            }
            case 3: {
                board.listPostIts();
                break;
            }
            case 4: {
                int id = readInt("Enter Post-it ID to search: ");
                board.displayPostIt(id);
                break;
            }
            case 5: {
                int id = readInt("Enter Post-it ID to delete: ");
                board.deletePostIt(id);
                break;
            }
            case 6: {
                int id = readInt("Enter Post-it ID to pin: ");
                board.pinPostIt(id);
                break;
            }
            case 7: {
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

std::string readString(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}