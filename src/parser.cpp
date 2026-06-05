#include <iostream>
#include <optional>
#include <sstream>
#include "command.hpp"
#include <vector>
using namespace std;

const vector<Command> COMMANDS = {
    {"cd", 1, CD},
    {"touch", 255, TOUCH},
    {"cat", 255, CAT},
    {"pwd", 0, PWD},
    {"exit", 0, EXIT}
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

bool parse_input(string input) {
    vector<string> flags;
    vector<string> args;
    optional<Command> found_command;

    vector<string> split_input = split(input);
    string input_command = split_input.front();
    split_input.erase(split_input.begin());

    for (string input_parts: split_input) {
        if (input_parts.rfind("-", 0) == 0 ) {
            flags.push_back(input_parts);
        }
        else {
            args.push_back(input_parts);
        }
    }

    for (Command command: COMMANDS) {
        if (command.name == input_command) {
            found_command = command;
        }
    }
    if (!found_command) {
        found_command = {input_command, 0, UNKNOWN};
    }
    
    if (args.size() > found_command.value().nb_args && found_command.value().type != UNKNOWN) {
        std::cout << "Too many args for " << found_command.value().name << " command" << std::endl;
        return false;
    }

    switch (found_command.value().type) {
        case CD:
            std::cout << "found CD" << std::endl;
            return false;
        case TOUCH: 
            std::cout << "found TOUCH" << std::endl;
            return false;
        case CAT:
            std::cout << "found CAT" << std::endl;
            return false;
        case PWD:
            std::cout << "found PWD" << std::endl;
            return false;
        case EXIT:
            return true;
        default:
            std::cout << "Unknown command: " << found_command.value().name << std::endl;
            return false;
    }
}
