// This is the implementation file for the backward-chaining Diagnostic Engine.
// Created by Rowan on 05.10.2019.
//

#include <iostream>             // Preprocessor directive added by Rowan
#include <string>
#include <iomanip>
#include <ctype.h>
#include <regex>
#include "Diagnostic_Engine.h"
#include "KnowledgeBase.h"      // Needed for the KnowledgeBase class
#include "ConclusionStack.h"    // Needed for the ConclusionStack
using namespace std;

//**********************************************************************************************************************

string DiagnosticEngine::runDiagnostic(UserInterface &userInterface, KnowledgeBase &kB, string &mode)  // type specifier for main() corrected by Rowan
{

    ConclusionStack RuleStack;      // Create dynamic stack for rule number portion of Conclusion Stack
    ConclusionStack ClauseStack;    // Create dynamic stack for relative clause number portion of Conclusion Stack

    // NOTE: Conclusion Stack is actually 2 stacks! A Rule number stack and a clause stack, where
    // the rule number corresponds to those in the rule base, while the clause number held in the stack is based on the
    // relative location of the clause within a specific 4 block segment of the Clause Variable list.
    // Example: In the clause variable list structure, 'QUALIFY' for Rule 40 is #13, but in the clause stack it would be
    // #1, since it is the first clause variable for that rule. 'GRADE' for Rule 40 is #14 in the Clause Variable List,
    // but #2 in the stack, etc.

    regex re_value(R"(\w+([A-Z])$)", regex_constants::ECMAScript);
    smatch match_results;
    string rawInput;            // Holds user's raw input for processing
    string query;               // Holds conclusion variable entered by user
    string reply;               // Holds user's answer to the expert system's questions
    int nextRuleNum = 0;        // Holds the rule number for the next rule associated with desired conclusion variable.
    // (sn)
    int clauseNum = 1;          // Holds the clause number relative to associated next rule for desired conclusion
    // variable.
    int clauseLoc;              // Holds value for clause location to look up. (i)
    bool ruleSatisfied = false; // Holds whether all the conditions of the evaluated rule are satisfied. (s)
//    int previousRule;           // Holds value of previous rule checked after it is popped from RuleStack.
//    int previousClause;         // Holds value of the previous clause number checked after popped from ClauseStack.
    string conclusion;          // Holds the conclusion statement of satisfied rule.

    /***** initialization section ******/
    
    //kB.displayRuleBase(mode);
    //kB.displayVarList(mode);
    //kB.displayClauseVarList(mode);
    //kB.displayConList();

    /****** inference section *****/

    getUserQuery(userInterface, rawInput, query);

    findConclusionRule(userInterface, ruleSatisfied, kB, query, conclusion, nextRuleNum, clauseNum,
                       clauseLoc, RuleStack, ClauseStack, mode);

    // Extract only the conclusion value to pass along to the repair engine as a diagnostic code. regex_search(conclusion, match_results, re_value);
    //    conclusion = match_results[0];
    regex_search(conclusion, match_results, re_value);
    conclusion = match_results[0];
    return conclusion;
}

//**********************************************************************************************************************
string DiagnosticEngine::formatRawInput(string raw){
    // Routine to remove whitespace from raw user input and convert to all caps to match variables using regex.
    string temp;    // Temporary variable to hold rawInput string
    try {
        regex re(R"([A-Za-z,_]{1,16}(?!\S))", regex_constants::ECMAScript);
        smatch match_results;       // Holds matching results for regex. We only care about index 0.
        // If the rawInput contains a matching word
        if (regex_search(raw, match_results, re)){
            temp = match_results[0];    // Get the matching word
            for (int i = 0; i < temp.length(); i++){
                temp[i] = toupper(temp[i]);
            }
        }
        else
            cout << "Invalid input!\n";
        return temp;
    }catch (const regex_error& e){ cout << "regex_error caught: " << e.what() << " code: " << e.code() << '\n';}
    return 0;
}
//**********************************************************************************************************************
void DiagnosticEngine::getUserQuery(UserInterface &userInterface, string &rawInput, string &query){
/* Routine to get initial user input to begin the process of finding the answer the user needs*/
    //cout << "ENTER CONCLUSION (ISSUE_NO_START or ISSUE_START): ";
    //cin >> rawInput;
    //query = formatRawInput(rawInput);
    query = userInterface.promptUser(true, false);
    //cout << "Formatted Input is: " << query << endl;
}

