#include <filesystem>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "flag.hpp"
#include <fstream>
using namespace std;

/**
 * execute_cd
 * function that execute the command line tool: cd 
 * return: bool
 */
bool execute_touch(vector<string> args, vector<string> flags) {
    bool use_help = false;
    TouchCommand command;
    for (string flag: flags) {
        if (flag == "-h" || flag == "--help") {
            use_help = true;
        }
    }
    if (use_help) command = {args, Help};
    else command = {args, None};

    if (command.flag == Help){
        std::cout << "touch - create file, or change file timestamps" << std::endl;
        return true;
    }

    if (command.flag == None) {
        for (string arg: args) {
            string final_arg;
            error_code err;
            if (arg.rfind("~", 0) == 0) {
                final_arg = string("/home/") + getlogin() +"/" + arg.erase(0, 1);
            } else {
                final_arg = arg;
            }
            filesystem::path path{final_arg};
            std::ofstream ofs(path);
            ofs.close();
        }
    }
    return true;
};
