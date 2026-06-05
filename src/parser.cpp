#include <iostream>
#include <optional>
#include <sstream>
#include "command.hpp"
#include <vector>
using namespace std;

const vector<Command> COMMANDS = {
    {"cd", 1, CD},
    {"touch", 1, TOUCH},
    {"cat", 1, CAT},
    {"pwd", 0, PWD}
};

vector<string> split(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void parse_input(string input) {
    string input_command = split(input).front();
    std::optional<Command> found_command;
    
    for (Command command: COMMANDS) {
        if (command.name == input_command) {
            found_command = command;
        }
    }
    if (!found_command) {
        found_command = {input_command, 0, UNKNOWN};
    }
    
    switch (found_command.value().type) {
        case CD:
            std::cout << "found CD" << std::endl;
            break;
        case TOUCH: 
            std::cout << "found TOUCH" << std::endl;
            break;
        case CAT:
            std::cout << "found CAT" << std::endl;
            break;
        case PWD:
            std::cout << "found PWD" << std::endl;
            break;
        default:
            std::cout << "Unknown command: " << found_command.value().name << std::endl;
            break;
    }
}
