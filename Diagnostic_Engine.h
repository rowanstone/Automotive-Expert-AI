// This is the specification file for the backward-chaining Diagnostic Engine
// Created by Rowan on 05.10.2019.
//
#ifndef AUTOMOTIVE_EXPERT_DIAGNOSTIC_ENGINE_H
#define AUTOMOTIVE_EXPERT_DIAGNOSTIC_ENGINE_H
#include <string>
#include "UserInterface.h"
#include "KnowledgeBase.h"
#include "ConclusionStack.h"
using namespace std;

class DiagnosticEngine{
private:
    void instantiate(UserInterface &, KnowledgeBase &, string &, string &);
    void getUserQuery(UserInterface &,string &, string &);
    string formatRawInput(string);

    bool isRuleSatisfied(KnowledgeBase &, int &, string &); /*, string &, string &, string &, float &, float &);*/
    bool isClauseConclusion(KnowledgeBase &, int, int, string &);      // Checks if an IF clause is also a conclusion statement.
    bool isClauseSatisfied(KnowledgeBase &, int, int, string &);       // Checks if an IF clause is satisfied.

    void processConclusionStack(UserInterface &, bool &, KnowledgeBase &, string &, string &, int &, int &, int &,
            ConclusionStack &, ConclusionStack &, string &);

    void findConclusionRule(UserInterface &, bool &, KnowledgeBase &, string &, string &, int &, int &, int &,
            ConclusionStack &, ConclusionStack &, string &);

    string getConclusion(int, KnowledgeBase &, ConclusionStack &, ConclusionStack &);

public:
    string runDiagnostic(UserInterface &, KnowledgeBase &, string &);
};

#endif //AUTOMOTIVE_EXPERT_DIAGNOSTIC_ENGINE_H
