#ifndef CAT_FLAG_HPP
#define CAT_FLAG_HPP

#include <vector>
using namespace std;


enum CatFlags {
    Help,
    None
};

struct CatCommand {
    vector<string> arg;
    CatFlags flag;
}; 

#endif
