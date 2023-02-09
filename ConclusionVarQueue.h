//
// Created by Rowan on 07.10.2019.
//

#ifndef AUTOMOTIVE_EXPERT_CONCLUSIONVARQUEUE_H
#define AUTOMOTIVE_EXPERT_CONCLUSIONVARQUEUE_H
#include<iostream>
#include<vector>

#include "KnowledgeBase.h"
//#include "Structs.h"

using namespace std;
class ConclusionVarQueue
{

private:
    // Structure for each node of dynamic queue
    struct Node
    {
        KnowledgeBase::variable var;   // Variable held in node
        Node *next; // Pointer to the next node in queue
    };

    Node *front;    // fp        // The front of the queue
    Node *rear;     // bp       // The rear of the queue
    int numItems;   // Number of items in the queue

    vector<KnowledgeBase::variable> varQueue;  //WILL BE THE VARIABLE INPUTTED FOR QUEUE
    vector<KnowledgeBase::rule> ruleHolder;    //COPIES THE RULES FROM KNOWLEDGE BASE FOR USE
    vector<KnowledgeBase::variable> varHolder;   //COPIES VARIABLES FROM KNOWLEDGE BASE FOR USE
    vector<KnowledgeBase::variable> result; //STORES ALL THE DATA FOR THE CLAUSES TO GET CONCLUSION

public:
    // Constructor
    ConclusionVarQueue();
    // Destructor
    ~ConclusionVarQueue();
    // Queue operations
    void enqueue(KnowledgeBase::variable);
    void dequeue(KnowledgeBase::variable &);
    bool isEmpty() const;
    void clear();
    void printQueue();
    KnowledgeBase::variable getFrontItem();
};



#endif //AUTOMOTIVE_EXPERT_CONCLUSIONVARQUEUE_H
