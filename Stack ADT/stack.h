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
    node* top; //points to first element in stack

public:
    stack() { //constructor
        top = nullptr;
    }
    
    //returns value at front of list
    char Top() {
        return  top->data;
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
    
    //deletes value at front of list
    void pop() {
        node* temp = new node;
        temp = top; //equal to first val
        top = top->next;
        delete temp;
    }
    
    bool isEmpty() {
        return top;
    }
    
    void print() {
        node* cu = top;
        
        while(cu!=nullptr) {
            cout << cu->data;
            cu = cu->next;
        }
    }
    
    //checks if charcter in string is digit
    bool isOperand(char o) {
        if( o == '0' || o == '1' ||o == '2'|| o == '3'|| o == '4'|| o == '5'|| o == '6'|| o == '7'|| o == '8'|| o == '9') {
            return true;
        }
        else {
            return false;
        }
    }
    
    //checks precedence for operators
    int Hprecedence(char o) {
        //if op is mult/div, has higher precedence
        if( o == '*' || o == '/' ) {
            return 2;
        }
        if ( o == '+' || o == '-') {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    
    
    void infixTprefix(stack p, stack &o, stack &st) {
        //new node created set equal to top node
        node* t = p.top;
        
        //scanning
        while(t!=nullptr) {
            //if it is a digit -- push to output
            if (isOperand(t->data)) {
                o.push(t->data);
            }
            //if it is NOT digit
            if (!isOperand(t->data)){
                //if stack is empty, push to stack
                if(!st.isEmpty()) {
                    st.push(t->data);
                }
                //if operator has a higher precedence, push to stack
                //compare operator to stack's top operator
                if ( Hprecedence(t->data) > Hprecedence(st.Top()) ) {
                    st.push(t->data);
                }
                if ( Hprecedence(t->data) < Hprecedence(st.Top())) {
                    //push operator at top of stack to output
                    o.push(st.Top());
                    //pop operator
                    st.pop();
                    //push to stack
                    st.push(t->data);
                }
            }
            t = t->next;
        }
    }
};

#endif /* stack_h */
