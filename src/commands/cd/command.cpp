#include <filesystem>
#include <iostream>
#include <vector>
#include "flag.hpp"
using namespace std;

/**
 * execute_cd
 * function that execute the command line tool: cd 
 * return: bool
 */
bool execute_cd(string arg, vector<string> flags) {
    bool use_help;
    CdCommand command;
    for (string flag: flags) {
        if (flag == "-h" || flag == "--help") {
            use_help = true;
        }
    }
    if (use_help) command = {arg, Help};
    else command = {arg, None};

    if (command.flag == Help){
        std::cout << "using Help" << std::endl;
        return true;
    }

    if (command.flag == None) {
        std::cout << "using cd command with " << arg << std::endl;
        return true;
    }
    std::cout << "err: something went wrong" << std::endl;
    return false;
};
