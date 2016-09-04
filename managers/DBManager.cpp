//
// Created by alexey on 02.09.16.
//
#include <stdio.h>
#include "DBManager.h"
#include <iostream>
#include "sqlite3.h"
#include "../utils/CLog.h"

static int callback(void *NotUsed, int argc, char **argv, char **szColName) {

    DisplayManager *manager = (DisplayManager *) NotUsed;
    for (int i = 0; i < argc; i++) {
        manager->outputData(string(szColName[i]) + " = " + argv[i]);
    }
    return 0;
}

bool DBManager::executeBatchCommand(std::vector<string> command) {
    for (auto c : command) {
        executeQuery(c);
    }
    return false;
}

int DBManager::executeQuery(std::string command) {

    sqlite3 *db;
    int rc;
    char *zErrMsg = 0;

    rc = sqlite3_open(_dbName.c_str(), &db);
    if (rc) {
        fprintf(stderr, "Не возможно открыть базу данных: %s\n", sqlite3_errmsg(db));
        return (0);
    } else {
        CLog::Write(CLog::Debug, "База открыта успешно");
    }
    rc = sqlite3_exec(db, command.c_str(), callback, _manager, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Ошибка при выполнении SQL инструкции: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "SQL инструкция успешно обработана\n");
    }
    sqlite3_close(db);
    return 0;
}


bool DBManager::checkDbExists(std::string dbName) {
    return false;
}

DBManager::DBManager(DisplayManager *manager, string dbName, bool autoCommit)
        : _autoCommit(autoCommit), _dbName(dbName), _manager(manager) {
}
