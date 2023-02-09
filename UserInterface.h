//This is the specification file for the User Interface.
// Created by Rowan on 06.10.2019.
//

#ifndef AUTOMOTIVE_EXPERT_USERINTERFACE_H
#define AUTOMOTIVE_EXPERT_USERINTERFACE_H
#include <iostream>
#include <algorithm>

using namespace std;

class UserInterface{
private:

    bool isDiagnostic = false;  // Should diagnostic questions be used?
    bool isRepair = false;      // Should repair questions be used?
    bool atStart = true;        // Has the program just started? Init to true.

public:
    void greetUser();
    string promptUser(bool, bool);
    string getUserInput(int);
    void checkInput(bool &, string &);
    void showResults(string);
    void changeMode(string);
};

#endif //AUTOMOTIVE_EXPERT_USERINTERFACE_H