//**********************************************************************************************************************
void DiagnosticEngine::instantiate( UserInterface &userInterface, KnowledgeBase &kB, string &q, string &mode)
/* Routine to initialize a variable (query) if it isn't already. If variable value is an empty string, then it has not
 * been initialized in the variable list held in the Knowledge Base. */
{
    int i = 0;

    string temp;
    /* find variable in the list */
    do
    {
        /*found variable and not already instantiated */
        if(q == kB.getVariableName(mode, i) && kB.getVariableValue(mode, i) == ""){
            // Prompt user for input and instantiate variables in KnowledgeBase at index location i.
            kB.setVariable(mode, userInterface.getUserInput(i),i);
        }
        i=i+1;
    }while((q != kB.getVariableName(mode, i-1) && i < kB.getVarListSize(mode)));
    // FOR TESTING PURPOSES
    //kB.displayVarList(mode);
}
//**********************************************************************************************************************
bool DiagnosticEngine::isRuleSatisfied(KnowledgeBase &kB, int &nextRuleNum, string &mode) {
/* Checks if a rule in the Knowledge Base has been satisfied. If yes, return true. */
    bool ruleSatisfied = false;
    bool clausesSatisfied[4] = {false, false, false, false};

    // NOTE: This has been written so that the conditions are retrieved from the Rule Base and not hard coded here,
    //  which is unlike the old version of this function.
    // Clause Variables populate the Variable List in KnowledgeBase according to the order in which they are first
    // encountered in the Rule Base when the Variable List table is initialized.
    // There is ONE clause variable per clause in the IF portion of statement.
    // NOTE -  Rule conclusions were adjusted to eliminate A > B, A <= B, etc. type formats because our auto diagnostic
    // program will not have conclusions like that. Our program conclusions will take the format "X = True" or
    // "X = False".

    for(int i = 0; i < kB.getRuleClauseMax(); i++) {
        // Check each clause in rule:
        clausesSatisfied[i] = isClauseSatisfied(kB, nextRuleNum, i, mode);
    }
    if (clausesSatisfied[0] && clausesSatisfied[1] && clausesSatisfied[2] && clausesSatisfied[3]){
        ruleSatisfied = true;
    }
    return ruleSatisfied;
}

//**********************************************************************************************************************
bool DiagnosticEngine::isClauseSatisfied(KnowledgeBase &kB, int ruleNum, int index, string &mode){
    int k = 0;
    bool clauseSatisfied = false;
    bool conVarSatisfied = false;

    if(kB.getRuleClause(mode, ruleNum, index) == ""){ // If there is no clause, then consider clause satisfied.
        clauseSatisfied = true;
        //cout << "No clause for ruleNum = " << ruleNum << " at location = " << index << endl;
    }
    else {
        do {
            //cout << "ruleNum in 'isClauseSatisfied() = " << ruleNum << endl;
            if(isClauseConclusion(kB, ruleNum, index, mode)){conVarSatisfied = true;}

            if (conVarSatisfied) {
                clauseSatisfied = true;
                //cout << "Conclusion variable in clause satisfied." << endl;
            }

            else if (kB.getRuleClause(mode, ruleNum, index) == (kB.getVariableName(mode, k) + " = " + kB.getVariableValue(mode, k))) {
                clauseSatisfied = true;
                //cout << "Clause satisfied." << endl;
            }
            //cout << "Clause variable at end of do-while in 'isClauseSatisfied()'..." << kB.getVariableName(k) << " = " << kB.getVariableValue(k) << endl;
            //cout << "at clause index k = " << k << endl;
            k++;
        } while (!clauseSatisfied && k < kB.getVarListSize(mode));
    }

    return clauseSatisfied;
}

