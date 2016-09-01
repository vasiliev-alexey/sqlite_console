#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    std::cout << "Program started" << std::endl;
    utils u;
    vector<string> params = u.convertParamToVector(argv, argc);


    if (!u.checkParam(params)) {
        return 1;
    }


    map<string, string> mp;
    mp = u.convertToMap(params);

    std::cout << "programm finished" << std::endl;
    return 0;
}



