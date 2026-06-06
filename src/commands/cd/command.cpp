#include <filesystem>
#include <unistd.h>
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
    bool use_help = false;
    CdCommand command;
    for (string flag: flags) {
        if (flag == "-h" || flag == "--help") {
            use_help = true;
        }
    }
    if (use_help) command = {arg, Help};
    else command = {arg, None};

    if (command.flag == Help){
        std::cout << "cd — change the working directory" << std::endl;
        return true;
    }

    if (command.flag == None) {
        string final_arg;
        error_code err;
        if (arg.rfind("~", 0) == 0) {
            final_arg = string("/home/") + getlogin() +"/" + arg.erase(0, 1);
        } else {
            final_arg = arg;
        } 
        filesystem::current_path(final_arg, err);

        if (err) {
            std::cout << "cd: \"" << final_arg << "\" " << err.message() << std::endl;
            return true;
        }
        return true;
    }
    std::cout << "err: something went wrong" << std::endl;
    return false;
};