//**********************************************************************************************************************
bool DiagnosticEngine::isClauseConclusion(KnowledgeBase &kB, int nextRuleNum, int index, string &mode){

    int j = 0;
    int otherRuleNum;
    bool conClauseSatisfied = false;
    bool otherRuleClausesSatisfied[4] = {false, false, false, false};

    do{// If the clause matches a conclusion statement
        if(kB.getRuleClause(mode, nextRuleNum, index) == (kB.getConclusion((j+1)*10))){
            // It is a conclusion variable. Get the Rule Number associated with that conclusion variable.
            otherRuleNum = kB.getConcRuleNum(j);
            //cout << "From isClauseConclusion... otherRuleNum = " << otherRuleNum << endl;
            // Check if the conditions for the conclusion variable have been met.
            for(int i = 0; i < kB.getRuleClauseMax(); i++) {
                otherRuleClausesSatisfied[i] = isClauseSatisfied(kB, otherRuleNum, i, mode);
            }
        }

        if(otherRuleClausesSatisfied[0] && otherRuleClausesSatisfied[1] && otherRuleClausesSatisfied[2] &&
           otherRuleClausesSatisfied[3]){
            conClauseSatisfied = true;
        }
        j++;
    }while(!conClauseSatisfied && j < kB.getConListSize());
    return conClauseSatisfied;
}
//**********************************************************************************************************************
void DiagnosticEngine::findConclusionRule(UserInterface &userInterface, bool &ruleSatisfied, KnowledgeBase &kB, string &query, string &conclusion, int &nextRuleNum,
                        int &clauseNum, int &clauseLoc, ConclusionStack &RuleStack, ConclusionStack &ClauseStack, string &mode) {

    int previousRule;
    /* While the query is a conclusion variable, push rules onto the stack. */
    kB.setStartIndex(0);    // Starting index is 0 for Knowledge Base data structures.
    nextRuleNum = kB.checkConList(query);
    //cout << "NextRuleNum in 'findConclusionRule()' is " << nextRuleNum << endl;
    if (nextRuleNum != 0) {        // if nextRuleNum != 0 then conclusion variable exists
        //cout << "Variable " << query << " is a Conclusion variable...";
        do
            /* push rule number and clause number on the associated part of conclusion stack.*/
        {
            //cout << "Pushing a new rule onto stack while looking for correct conclusion..." << endl;
            RuleStack.push(nextRuleNum);
            //cout << "Conclusion Var Rule# is " << nextRuleNum << " and clause# is " << clauseNum << endl;
            ClauseStack.push(clauseNum);

            do {
                processConclusionStack(userInterface, ruleSatisfied, kB, query, conclusion, nextRuleNum,
                                       clauseNum, clauseLoc, RuleStack, ClauseStack, mode);// do while the queried conclusion and empty string don't match.
            } while (query != "");

            /*no more clauses check if part of statement */
            // nextRuleNum gets the rule number at the top of Rule Stack
            nextRuleNum = RuleStack.getTopValue();
            //cout << "No more IF clauses found in Conclusion Var rule. nextRuleNum = " << nextRuleNum << endl;

            /* see if the then part should be invoked */
            //ruleSatisfied = isRuleSatisfied(kB, nextRuleNum, de, di, qu, gr, ex); << OLD RULE SET (DO NOT USE)
            //cout << "Checking if Conclusion Var Rule#" << nextRuleNum << "is satisfied..." << endl;
            ruleSatisfied = isRuleSatisfied(kB, nextRuleNum, mode);

            if (!ruleSatisfied) {
                /* failed..search rest of statements for same conclusion */
                //cout << "Conclusion Var Rule was not satisfied." << endl;
                /* get conclusion */
                clauseLoc = RuleStack.getTopValue();
                //cout << "Checking for other conclusions at clauseLoc/10-1 = " << clauseLoc/10-1 <<
                //" for " << query << endl;
                query = kB.getConLabel(clauseLoc / 10 - 1); // Retrieve the queried conclusion label.(Index starts at 0)
                /* search for conclusion starting at the next statement number */
                // Rule Number needs to be divided by 10 for Conclusion List index.
                kB.setStartIndex(RuleStack.getTopValue() / 10 + 1);
                //cout << "startIndex for conclusion label " << query << "has been set to " << clauseLoc/10 + 1 << endl;
                nextRuleNum = kB.checkConList(query);
                //cout << "nextRuleNum for "<< query << "is " << nextRuleNum << endl;
                /* pop old conclusion and put on new one, if applicable */
                RuleStack.pop(previousRule);
                //cout << "Old rule# "<< previousRule << "has been popped off the stack." << endl;
            }
        } while ((!ruleSatisfied) && (nextRuleNum != 0));

        if(nextRuleNum != 0){
            /* if part true invoke then part */
            /* then part of if-then statements from the position knowledge base */
            conclusion = getConclusion(nextRuleNum, kB, RuleStack, ClauseStack);
            //cout << "Conclusion is: " << conclusion << endl;

            if(RuleStack.isEmpty()) {
                /* finished */
                //cout << "*** SUCCESS ***\n";
                //kB.displayVarList(mode); // Display final state of variable list at end of program
            }
            else {
                //cout << "There are more rules on the stack. " << endl;
                int clauseIterator;
                /* stack is not empty */
                /* get next clause then continue */
                ClauseStack.pop(clauseIterator);
                //cout << "clause # was " << clauseIterator << endl;
                clauseIterator++;
                ClauseStack.push(clauseIterator);
                // cout << "clause # is now " << ClauseStack.getTopValue() << endl;
                processConclusionStack(userInterface, ruleSatisfied, kB, query, conclusion, nextRuleNum,clauseNum,
                                       clauseLoc, RuleStack, ClauseStack, mode);
            }
        }
    }
}

