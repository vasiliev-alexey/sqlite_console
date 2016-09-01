//
// Created by alexey on 01.09.16.
//
#include <map>
#include <iostream>
#include "utils.h"

using namespace std;

std::map<string, string> utils::convertToMap(vector<string> param) {
    std::map<string, string> paramMap;

    return paramMap;
}


static void printHelp() {
    std::cout << "Допустимые ключи:\n";
    std::cout << "-d  = имя базы данных\n";
    std::cout << "-f  = путь к файлу с коммандой для БД\n";
}

bool checkParamCode(string param, string par2) {
    /* TODO validation
     * if( (param == "-f" || param == "-d" ) && ! par2->empty()) {
         return true;
     }*/
    return true;
}

bool utils::checkParam(vector<string> params) {
    if (params.size() < 1) {
        std::cout << "Неверное количество параметров:\n";
        std::cout << "use -help \n";
        return 1;
    }
    if (params.size() > 1) {
        for (int i = 1; i < params.size(); i++) {
            string arg = params[i];
            string arg2;
            if (i < params.size() - 1 && (arg == "-f" || arg == "-h")) {
                arg2 = params[i + 1];;
            }

            if (arg == "-h") {
                printHelp();
                return false;
            }
            if (!checkParamCode(arg, arg2)) {
                std::cout << "Параметры указаны не верно:\n";
                printHelp();
                return false;
            }
        }
        return true;
    }
}

vector<string> utils::convertParamToVector(char **pString, size_t size) {

    vector<string> r;
    for (int i = 1; i < size; i++) {
        r.push_back(std::string(pString[i]));
    }

    return r;
}

