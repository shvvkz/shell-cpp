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
bool execute_cat(vector<string> args, vector<string> flags) {
    bool use_help = false;
    CatCommand command;
    for (string flag: flags) {
        if (flag == "-h" || flag == "--help") {
            use_help = true;
        }
    }
    if (use_help) command = {args, Help};
    else command = {args, None};

    if (command.flag == Help){
        std::cout << "cd — change the working directory" << std::endl;
        return true;
    }

    if (command.flag == None) {
        for (string arg: args) {
            string path;
            bool can_open_file = true;

            if (arg.rfind("~", 0) == 0) {
                path = string("/home/") + getlogin() +"/" + arg.erase(0, 1);
            } else {
                path = arg;

            }

            ifstream file(path);
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << path << std::endl;
                can_open_file = false;
            }
            
            if (can_open_file) {
                string line;
                while (getline(file, line)) {
                    std::cout << line << std::endl;
                }
            }
            file.close();
        }
    }
    return true;
};
