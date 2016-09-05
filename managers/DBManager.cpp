//
// Created by alexey on 02.09.16.
//
#include <stdio.h>
#include "DBManager.h"
#include "sqlite3.h"
#include "../utils/CLog.h"
#include "FileManager.h"

static int callback(void *NotUsed, int argc, char **argv, char **szColName) {

    DisplayManager *manager = (DisplayManager *) NotUsed;
    for (int i = 0; i < argc; i++) {
        manager->outputData(string(szColName[i]) + " = " + argv[i]);
    }
    return 0;
}

int DBManager::executeQuery(std::vector<string> command) {

    sqlite3 *db;
    int rc;
    char *zErrMsg = 0;
    try {

        rc = sqlite3_open(_dbName.c_str(), &db);

        if (rc) {
            fprintf(stderr, "Не возможно открыть базу данных: %s\n", sqlite3_errmsg(db));
            return (0);
        } else {
            CLog::Write(CLog::Debug, "База открыта успешно");
        }
        if (_autoCommit) {
            sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);
        }
        for (auto c : command) {
            rc = sqlite3_exec(db, c.c_str(), callback, _manager, &zErrMsg);
            if (rc != SQLITE_OK) {
                fprintf(stderr, "Ошибка при выполнении SQL инструкции: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);

                if (_autoCommit) {
                    sqlite3_exec(db, "ROLLBACK TRANSACTION;", NULL, NULL, NULL);
                }
                throw;
            } else {
                CLog::Write(CLog::Debug, "SQL инструкция успешно обработана:" + c);

            }
        }
        if (_autoCommit) {
            sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
        }
        sqlite3_close(db);
    } catch (exception e) {
        fprintf(stderr, "Ошибка при выполнении SQL инструкции: %s\n", zErrMsg);
        try {
            sqlite3_close(db);
        } catch (exception ee) { ;
        }
    }
    return 0;
}


DBManager::DBManager(DisplayManager *manager, string dbName, bool autoCommit)
        : _autoCommit(autoCommit), _dbName(dbName), _manager(manager) {
    if (!FileManager::checkFileExists(dbName)) {
        CLog::Write(CLog::Debug, "База " + dbName + " отсутсвует и будет создана \n");
    }

}
