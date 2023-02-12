#include <string>

using namespace std;

class MyDebugger {
    static bool debugMode;
    public:
        MyDebugger();
        void setDebugMode(bool _debugMode);
        static void debug(string msg);
};