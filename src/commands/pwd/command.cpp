#include <filesystem>
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;

/**
 * execute_pwd
 * function that execute the command line tool: pwd  
 * return: bool
 */
bool execute_pwd(vector<string> flags){
    for (string flag: flags) {
        if (flag == "-h" || flag == "--help") {
            std::cout << "pwd - print name of current/working directory" << std::endl;
            return true;
        }
    }

    std::cout << filesystem::current_path() << std::endl;

    return true;
}
