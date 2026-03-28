#include <iostream>
#include <limits>
#include "PostItBoard.hpp"

enum class Command {
    Add,
    List,
    Delete,
    Search,
    Pin,
    Unpin,
    Unknown
};


int readInt(const std::string& prompt);
std::string readString(const std::string& prompt);
std::string getFlagArg(int argc, char* argv[], const std::string &flag);
int getFlagId(int argc, char* argv[], const std::string &flag);
bool flagExists(int argc, char* argv[], const std::string &flag);
Command parseCommand(const std::string &cmd);


void handleAdd(int argc, char*argv[], PostItBoard &postItBoard);
void handleList(int artgc, char* argv[], PostItBoard &postItBoard);
void handleDelete(int argc, char*argv[], PostItBoard &postItBoard);
void handleSearch(int argc, char*argv[], PostItBoard &postItBoard);
void handlePin(int argc, char*argv[], PostItBoard &postItBoard);
void handleUnpin(int argc, char*argv[], PostItBoard &postItBoard);

int main(int argc, char* argv[]) {
    PostItBoard board;

    std::string command = argv[1];
    Command cmd = parseCommand(command);

    switch (cmd) {
        case Command::Add:
            handleAdd(argc, argv, board);
            break;
        case Command::List:
            handleList(argc, argv, board);
            break;
        case Command::Delete:
            handleDelete(argc, argv, board);
            break;
        case Command::Search:
            std::cout << "Not implemented.\n";
            break;
        case Command::Pin:
            handlePin(argc, argv, board);
            break;
        case Command::Unpin:
            handleUnpin(argc, argv, board);
            break;
        default:
            std::cout << "not implemented.\n";
    }


    return 0;
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

std::string getFlagArg(int argc, char* argv[], const std::string &flag) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        size_t pos = arg.rfind(flag);

        if (pos != std::string::npos) {
            return arg.substr(pos + flag.length(), arg.length());
        }

    }
    return "";
    }

int getFlagId(int argc, char* argv[], const std::string &flag) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        size_t pos = arg.rfind(flag);

        if (pos != std::string::npos) {
            return std::stoi(arg.substr(pos + flag.length(), arg.length()));
        }
    }

    return -1;
}

bool flagExists(int argc, char* argv[], const std::string &flag) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        size_t pos = arg.rfind(flag);

        if (pos != std::string::npos) {
            return true;
        }
    }
    return false;
}

Command parseCommand(const std::string& cmd) {
    if (cmd == "add") {
        return Command::Add;
    }
    if (cmd == "list") {
        return Command::List;
    }
    if (cmd == "delete") {
        return Command::Delete;
    }
    if (cmd == "search") {
        return Command::Search;
    }

    if (cmd == "pin") {
        return Command::Pin;
    }

    if (cmd == "unpin") {
        return Command::Unpin;
    }

    return Command::Unknown;
}

void handleAdd(int argc, char* argv[], PostItBoard &postItBoard) {
    postItBoard.loadFromFile();
    std::string title = getFlagArg(argc, argv, "--title=");
    std::string message = getFlagArg(argc, argv, "--message=");
    std::string color = getFlagArg(argc, argv, "--color=");

    postItBoard.createPostIt(title, message, color);
    postItBoard.saveToFile();
}

void handleList(int argc, char* argv[], PostItBoard &postItBoard) {
    postItBoard.loadFromFile();
    bool pinnedOnly = flagExists(argc, argv, "--pinned");
    postItBoard.listPostIts(pinnedOnly);
}

void handleDelete(int argc, char* argv[], PostItBoard &postItBoard) {
    postItBoard.loadFromFile();
    int targetId = getFlagId(argc, argv, "--id=");

    postItBoard.deletePostIt(targetId);
    postItBoard.saveToFile();
}

void handlePin(int argc, char *argv[], PostItBoard &postItBoard) {
    postItBoard.loadFromFile();
    int targetId = getFlagId(argc, argv, "--id=");
    postItBoard.pinPostIt(targetId);
    postItBoard.saveToFile();
}

void handleUnpin(int argc, char* argv[], PostItBoard &postItBoard) {
    postItBoard.loadFromFile();
    int targetId = getFlagId(argc, argv, "--id=");
    postItBoard.unpinPostIt(targetId);
    postItBoard.saveToFile();
}
