#ifndef COMMAND_HPP
#define COMMAND_HPP

using namespace std;

enum CommandType {
    CD,
    TOUCH,
    CAT,
    PWD,
    EXIT,
    UNKNOWN
};

struct Command {
    string name;
    unsigned long nb_args;
    CommandType type;
};

#endif
