#include <iostream>
#include "log_auxiliars.hpp"

int main(){
    cout << "### SYSTEM LOG ###\n";
    cout << "Testing default logging options...\n";
    //Test on DEBUG type log 
    logMessage("Reading memory at location 0xb1382b", Severity::DEBUG);
    //Test on INFO type log
    logMessage("Update done on core", Severity::INFO);
    //Test on WARNING type log
    logMessage("Min Heap implementation may leak data", Severity::WARNING);
    //Test on ERROR type log
    logMessage("Object is not suscriptable", Severity::ERROR);
    //Test on CRITICAL type log 
    logMessage("Memory leak, core dumped", Severity::CRITICAL);
    //Test on error and line logging 
    logMessage("Comparing int with string", "MATRIX.cpp", 123);
    //Test on user SECURITY access
    logMessage("ACCESS GRANTED", "$sudo");
    //Test on RUNTIME_ERROR and exception handling
    try {
        int a = 2;
        int b = 0;
        if (b == 0) throw "DIVISION BY ZERO"; //Error captured on runtime
        return a/b;
    }
    catch (const char* e) {
        logMessage(e, Severity::RUNTIME_ERROR);
        return 1; //handled and returning 1 as error code
    }
    return 0;
}