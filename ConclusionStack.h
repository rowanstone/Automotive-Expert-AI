// This is the specification for the ConclusionStack class, which is a dynamic stack built off a linked list structure.
// Created by Rowan on 23.09.2019.
//

#ifndef AUTOMOTIVE_EXPERT_CONCLUSIONSTACK_H
#define AUTOMOTIVE_EXPERT_CONCLUSIONSTACK_H

class ConclusionStack{
private:
    // Struct to define a node on the stack.
    struct StackNode {
        int value;          // Value of either the rule number or the relative clause number, depending on the stack.
        StackNode *next;    // Pointer to the next StackNode
    };

    StackNode *top;         // Pointer to the top of the stack.

public:
    // Constructor
    ConclusionStack(){ top = nullptr;}
    // Destructor
    ~ConclusionStack();
    // Stack operations
    void push(int);
    void pop(int &);
    bool isEmpty();
    int getTopValue();
};

#endif //AUTOMOTIVE_EXPERT_CONCLUSIONSTACK_H
