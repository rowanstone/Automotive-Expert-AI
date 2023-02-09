// This is the implementation file for the ConclusionStack class, which is a dynamic stack built off a linked list
// structure.
// Created by Rowan on 23.09.2019.
//
#include<iostream>
#include "ConclusionStack.h"
using namespace std;

//**********************************************************************************************************************
// Destructor function - deletes every node in the stack when it is no longer being used.
//**********************************************************************************************************************
ConclusionStack::~ConclusionStack() {
    StackNode *nodePtr = nullptr;
    StackNode *nextNode = nullptr;
    // Set nodePtr at the top of the stack.
    nodePtr = top;
    // Go through the stack list and delete each node
    while (nodePtr != nullptr){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
//**********************************************************************************************************************
// isEmpty function will check if the stack is empty and return a boolean value
//**********************************************************************************************************************
bool ConclusionStack::isEmpty(){
    bool empty;
    if (!top)
        empty = true;
    else
        empty = false;
    return empty;
}
//**********************************************************************************************************************
// Push function will push an entry onto the top of the stack
//**********************************************************************************************************************
void ConclusionStack::push(int num) {
    StackNode *newNode = nullptr;   // Points to a new node
    // Allocate a new node and store an entry there
    newNode = new StackNode;
    newNode->value = num;

    // If there are no nodes in the list, then make a new node at the top of the stack
    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }
        // If the stack is not empty, place a new node entry before top.
    else{
        newNode->next = top;
        top = newNode;
    }

}

//**********************************************************************************************************************
// Pop function will pop an entry off of the top of the stack and will copy it into a variable
//**********************************************************************************************************************
void ConclusionStack::pop(int &var) {
    StackNode *temp = nullptr;

    // Check that stack isn't empty before attempting to pop.
    if(isEmpty()){
        cout << "The stack is empty! \n";
    }
        // If the stack is not empty, proceed with pop operation
    else{
        var = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

//**********************************************************************************************************************
// getTopValue function will return the value held at the top position of the stack without popping it.
//**********************************************************************************************************************
int ConclusionStack::getTopValue() {
    return top->value;
}


