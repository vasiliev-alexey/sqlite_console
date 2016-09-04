//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_DBMANAGER_H
#define SQLLITE_CONSOLE_DBMANAGER_H
#include <string>
#include <vector>
#include "DisplayManager.h"

class DBManager {

public:

    DBManager(DisplayManager *manager , string dbName , bool autoCommit = false);

    static bool checkDbExists(std::string dbName);

    bool executeBatchCommand(std::vector<string> command);

    int executeQuery(std::string command);

private:
    bool  _autoCommit;
    DisplayManager *_manager;
    string _dbName;
};


#endif //SQLLITE_CONSOLE_DBMANAGER_H
