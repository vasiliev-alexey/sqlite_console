//
// Created by alexey on 01.09.16.
//

#ifndef SQLLITE_CONSOLE_FILEMANAGER_H
#define SQLLITE_CONSOLE_FILEMANAGER_H

#include <vector>

using namespace std;

class FileManager {

public:


    FileManager(string fname);
    std::vector<string> readInstructions();
    bool isValid() { return  _valid ;};

     bool checkFileExists();

    static bool checkFileExists(string fileName);

private:
    bool  _valid;
    string _fileName;

};


#endif //SQLLITE_CONSOLE_FILEMANAGER_H
