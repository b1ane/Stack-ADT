//
//  nStack.h
//  Stack ADT
//
//  Created by blane on 9/21/22.
//

#ifndef nStack_h
#define nStack_h
#include <iostream>
#include <string>
using namespace std;

struct nNode {
    int data;
    nNode* next;
};

class nStack {
private:
    nNode* top;
public:
    nStack() {
        top = nullptr;
    }
    
    int Top() {
        //if list is not empty -- return value on top
        if (!isEmpty()) {
            return top->data;
        }
        else {
            return 0;
        }
    }
    
    void push(int val) {
        nNode* newNode = new nNode;
        newNode->data = val;
        if (isEmpty()) {
            newNode->next = nullptr;
        }
        else {
            newNode->next = top;
        }
        top = newNode;
    }
    
    void pop() {
        if (!isEmpty()) {
            nNode* temp = new nNode;
            temp = top;
            top=top->next;
            delete temp;
        }
    }
    
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void print() {
        nNode* cu = top;
        
        while(cu!=nullptr) {
            cout << cu->data;
            cu = cu->next;
        }
    }
    
};


#endif /* nStack_h */
