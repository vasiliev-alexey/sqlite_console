//
// Created by alexey on 01.09.16.
//
#include <map>
#include <vector>

#ifndef SQLLITE_CONSOLE_UTILS_H
#define SQLLITE_CONSOLE_UTILS_H


using namespace std;

class ParamsManager {


public:
    ParamsManager(int argc, char *argv[]);

    bool isParamValid();

    string getParamValue(string paramKey);

    bool checkParamValue(string paramKey);

    map<string, string> paramHolder;
    ~ParamsManager();
private:
    vector<string> convertParamToVector(char **pString, size_t size);

    bool checkParam(vector<string> params);

    bool isValid;

    std::map<string, string> convertToMap(vector<string> param);
    //  map<string , string> paramHolder;
};


#endif //SQLLITE_CONSOLE_UTILS_H
