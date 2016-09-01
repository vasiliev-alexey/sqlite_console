//
// Created by alexey on 01.09.16.
//

#include <cstdio>
#include <string>
#include "FileManager.h"

using namespace std;

bool FileManager::checkFileExists(const string fileName) {
    if (FILE *file = fopen(fileName.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
};