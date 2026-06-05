#include <iostream>
#include "parser.hpp"
using namespace std;


int main() {
    while (1) {
        string user_input;
        std::cout << "Type: ";
        std::getline(std::cin, user_input);
        parse_input(user_input); 
    }
    return 0;
}
