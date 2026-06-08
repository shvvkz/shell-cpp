#ifndef TOUCH_FLAG_HPP
#define TOUCH_FLAG_HPP

#include <vector>
using namespace std;


enum TouchFlags {
    Help,
    None
};

struct TouchCommand {
    vector<string> args;
    TouchFlags flag;
}; 

#endif
