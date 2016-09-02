//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_DISPLAYMANAGER_H
#define SQLLITE_CONSOLE_DISPLAYMANAGER_H

#include <string>

using namespace std;

class DisplayManager {

public:
    virtual void outputData(std::string result)=0;

};


#endif //SQLLITE_CONSOLE_DISPLAYMANAGER_H
