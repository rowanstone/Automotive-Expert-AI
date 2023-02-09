// This is the main controller for the Automotive Expert System.
// The diagnostic portion of the program utilizes a backward-chaining inference engine to determine the cause of the
// vehicle issue. Once an issue is found, then the program will use a forward-chaining inference method to provide the
// user with the recommended repair solution for the problem.

#include <iostream>
#include "KnowledgeBase.h"
#include "UserInterface.h"
#include "Diagnostic_Engine.h"
#include "Repair_Advisor.h"

int main() {
    string mode;
    string diagnosticResult;
    string suggestedRepair;
    KnowledgeBase diagKB, repairKB;
    UserInterface userInterface;
    DiagnosticEngine diagnosticEngine;
    RepairAdvisor repairAdvisor;


    userInterface.greetUser();
    mode = userInterface.promptUser(false, false);  // Get program mode from user at start of program.
    if(mode == "DIAGNOSTIC") {
        diagKB.initKB();
        diagnosticResult = diagnosticEngine.runDiagnostic(userInterface, diagKB, mode);
        userInterface.showResults(diagnosticResult);
        cout << "*****   HIT ENTER TO CONTINUE AND VIEW REPAIR SUGGESTION   *****" << endl;
        system("pause");
        mode = "REPAIR";
        userInterface.changeMode(mode);
        //repairKB.initKB();
        suggestedRepair = repairAdvisor.runRepairAdvisor(userInterface, diagKB, mode, diagnosticResult);
        userInterface.showResults(suggestedRepair);
    }
    else if(mode == "REPAIR") {
        repairKB.initKB();
        suggestedRepair = repairAdvisor.runRepairAdvisor(userInterface, repairKB, mode, "");
        //cout << "Suggested Repair is: " << suggestedRepair << endl;
        userInterface.showResults(suggestedRepair);
    }
    else if(mode == "EXIT")
        return 0;

    cout << "END OF PROGRAM\n";
    system("pause");
    return 0;
}