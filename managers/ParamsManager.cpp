//
// Created by alexey on 01.09.16.
//
#include <map>
#include <iostream>
#include "ParamsManager.h"
#include "../utils/CLog.h"
#include "FileManager.h"

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
    fprintf(stdout,  "Допустимые ключи: \n");
    fprintf(stdout,  "-d   = Имя базы данных\n");
    fprintf(stdout,  "-f   = Путь к файлу с коммандой для БД\n");
    fprintf(stdout,  "-q   = Инструкция задана из  коммандной строки\n");
    fprintf(stdout,  "-o   = Режим вывода  результатов FILE – вывод в файл, CONSOLE – вывод в Консоль\n");
    fprintf(stdout,  "-of  = Файл с результатами выполнения инструкций\n");
    fprintf(stdout,  "-h   = Помощь\n");
}

bool checkParamCode(string paramKey, string paramValue) {


    if (paramKey == "-f" && ! FileManager::checkFileExists(paramValue)) return false;
    return true;
}


bool ParamsManager::checkParamConsistance() {

    if (paramHolder.find("-d") == paramHolder.end()) {
        fprintf(stderr, "Не задано имя БД: -d / -f\n");
        return false;
    }
    if (paramHolder.find("-o") == paramHolder.end()) {
        fprintf(stderr, "Не задан формат вывода -0 / -f\n");
        return false;
    }

    if (paramHolder.find("-q") == paramHolder.end() && paramHolder.find("-f") == paramHolder.end()
            ) {
        fprintf(stderr, "Не задан источник для выполнения инструкций: -q / -f\n");
        return false;
    }
    if (paramHolder["-o"] != "FILE" && paramHolder["-o"] != "CONSOLE") {
        fprintf(stderr, "Не задан формат для вывода результатов: -o\n");
        return false;
    }
    if (paramHolder["-o"] == "FILE" && paramHolder.find("-of") == paramHolder.end()) {
        fprintf(stderr, "Не задано имя файла для вывода результатов: -of\n");
        return false;
    }
    return  true;

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
            if (arg == "-h") {
                printHelp();
                _isValid = false;
                return;
            }
            string arg2;
            if (i < argc - 1 && (arg == "-f" ||
                                 arg == "-d" ||
                                 arg == "-q" ||
                                 arg == "-of" ||
                                 arg == "-o"
            )) {
                arg2 = argv[i + 1];;
            }

            if (!checkParamCode(arg, arg2)) {

                fprintf(stderr, "Параметры указаны не верно: %s\n" , arg);
                printHelp();
                _isValid = false;
                return;
            }
        }
        CLog::Write(CLog::Debug, string("convert param to  vector"));
        vector<string> tmp = convertParamToVector(argv, argc);
        CLog::Write(CLog::Debug, string("Convert param to map"));
        paramHolder = convertToMap(tmp);
        CLog::Write(CLog::Debug, string("validate param"));

        _isValid = checkParamConsistance();
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

