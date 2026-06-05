#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

enum CommandType {
    CD,
    TOUCH,
    CAT,
    PWD,
    EXIT,
    UNKNOWN
};

struct Command {
    std::string name;
    unsigned long nb_args;
    CommandType type;
};

#endif
