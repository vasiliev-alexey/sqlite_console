#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "managers/ParamsManager.h"
#include "managers/FileManager.h"
#include "utils/CLog.h"

#define  DEBUG false
using namespace std;


int main(int argc, char *argv[]) {
    std::cout << "Program started" << std::endl;
    ParamsManager u(argc, argv);
    CLog::SetLevel(CLog::Debug);

    if (!u.isParamValid()) {
        std::cout << "Ошибочные пераметры. Работа программы прекращена" << std::endl;
        return 1;
    }
    vector<string> instructions;
    if (u.checkParamValue("-f")) {
        // набор команд пришел из файла;
        auto fname  = u.getParamValue("-f");
        FileManager fm(fname);
        if (! fm.isValid()) {
            throw "Ошибка при работе с файлом " + fname;
        }
        instructions  = fm.readInstructions();

    } else if (u.checkParamValue("-q")) {
        // набор комманд пришел из строки запроса
        instructions.push_back(u.getParamValue("-q"));
    }


    std::cout << "programm finished" << std::endl;
    return 0;
}



