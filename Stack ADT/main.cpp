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
    
    stack first;
    first.push("g");
    first.push("o");
    first.push("d");
    
    first.print();
    cout << endl;
    
    
    
    return 0;
}
