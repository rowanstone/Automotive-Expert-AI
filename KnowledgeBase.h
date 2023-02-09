// This is the KnowledgeBase class for the Automotive Expert System, which holds all of the rules to be used in the
// program. So far only the diagnostic rules at this time.

#ifndef AUTOMOTIVE_EXPERT_KNOWLEDGEBASE_H
#define AUTOMOTIVE_EXPERT_KNOWLEDGEBASE_H

#include<iostream>
#include<vector>
#include <regex>

using namespace std;

// Knowledge Base Class Declaration

class KnowledgeBase {
public:
    static const int CLAUSE_MAX = 4;

    struct variable {
        string name;    // Name of variable (applies to conclusion variables as well)
        string value;   // Value of variable (applies to conclusion variables as well)
    };
    struct rule {
        //static const int CLAUSE_MAX = 4;
        int ruleNum;                    // Rule number
        string clause[CLAUSE_MAX];      // IF clause array
        string conclusion;              // Conclusion of the rule
    };

    struct clauseEntry {
        int clauseNum;      // Clause Variable number
        string clauseVar;   // Clause Variable
    };
    struct conVar {
        int ruleNum;        // Number of associated rule for conclusion
        string label;       // Conclusion label
        string statement;   // Conclusion statement
    };

private:

    int startIndex = 0;         // Holds starting index value to check lists in order to avoid going over
    // same conclusion (DIAGS) or Clause Variable List item (REPAIR) twice. (f in Backward_Chaining_Program.cpp)

    vector<rule> diagRules;                     // Empty diagnostic rule base
    vector<rule> repairRules;                   // Empty repair rule base
    vector<variable> diagVarList;               // Empty diagnostic Variable List
    vector<variable> repairVarList;             // Empty repair Variable list
    vector<conVar> conList;                     // Empty DIAGNOSTIC Conclusion List
    vector<clauseEntry> diagClauseVarList;      // Empty diagnostic Clause Variable List
    vector<clauseEntry> repairClauseVarList;    // Empty repair Clause Variable List

    void initRepairRules();
    void initDiagRules();
    void initVarList(vector<rule> &, vector<variable> &);
    void initConList(vector<rule> &);     // DIAG ONLY
    void initClauseVarList(vector<rule> &, vector<clauseEntry> &);
    void checkDuplicatesVarList(vector<variable> &, smatch &, variable &);
    void pushVariable(vector<variable> &, smatch &, variable &);

public:


    //KnowledgeBase();                                      // Constructor
    //~KnowledgeBase();                                     // Destructor
    void initKB();
    //bool initCheck( const string &);               // Public member function that calls private member function
    //void initVar(string);
    void setVariable(string &, string, int);      // Set User answer for entry in Variable List.
    void setStartIndex(int);                                // Set the starting index for list search.
    int getStartIndex();                                    // return current value of StartIndex.
    int checkConList(string &);                             // Check Conclusion List for requested variable entered by user. DIAG ONLY
    int getConcRuleNum(int);                                // Get Rule Number for Conclusion Stack in Main() associated with requested DIAG ONLY
    // conclusion variable given by user, if it exists in Conclusion List.
    int deriveRuleNum(int);                                 // Computer Rule number from Clause number (REPAIR ONLY)

    string getClauseVariable(string &, int);   // Get Clause Variable from entry in Variable List based on index location
    string getConclusion(int);                              // Get value of Conclusion from Conclusion list based on Rule/Statement Number
    string getConLabel(int);                                // Get label of conclusion from Conclusion List at index location
    string getVariableName(string &, int);        // Get variable name at index location from varList
    string getVariableValue(string &, int);       // Get value of variable at index location from varList
    string getRuleClause(string &, int, int);         // Get  rule clause
    int getRuleNum(string &, int);
    string getRuleConclusion(string &, int);

    int getClauseVarNumber(variable &);
    int getClauseVarListSize(string &);         // Returns the size of the Clause Variable List.

//    const vector<rule> getDiagRules();
//    const vector<rule> getRepairRules();
//    const vector<variable> getDiagVarList();
   const vector<variable> getRepairVarList();
//    const vector<clauseEntry> getDiagClauseVarList();
//    const vector<clauseEntry> getRepairClauseVarList();

    int getVarListSize(string &);                 // Returns size of the variable list
    int getRuleBaseSize(string &);
    int getConListSize();                                   // Returns the size of the Conclusion List
    const int getRuleClauseMax();                           // Returns the Max number of clauses a rule can have
    void displayRuleBase(string);                   // Display the Rule Base
    void displayConList();                                  // Display the Conclusion List
    void displayVarList(string);                // Displays the current contents of the Variable List
    void displayClauseVarList(string);       // Displays the Clause Variable List

};

#endif //AUTOMOTIVE_EXPERT_KNOWLEDGEBASE_H
