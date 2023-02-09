// This is the implementation file for the Repair Advisor module
// Created by Rowan on 07.10.2019.
//

#include <iostream>             // Preprocessor directive added by Rowan
#include <string>
#include <iomanip>
//#include <ctype.h>
#include <regex>
#include "Repair_Advisor.h"
#include "KnowledgeBase.h"      // Needed for the KnowledgeBase
#include "ConclusionVarQueue.h"

using namespace std;

//**********************************************************************************************************************
string RepairAdvisor::runRepairAdvisor(UserInterface &userInterface, KnowledgeBase &kB, string &mode, string diagResult){

    string suggestedRepair;
    suggestedRepair = "Pretend this is a real repair suggestion for now... :)";

    //kB.displayRuleBase(mode);
    //kB.displayVarList(mode);
    //kB.displayClauseVarList(mode);
    ConclusionVarQueue con;
    int clauseVarPtr[] = {0,0};
    string variable;
    bool varInit;

    string input = diagResult;

    if(input == "")
        input = userInterface.promptUser(false, true);
    // Initialize input variable (if it exists) and enqueue it onto the conclusion queue
    inputData(userInterface, con, kB, mode, input);

    // TRACK VARIABLES
    //kB.displayVarList(mode);

    suggestedRepair = processQueue(userInterface, con, kB, clauseVarPtr,mode, variable, varInit);

    // FINAL QUEUE STATE
    //con.printQueue();

    return suggestedRepair;

}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
void RepairAdvisor::inputData(UserInterface &userInterface, ConclusionVarQueue &con, KnowledgeBase &kB, string &mode, string &input){
    KnowledgeBase::variable variable;
    for(int j = 0; j < kB.getVarListSize(mode); j++){
        if(kB.getVariableName(mode, j) == input) {
            kB.setVariable(mode, "YES", j);
                break;
            }
    }
    initCheck(userInterface, kB, mode, input);
    for(int i = 0; i < kB.getVarListSize(mode); i++)
    {
        if(kB.getVariableName(mode, i) == input) {

            variable.name = kB.getVariableName(mode, i);
            variable.value = kB.getVariableValue(mode, i);
            con.enqueue(variable);
            break;
        }
    }
    //con.printQueue();
}
//**********************************************************************************************************************
//
//**********************************************************************************************************************
string RepairAdvisor::processQueue(UserInterface &userInterface, ConclusionVarQueue &con, KnowledgeBase &kB, int clauseVarPtr[], string &mode, string &variable, bool &varInit){

    KnowledgeBase::variable previousConVar; // move to function

    do {
        previousConVar = searchConVarList(userInterface, con, kB, clauseVarPtr, mode, variable, varInit);
    }while(!con.isEmpty());

    // return results for this value as the predicted best outcome (captured by suggested repair)
    return previousConVar.name; // + " = " + previousConVar.value;
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
KnowledgeBase::variable RepairAdvisor::searchConVarList(UserInterface &userInterface, ConclusionVarQueue &con, KnowledgeBase &kB, int clauseVarPtr[], string &mode, string &variable, bool &varInit){

    kB.setStartIndex(0); // Set the start index to search Clause Variable List for current variable to 0
    bool varFound = false;
    int clauseNum;
    int ruleNum;
    bool ruleSatisfied;
    string ruleConclusion;
    KnowledgeBase::variable previousConVar;
    if(!con.isEmpty()) {
        do {
            for (int i = kB.getStartIndex(); i < kB.getClauseVarListSize(mode); i++) { // change to do-while
                // If the variable at front of queue matches the next item in Clause Variable List
                if (con.getFrontItem().name == kB.getClauseVariable(mode, i)) {
                    varFound = true;
                    clauseNum = i + 1; // offset by one since index starts at 0.
                    kB.setStartIndex(i + 2); // Adjust start index to avoid processing the same instance in the future.

                    // Derive the Rule Number from clauseNum
                    ruleNum = kB.deriveRuleNum(clauseNum);

                    // Place the computer Rule Number in the first element of ClauseVariablePtr[] and set clause# = 1 in 2nd element.
                    clauseVarPtr[0] = ruleNum;
                    clauseVarPtr[1] = 1;    // starting clause number for rule, range from 1 to 4 (adjust to 0 - 3 for offset)

                    ruleSatisfied = checkRuleClauses(userInterface, con, kB, clauseVarPtr, mode, variable, varInit);

                    // If rule is satisfied, get the conclusion variable, initialize it automatically, and add it to the queue.
                    if (ruleSatisfied) {
                        extractConVar(con, kB, clauseVarPtr, mode, variable, varInit);
                    }
                        // Otherwise, if the rule is not satisfied, keep checking for other matching rules
                    //else if (!ruleSatisfied) {

                   // }
                    // Set varFound back to false when checking for new instance of it in Clause Variable List.
                    varFound = false;
                    // TEST FOR STARTINDEX
                    /*cout << "***********  START INDEX TEST  **************"<< endl;
                    for (int j = kB.getStartIndex(); j < kB.getClauseVarListSize(mode); j++) {
                        if(con.getFrontItem().name == kB.getClauseVariable(mode, j))
                            cout << con.getFrontItem().name << " is at location "<< j+1 << endl;
                        else
                            cout << con.getFrontItem().name << "is not at this location in Clause Variable List." << endl;
                    }
                    cout << "********************************************"<< endl;*/
                }
            }
            if (!varFound) {
                kB.setStartIndex(kB.getClauseVarListSize(mode) + 1); // Mark all entries in Clause Variable List as
                // searched for the front conclusion variable variable
                // Dequeue front conclusion variable
                con.dequeue(previousConVar);
            }
            // While here are still instances of the variable at the front of the queue left to be checked
        } while (kB.getStartIndex() < kB.getClauseVarListSize(mode));
    }
    else{
        cout << "DIAGNOSTIC CODE NOT FOUND. PROGRAM WILL NOW EXIT." << endl;
        exit(0);
    }
    return previousConVar;
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
bool RepairAdvisor::checkRuleClauses(UserInterface &userInterface, ConclusionVarQueue &con, KnowledgeBase &kB, int clauseVarPtr[], string &mode, string &variable, bool &varInit){
    string ruleClause;
    bool clauseSatisfied[] = {false, false, false, false};
    bool ruleSatisfied = false;

    do {    // While there are clauses to be checked in the rule
        // Find corresponding Rule and Clause in Rule List
        ruleClause = kB.getRuleClause(mode, clauseVarPtr[0], clauseVarPtr[1]);


        // Extract variable name from the clause
        try {
            regex re(R"(^\w+([A-Z]))",
                     regex_constants::ECMAScript);   // Raw string literal to compare to variable names.
            // This raw string literal should capture ONLY characters A-Z on the left of the '=' in the clause.

            smatch match_results;   // Storage container for results that match the above raw string literal.
            // match_results[0] points to the start of the submatch and should give whole matching word
            // match_results[1] points to the end of the submatch and should give the last letter of match

            // Get the variable name from clause.
            regex_search(ruleClause, match_results, re);
            variable = match_results[0];


        } catch (const regex_error &e) {
            cout << "regex_error caught: " << e.what() << " code: " << e.code() << '\n';
        }
        // If there is an empty clause, assume clause is satisfied.
        if(variable == ""){
            clauseSatisfied[clauseVarPtr[1]-1] = true;
        }
            // Otherwise, if there is a clause...
        else if(variable != "") {

            // check for clause variable initialization
            //varInit = kB.initCheck(variable);
            varInit = initCheck(userInterface, kB, mode, variable);
            if (!varInit) {
                // Initialize variable with user input if it has not been initialized already.
                //kB.initVar(variable);
                initVar(userInterface, kB, mode, variable);
            }
            // Check if clause is satisfied
            for(int j = 0; j < kB.getVarListSize(mode); j++){
                if(variable == kB.getVariableName(mode, j)){
                    if(kB.getVariableName(mode, j)+" = "+kB.getVariableValue(mode,j) == ruleClause) {
                        clauseSatisfied[clauseVarPtr[1] - 1] = true;
                        break;
                    }
                }
            }
        }

        // Check for the next rule clause variable
        clauseVarPtr[1]++;
    }while(clauseVarPtr[1] < kB.getRuleClauseMax()+1);
    // Now that all clauses are instantiated, check if the rule is satisfied
    if(clauseSatisfied[0] && clauseSatisfied[1] && clauseSatisfied[2] && clauseSatisfied[3])
        ruleSatisfied = true;   // return this value when this function is written.

    return ruleSatisfied;
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
void RepairAdvisor::extractConVar(ConclusionVarQueue &con, KnowledgeBase &kB, int clauseVarPtr[], string &mode, string &variable, bool &varInit){
    string conVarValue;
    KnowledgeBase::variable newConVar;
    string ruleConclusion;

    // Get conclusion variable name and value
    ruleConclusion = kB.getRuleConclusion(mode, clauseVarPtr[0]/10-1);


    try {
        regex re(R"(^\w+([A-Z]))",
                 regex_constants::ECMAScript);   // Raw string literal to compare to variable names.
        // This raw string literal should capture ONLY characters A-Z on the left of the '=' in the clause.

        smatch match_results;   // Storage container for results that match the above raw string literal.
        // match_results[0] points to the start of the submatch and should give whole matching word
        // match_results[1] points to the end of the submatch and should give the last letter of match

        // Get the variable name from conclusion clause.
        regex_search(ruleConclusion, match_results, re);
        variable = match_results[0];


    } catch (const regex_error &e) {
        cout << "regex_error caught: " << e.what() << " code: " << e.code() << '\n';
    }

    // Initialize the conclusion variable in the variable list (NO USER INPUT)
    try {
        regex re(R"(\w+([A-Z])$)", regex_constants::ECMAScript);   // Raw string literal to compare to variable names.
        // This raw string literal should capture ONLY characters A-Z on the left of the '=' in the clause.

        smatch match_results;   // Storage container for results that match the above raw string literal.
        // match_results[0] points to the start of the submatch and should give whole matching word
        // match_results[1] points to the end of the submatch and should give the last letter of match

        // Get the conclusion variable value from conclusion statement.
        regex_search(ruleConclusion, match_results, re);

        conVarValue = match_results[0];


    } catch (const regex_error &e) {
        cout << "regex_error caught: " << e.what() << " code: " << e.code() << '\n';
    }
    // Initialize value in Variable List
    for(int k = 0; k < kB.getVarListSize(mode); k++){
        if(variable == kB.getVariableName(mode, k)){
            kB.setVariable(mode, conVarValue,k);
            break;
        }
    }
    // Show updated Variable List state
    //kB.displayVarList(mode);
    // Add it to the Conclusion Variable Queue
    newConVar.name = variable;
    newConVar.value = conVarValue;
    con.enqueue(newConVar);
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
bool RepairAdvisor::initCheck(UserInterface &userInterface,KnowledgeBase &kB, string &mode, const string &varName)
{
    bool initialized = false;

    for(int i = 0; i < kB.getVarListSize(mode);i++){
        //if(repairVarList.at(i).name.compare(varName) == 0 ){
        if(varName == kB.getVariableName(mode, i)){
            //if(repairVarList.at(i).value == "")
            if(kB.getVariableValue(mode, i) == "")
            {
                //cout<<varName<<" is not initialized\n";
                initVar(userInterface, kB, mode, varName);
                initialized = false;
                break;
                //return false;
            }
            else
            {
                //cout<<varName<<" is initialized\n";
                initialized = true;
                break;
                //return true;
            }
        }

    }
    return initialized;
}

//**********************************************************************************************************************
//
//**********************************************************************************************************************
void RepairAdvisor::initVar(UserInterface &userInterface, KnowledgeBase &kB, string &mode, const string varName)
// MOVE TO USER INTERFACE, EVENTUALLY
{
    string input;

    //for(int i = 0; i < repairVarList.size();i++)
    for(int i = 0; i < kB.getVarListSize(mode); i++)
    {
        //INITIALIZE VARIABLE
        //if(repairVarList.at(i).name == varName)
        if(kB.getVariableName(mode, i) == varName)
        {
            //repairVarList.at(i).init = 1;
            //IF THERE IS NO VALUE ASK FOR VALUE
            //if(repairVarList.at(i).value == "")
            if(kB.getVariableValue(mode, i) == "")
            {
                kB.setVariable(mode, userInterface.getUserInput(i),i);

            }
        }
    }
}

