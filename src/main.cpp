#include <iostream>
#include <filesystem>
#include <string>
#include "parser.hpp"
using namespace std;

string ps1() {
    string current_path = filesystem::current_path();
    string final_ps1 = current_path + "\n> ";
    return final_ps1;
}

int main() {
    while (1) {
        string user_input;
        std::cout << ps1();
        std::getline(std::cin, user_input);
        if (!parse_input(user_input)) {
            return 1;
        }
        std::cout << std::endl;
    }
}
