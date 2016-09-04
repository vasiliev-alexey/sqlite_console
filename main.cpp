#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "managers/ParamsManager.h"
#include "managers/FileManager.h"
#include "utils/CLog.h"
#include "managers/DBManager.h"
#include "managers/ConsoleDisplayManager.h"
#include "managers/FileOutPutManager.h"

#define  DEBUG false
using namespace std;


int main(int argc, char *argv[]) {
    std::cout << "Program started" << std::endl;
    ParamsManager u(argc, argv);
    DisplayManager *dpm;
    CLog::SetLevel(CLog::Debug);

    if (!u.isParamValid()) {
        std::cout << "Ошибочные пераметры. Работа программы прекращена" << std::endl;
        return 1;
    }
    vector<string> instructions;
    if (u.checkParamValue("-f")) {
        // набор команд пришел из файла;
        auto fname = u.getParamValue("-f");
        FileManager fm(fname);
        if (!fm.isValid()) {
            throw "Ошибка при работе с файлом " + fname;
        }
        instructions = fm.readInstructions();

    } else if (u.checkParamValue("-q")) {
        // набор комманд пришел из строки запроса
        instructions.push_back(u.getParamValue("-q"));
    }

    string outValue = u.getParamValue("-o");
    if (outValue == "FILE") {
        string fname = u.getParamValue("-of");
        dpm = new FileOutPutManager(fname);
    } else if (outValue == "CONSOLE") {
        dpm = new ConsoleDisplayManager();
    } else {
        throw "Выбран не верныф формат вывода результатов";
    }

    string dbName = u.getParamValue("-d");

    DBManager dbm(dpm, dbName, true);

    dbm.executeBatchCommand(instructions);

    std::cout << "Успешное завершение работы программы" << std::endl;
    return 0;
}



