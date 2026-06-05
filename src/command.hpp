#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

enum CommandType {
    CD,
    TOUCH,
    CAT,
    PWD,
    UNKNOWN
};

struct Command {
    std::string name;
    int nb_args;
    CommandType type;
};

#endif
