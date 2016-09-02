//
// Created by alexey on 02.09.16.
//

#include "DBManager.h"
#include <iostream>


bool DBManager::executeNonQuery(std::string command) {
    return false;
}

int DBManager::executeQuery(std::string command) {
    return 0;
}

int DBManager::setDb(std::string dbName) {
    return 0;
}


int DBManager::callback(void *NotUsed, int argc, char **argv, char **szColName) {
    for (int i = 0; i < argc; i++) {
        _manager ->outputData( string(szColName[i]) + " = " +  argv[i] );
    }

    std::cout << "\n";
    return 0;
}

bool DBManager::checkDbExists(std::string dbName) {
    return false;
}

DBManager::DBManager(DisplayManager *manager, bool autoCommit)
        : _autoCommit(autoCommit), _manager(manager) {
}