//**********************************************************************************************************************
void DiagnosticEngine::processConclusionStack(UserInterface &userInterface, bool &ruleSatisfied, KnowledgeBase &kB,
        string &query, string &conclusion, int &nextRuleNum, int &clauseNum, int &clauseLoc,ConclusionStack &RuleStack,
        ConclusionStack &ClauseStack, string &mode){

    /* While the query is a conclusion variable, push rules onto the stack. */
    // Calculate location of clause variable in clause variable list to avoid traversing entire vector.
    //cout << "RuleStack top value = " << RuleStack.getTopValue() << " ClauseStack top value = " << ClauseStack.getTopValue() << endl;
    clauseLoc = 5*((RuleStack.getTopValue()/10)-1) + ClauseStack.getTopValue();
    //cout << "clauseLoc value in 'processConclusionStack()' is " << clauseLoc << endl;
    /* clause variable */
    // Replaces user input query with current value of clause variable at clauseLoc in clause variable table
    query = kB.getClauseVariable(mode, clauseLoc-1);  // Index for variable table starts at 0.
    //cout << "Query is now: " << query << endl;

    if(query != "" || !query.empty()) { // Compare clause variable in query to empty string. If they don't match...
        /*is this clause variable a conclusion? */
        kB.setStartIndex(0);    // Starting index is 0 for Knowledge Base data structures.
        //int clauseIterator = 0;
        // check conclusion list for query
        nextRuleNum = kB.checkConList(query);
        if(nextRuleNum != 0) {
            //cout << "nextRuleNum in if = " << nextRuleNum << endl;
            /* If it matches then it is a conclusion, so push it */
            findConclusionRule(userInterface, ruleSatisfied, kB, query, conclusion, nextRuleNum, clauseNum,
                               clauseLoc, RuleStack, ClauseStack, mode);
        }
        else {/* check instantiation of this clause */
            //cout << "nextRuleNum in else = " << nextRuleNum << endl;
            instantiate(userInterface, kB, query, mode);
            //kB.displayVarList();  // TESTING
            int clauseIterator = 0;
            ClauseStack.pop(clauseIterator);
            //cout << "Popped clauseIteratorA after instantiation in 'processConclusionStack()': " << clauseIterator << endl;
            clauseIterator++;
            ClauseStack.push(clauseIterator);
        }
    }
}

//**********************************************************************************************************************
string DiagnosticEngine::getConclusion(int nextRuleNum, KnowledgeBase &kB, ConclusionStack &RuleStack, ConclusionStack &ClauseStack){
/* Fetches the correct conclusion for the satisfied rule, then pops both parts of the Conclusion Stack*/

    int previousRule;
    int previousClause;

    string conclusion = kB.getConclusion(nextRuleNum);

    cout << conclusion <<"\n";

    /* pop both the RuleStack and ClauseStack */
    RuleStack.pop(previousRule);
    ClauseStack.pop(previousClause);
    //cout << "Conclusion acquired. Previous Rule# is " << previousRule << " and previous clause # is "<< previousClause << endl;


    return conclusion;
}
