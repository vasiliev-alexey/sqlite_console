//
// Created by alexey on 01.09.16.
//
#include <map>
#include <iostream>
#include "ParamsManager.h"
#include "../utils/CLog.h"

#ifndef DEBUG
#define DEBUG  true
#endif
using namespace std;

std::map<string, string> ParamsManager::convertToMap(vector<string> param) {
    std::map<string, string> paramMap;

    for (int i = 0; i < param.size();) {
        paramMap[param[i]] = param[i + 1];
        i = i + 2;
    }
    return paramMap;
}

static void printHelp() {
    std::cout << "Допустимые ключи:\n";
    std::cout << "-d   = Имя базы данных\n";
    std::cout << "-f   = Путь к файлу с коммандой для БД\n";
    std::cout << "-q   = Инструкция задана из  коммандной строки";
    std::cout << "-o   = Режим вывода  результатов FILE – вывод в файл, CONSOLE – вывод в Консоль";
    std::cout << "-of  = Файл с результатами выполнения инструкций";
    std::cout << "-h   = Помощь";
}

bool checkParamCode(string paramKey, string paramValue) {
    /* TODO validation
     * if( (paramKey == "-f" || paramKey == "-d" ) && ! paramValue->empty()) {
         return true;
     }*/
    return true;
}

bool ParamsManager::checkParam(vector<string> params) {
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

vector<string> ParamsManager::convertParamToVector(char **pString, size_t size) {
    vector<string> r;
    for (int i = 1; i < size; i++) {
        r.push_back(std::string(pString[i]));
    }
    return r;
}

ParamsManager::ParamsManager(int argc, char **argv) : _isValid(false) {
    CLog::SetLevel(CLog::Debug);
    if (argc < 2) {
        return;
    }
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            string arg2;
            if (i < argc - 1 && (arg == "-f" || arg == "-h")) {
                arg2 = argv[i + 1];;
            }
            if (arg == "-h") {
                printHelp();
                return;
            }
            if (!checkParamCode(arg, arg2)) {
                std::cout << "Параметры указаны не верно:\n";
                printHelp();
                return;
            }
        }
        vector<string> tmp = convertParamToVector(argv, argc);
        paramHolder = convertToMap(tmp);
        CLog::Write(CLog::Debug, string("ParamHolder=" + to_string(paramHolder.size())).c_str());
        _isValid = true;
    }
}

bool ParamsManager::isParamValid() {
    return _isValid;
}

string ParamsManager::getParamValue(string paramKey) {
    if (paramHolder.find(paramKey) != paramHolder.end()) {
        return paramHolder[paramKey];
    } else {
        throw "No parmam by key" + paramKey;
    }
}

bool ParamsManager::checkParamValue(string paramKey) {
    if (paramHolder.find(paramKey) != paramHolder.end()) {
        return true;
    } else {
        return false;
    }
}

ParamsManager::~ParamsManager() {
}

