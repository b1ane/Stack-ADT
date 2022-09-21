//
//  main.cpp
//  Stack ADT
//
//  Created by blane on 9/14/22.
//

#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include "stack.h"
#include <vector>
#include "nStack.h"


//checks if charcter in string is digit
bool isOperand(char o) {
    if( o == '0' || o == '1' ||o == '2'|| o == '3'|| o == '4'|| o == '5'|| o == '6'|| o == '7'|| o == '8'|| o == '9') {
        return true;
    }
    else {
        return false;
    }
}

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

string infixTpost(string inp) {
    string output="";
    stack o;
    stack st;
    
    for(int i = 0; i < inp.length(); i++) {
        //if a digit - insert digit to stack object (at front)
        if(isOperand(inp[i])) {
            output+=(inp[i]);
        }
        else {
            //if stack is empty - push operator to stack
            if(st.isEmpty()) {
                st.push(inp[i]);
            }
            else {
                while(!st.isEmpty() && (Hprecedence(inp[i]) <= Hprecedence(st.Top()))) {
                    output+=(st.Top());
                    st.pop();
                }
                st.push(inp[i]);
            }
            
        }
    }
    
    while(!st.isEmpty()) {
        output+=(st.Top());
        st.pop();
    }

    return output;
}

string infixTprefix(string inp) {
    string newString="";
    string output ="";
    stack st;
    stack o;
    //scanning
    //reverses string then places in output string
    stack on;
    for( int i = 0; i < inp.length(); i++) {
        on.push(inp[i]);
        //newString+=on.Top();
    }
    
    while(!on.isEmpty()) {
        newString+=on.Top();
        on.pop();
    }
    
    //evaluating string
    for( int i = 0; i < newString.length(); i++ ) {
        //push to output if it is a digit -- reverses the equation
        if (isOperand(newString[i])) {
            output+=newString[i];
        }
        else {
            //if the stack is empty -- push operator to stack
            if(st.isEmpty()) {
                st.push(newString[i]);
            }
            else {
                if(Hprecedence(newString[i]) >= Hprecedence(st.Top())) {
                    st.push(newString[i]);
                }
                //has lower precedence than operator on top of stack
                if(Hprecedence(newString[i]) < Hprecedence(st.Top())) {
                    //until stack is empty
                    //or until operator on top of stack is lower than character passed
                    while(!st.isEmpty() && Hprecedence(st.Top()) > Hprecedence(newString[i])) {
                        output+=st.Top();
                        //o.push(st.Top());
                        st.pop();
                    }
                    st.push(newString[i]);
                }
            }
        }
    }
    //push rest of stack to output
    while(!st.isEmpty()){
        output+=st.Top();
        //o.push(st.Top());
        st.pop();
    }
    
    string revO;
    stack x;
    for( int i = 0; i < output.length(); i++ ){
        x.push(output[i]);
    }
    while(!x.isEmpty()) {
        revO+=x.Top();
        x.pop();
    }
    
    
    return revO;
}

int op(int a, int b, char o) {
    int result = 0;
    
    switch (o){
          case '+':
            result = (a + b);
            break;
          case '-':
            result = a - b;
            break;
          case '*':
            result = a * b;
            break;
       }
    
    return result;
    
}



int eval(string post) {
    nStack st; //stack of ints
    
    for( int i = 0; i < post.length(); i++ ) {
        if (isOperand(post[i])) {
            int num = post[i] - '0';
            st.push(num);
        }
        if (!isOperand(post[i])) {
            int a = st.Top();
            st.pop();
            cout << a << endl;
            int b = st.Top();
            cout << b << endl;
            st.pop();
            int x = op(a, b, post[i]);
            st.push(x);
        }
    }
    
    return st.Top();
}




int main() {
    // insert code here...
    //take in infix-notation equation as string  input
    /*
    string input;
    cin >> input;

    cout << "PREFIX AS STRING: ";
    cout << infixTprefix(input) << endl;
    
    cout << "POSTFIX AS STRING: ";
    cout << infixTpost(input) << endl;
    
    string x = infixTprefix(input);
    */
    
    cout << "POSTFIX EVAL: ";
    cout << eval("234*+") << endl;
    
    
    
    return 0;
}
