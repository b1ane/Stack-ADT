//
//  stack.h
//  Stack ADT
//
//  Created by blane on 9/14/22.
//

#ifndef stack_h
#define stack_h
#include <iostream>
#include <string>
using namespace std;

struct node {
    char inp;
    node* next;
};

class stack {
private:
    node* tp; //points to first element in stack

public:
    stack() { //constructor
        tp = nullptr;
    }
    
    //returns value at front of list
    void top() {
        cout<< tp->inp << endl;
    }
    
    
    //insert value at front of list;
    void push(char val) {
        //new node is create, stores value passed as parameter
        node* newNode = new node;
        newNode->inp = val;
        //top is to value passed
        newNode->next = tp;
        tp = newNode;
    }
    
    void print() {
        node* cu = tp;
        
        while(cu!=nullptr) {
            cout << cu->inp;
            cu = cu->next;
        }
    }
    
    
    
    
    
    
};

#endif /* stack_h */
