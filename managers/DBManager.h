//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_DBMANAGER_H
#define SQLLITE_CONSOLE_DBMANAGER_H

#include <sqlite3.h>
#include <string>
#include "DisplayManager.h"


class DBManager {

public:

    DBManager(DisplayManager *manager , bool autoCommit = false);

    static bool checkDbExists(std::string dbName);

    bool executeNonQuery(std::string command);

    int executeQuery(std::string command);

    int setDb(std::string dbName);

    void setAutoCommit(bool autoCommit);

private:
      int callback(void *NotUsed, int argc, char **argv, char **szColName);
    bool  _autoCommit;
    DisplayManager *_manager;
};


#endif //SQLLITE_CONSOLE_DBMANAGER_H
