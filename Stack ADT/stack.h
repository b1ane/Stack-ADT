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
    int digi;
    char data;
    node* next;
};

class stack {
private:
    node* top; //points to first element in stack
    node* itop;

public:
    stack() { //constructor
        top = nullptr;
        itop = nullptr;
    }
    
    //returns value at front of list
    char Top() {
        return  top->data;
    }
    
    int iTop() {
        return itop->digi;
    }
    
    
    //insert value at front of list;
    void push(char val) {
        //new node is create, stores value passed as parameter
        node* newNode = new node;
        newNode->data = val;
        //top is to value passed
        newNode->next = top;
        top = newNode;
    }
    
    void iPush(int num) {
        node* newNode = new node;
        newNode->digi = num;
        newNode ->next = itop;
        itop = newNode;
    }
    
    //insert value at back
    void insert(char val) {
        node* newNode = new node;
        newNode->data = val;
        newNode -> next = nullptr;
        if(isEmpty()) {
              top = newNode;
            }
            else {
              // loop until last node is reached, add new node there
              node* cur = top; //cur stores value of head

              // loop until last node is reached
              while( cur->next != nullptr) {
                cur = cur -> next;
              }
              cur->next = newNode;
            }
    }
    
    //deletes value at front of list
    void pop() {
        node* temp = new node;
        temp = top; //equal to first val
        top = top->next;
        delete temp;
    }
    
    void iPop() {
        node* temp = new node;
        temp = itop;
        itop = itop->next;
        delete temp;
    }
    
    //returns true if stack is empty
    bool isEmpty() {
        if(top==nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void print() {
        node* cu = top;
        
        while(cu!=nullptr) {
            cout << cu->data;
            cu = cu->next;
        }
    }
    
    void iPrint() {
        node* cu = itop;
        while (cu!=nullptr) {
            cout << cu->digi;
            cu = cu->next;
        }
    }
    
};

#endif /* stack_h */
