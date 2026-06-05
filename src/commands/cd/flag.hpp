#ifndef CD_FLAG_HPP
#define CD_FLAG_HPP

#include <vector>
using namespace std;


enum CdFlags {
    Help,
    None
};

struct CdCommand {
    string arg;
    CdFlags flag;
}; 

#endif
