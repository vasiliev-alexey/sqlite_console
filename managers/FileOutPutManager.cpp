//
// Created by alexey on 02.09.16.
//

#include "FileOutPutManager.h"

void FileOutPutManager::outputData(std::string result) {

    std::ofstream out(_fileName);
    out << result;
    out.close();

}

FileOutPutManager::FileOutPutManager(string fileOutPutName)  : _fileName(fileOutPutName){

}
