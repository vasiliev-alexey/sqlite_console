//
// Created by alexey on 01.09.16.
//

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include "FileManager.h"
#include "../utils/CLog.h"

using namespace std;

FileManager::FileManager(string fname) : _valid(false), _fileName(fname) {
    CLog::SetLevel(CLog::All);
    _valid = checkFileExists();
}

bool FileManager::checkFileExists() {
    if (FILE *file = fopen(_fileName.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        CLog::Write(CLog::Debug, "Нет файла с инструкциями" + _fileName);
        return false;
    }
}

std::vector<string> FileManager::readInstructions() {
    vector<string> result;
    std::string line;
    std::ifstream infile(_fileName);
    while (std::getline(infile, line)) {
        result.push_back(line);
        CLog::Write(CLog::Debug, "Read instr:" + line);
    }
    infile.close();
    return vector<string>();
};