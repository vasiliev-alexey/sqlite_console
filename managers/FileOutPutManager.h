//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_FILEOUTPUTMANAGER_H
#define SQLLITE_CONSOLE_FILEOUTPUTMANAGER_H


#include "DisplayManager.h"
#include <fstream>

class FileOutPutManager : public DisplayManager {
public:
    FileOutPutManager(string fileOutPutName);
    virtual void outputData(std::string result) override;

private:
    string _fileName;

};


#endif //SQLLITE_CONSOLE_FILEOUTPUTMANAGER_H
