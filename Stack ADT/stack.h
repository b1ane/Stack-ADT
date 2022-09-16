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
    char data;
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
        cout<< tp->data << endl;
    }
    
    
    //insert value at front of list;
    void push(char val) {
        //new node is create, stores value passed as parameter
        node* newNode = new node;
        newNode->data = val;
        //top is to value passed
        newNode->next = tp;
        tp = newNode;
    }
    
    //deletes value at front of list
    void pop() {
        node* temp = new node;
        temp = tp; //equal to first val
        tp = tp->next;
        delete temp;
    }
    
    void print() {
        node* cu = tp;
        
        while(cu!=nullptr) {
            cout << cu->data;
            cu = cu->next;
        }
    }
    
    
    
    
    
    
};

#endif /* stack_h */
