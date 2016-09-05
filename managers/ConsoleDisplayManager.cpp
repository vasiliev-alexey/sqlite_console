//
// Created by alexey on 02.09.16.
//

#include <iostream>
#include "ConsoleDisplayManager.h"

void ConsoleDisplayManager::outputData(std::string result) {
   fprintf( stdout , "Result: %s\n " ,  result.c_str()  );
}
