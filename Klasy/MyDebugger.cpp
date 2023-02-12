#include <iostream>
#include "MyDebugger.h"

bool MyDebugger::debugMode = false;

MyDebugger::MyDebugger() {}

void MyDebugger::setDebugMode(bool _debugMode) {
    debugMode = _debugMode;
}

void MyDebugger::debug(string msg) {
    if(debugMode) {
        cout << msg << '\n';
    }
}