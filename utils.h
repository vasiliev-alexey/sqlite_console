//
// Created by alexey on 01.09.16.
//
#include <map>
#include <vector>

#ifndef SQLLITE_CONSOLE_UTILS_H
#define SQLLITE_CONSOLE_UTILS_H
using namespace std;

class utils {

public:
    std::map<string, string> convertToMap(vector<string> param);

    vector<string> convertParamToVector(char **pString, size_t size);

    bool checkParam(vector<string> params);
};


#endif //SQLLITE_CONSOLE_UTILS_H
