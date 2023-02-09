//
// Created by Rowan on 07.10.2019.
//
#include<iostream>
#include<algorithm>
#include<vector>

#include "ConclusionVarQueue.h"
#include "KnowledgeBase.h"

using namespace std;

//**********************************************************************************************************************
// The constructor of ConclusionVarQueue creates an empty queue.
//**********************************************************************************************************************
ConclusionVarQueue::ConclusionVarQueue(){
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

//**********************************************************************************************************************
// Destructor
//**********************************************************************************************************************
ConclusionVarQueue::~ConclusionVarQueue(){
    clear();
}

//**********************************************************************************************************************
// Enqueue inserts a variable at the rear of the queue
//**********************************************************************************************************************
void ConclusionVarQueue::enqueue(KnowledgeBase::variable var) {
    Node *newNode = nullptr;
    // Create a new node and store var there.
    newNode = new Node;
    newNode->var = var;
    newNode->next = nullptr;

    // Adjust the front and rear as needed
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    // Update number of items in queue
    numItems++;
}

//**********************************************************************************************************************
// Dequeue removes the variable at the front of the queue and copies it into var.
//**********************************************************************************************************************
void ConclusionVarQueue::dequeue(KnowledgeBase::variable &var) {
    Node *temp = nullptr;
    // Adjust the front and rear as needed
    if(isEmpty()){
        cout << "The conclusion variable queue is empty" << "\n";
    }
    else{
        // Save the front node variable in var
        var = front->var;
        // Remove the front node and delete it
        temp = front;
        front = front->next;
        delete temp;
        // Update number of items in queue
        numItems--;
    }
}

//**********************************************************************************************************************
// isEmpty returns true if the queue is empty, otherwise it returns false.
//**********************************************************************************************************************
bool ConclusionVarQueue::isEmpty() const {
    bool status;

    if(numItems > 0)
        status = false;
    else
        status = true;
    return status;
}

//**********************************************************************************************************************
// clear dequeues all of the variables in the queue.
//**********************************************************************************************************************
void ConclusionVarQueue::clear(){
    KnowledgeBase::variable var;
    while(!isEmpty())
        dequeue(var);
}

//**********************************************************************************************************************
// clear dequeues all of the variables in the queue.
//**********************************************************************************************************************
void ConclusionVarQueue::printQueue(){
    Node *temp = nullptr;
    if(isEmpty())
        cout << "Nothing to print. The queue is empty." << endl;
    else{
        cout << "*** Conclusion Variable Queue ***" << endl;
        temp = front;
        for(int i = 0; i < numItems; i++){
            cout << temp->var.name << "\t" << temp->var.value << endl;
            temp = temp->next;
        }
    }
}

//**********************************************************************************************************************
// getFrontItem returns the variable at the front of the queue
//**********************************************************************************************************************
KnowledgeBase::variable ConclusionVarQueue::getFrontItem(){
    return front->var;
}
