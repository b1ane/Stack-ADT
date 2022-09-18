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



int main() {
    // insert code here...
    //take in infix-notation equation as string  input
    
    string input;
    getline(cin, input);
    
    stack prefix;
    stack output;
    
    //loops through entire equation, pushes all values to prefix stack
    for( int i  = 0; i < input.size(); i++) {
        prefix.push(input.at(i));
    }
    
    prefix.print(); //outputs entire prefix equation
    cout << endl;
    
    stack st;
    
    output.infixTprefix(prefix,output,st);
    output.print();
    cout << endl;
    st.print();
    cout << endl;
    
    
    
    return 0;
}
