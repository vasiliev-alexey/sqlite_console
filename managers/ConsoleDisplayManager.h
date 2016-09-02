//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_CONSOLEDISPLAYMANAGER_H
#define SQLLITE_CONSOLE_CONSOLEDISPLAYMANAGER_H


#include "DisplayManager.h"

class ConsoleDisplayManager : public DisplayManager {
public:
    virtual void outputData(std::string result) override;
};


#endif //SQLLITE_CONSOLE_CONSOLEDISPLAYMANAGER_H
