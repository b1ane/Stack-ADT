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
#include <cstring>



int main() {
    // insert code here...
    //take in infix-notation equation as string  input
    
    string input;
    cin >> input;
    
    stack prefix;
    stack output;
    
    //loops through entire equation, pushes all values to prefix stack
    for( int i  = 0; i < input.length(); i++) {
        prefix.push(input[i]);
    }
    
    stack st;
    output.infixTprefix(prefix,output,st);
    cout << "PREFIX: ";
    output.print();
    cout << endl;
    
    stack post;
    
    cout << post.infixTpost(input) << endl;
    
    return 0;
}
