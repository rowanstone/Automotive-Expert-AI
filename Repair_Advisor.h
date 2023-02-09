// This is the RepairAdvisor class definition file for the Automotive Expert System. This class object and it's member
// functions utilize forward-chaining methodology to provide the user with relevant repair suggestions.
// Created by Rowan on 07.10.2019.
//

#ifndef AUTOMOTIVE_EXPERT_REPAIR_ADVISOR_H
#define AUTOMOTIVE_EXPERT_REPAIR_ADVISOR_H

#include <string>
#include <iostream>
#include <vector>
#include "UserInterface.h"
#include "KnowledgeBase.h"
#include "ConclusionVarQueue.h"

using namespace std;

class RepairAdvisor{
private:
    //vector<KnowledgeBase::variable> varQueue;  //WILL BE THE VARIABLE INPUTTED FOR QUEUE
    //vector<KnowledgeBase::rule> ruleHolder;    //COPIES THE RULES FROM KNOWLEDGE BASE FOR USE
    //vector<KnowledgeBase::variable> varHolder;   //COPIES VARIABLES FROM KNOWLEDGE BASE FOR USE
    //vector<KnowledgeBase::variable> result; //STORES ALL THE DATA FOR THE CLAUSES TO GET CONCLUSION
    /*
    void enqueue(KnowledgeBase::variable var);
    void dequeue();
    void queueCheck();
    int getRuleNumber(KnowledgeBase::variable var);
    void addClauseVar(int Num);
    bool initCheck(KnowledgeBase::variable var);
    bool duplicateCheck(KnowledgeBase::variable var);
    int getConclusionInt();
    void getConclusion(int ruleNum);
    KnowledgeBase::variable queueInitCheck(KnowledgeBase::variable var);
    void print();
    */
    void inputData(UserInterface &, ConclusionVarQueue &, KnowledgeBase &, string &, string &);
    string processQueue(UserInterface &, ConclusionVarQueue &, KnowledgeBase &, int *, string &, string &, bool &);
    KnowledgeBase::variable searchConVarList(UserInterface &, ConclusionVarQueue &, KnowledgeBase &, int *, string &, string &, bool &);
    bool checkRuleClauses(UserInterface &, ConclusionVarQueue &, KnowledgeBase &, int *, string &, string &, bool &);
    void extractConVar(ConclusionVarQueue &, KnowledgeBase &, int *, string &, string &, bool &);
    bool initCheck(UserInterface &, KnowledgeBase &, string &, const string &);
    void initVar(UserInterface &, KnowledgeBase &, string &, const string);

public:
    string runRepairAdvisor(UserInterface &, KnowledgeBase &, string &, string);
};

#endif //AUTOMOTIVE_EXPERT_REPAIR_ADVISOR_H
