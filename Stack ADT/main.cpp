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

//checks if charcter in string is digit
bool isOperand(char o) {
    if( o == '0' || o == '1' ||o == '2'|| o == '3'|| o == '4'|| o == '5'|| o == '6'|| o == '7'|| o == '8'|| o == '9') {
        return true;
    }
    else {
        return false;
    }
}



int main() {
    // insert code here...
    //take in infix-notation equation as string  input
    
    string input;
    getline(cin, input);
    
    stack digits; //holds operands
    stack ops;    //holds operators
    
    
    //loops through entire equation
    for( int i  = 0; i < input.size(); i++) {
        //if value in string is a number -- push to digits
        if( input.at(i) == '0' || input.at(i) == '1' ||input.at(i) == '2'||input.at(i) == '3'||input.at(i) == '4'||input.at(i) == '5'||input.at(i) == '6'||input.at(i) == '7'||input.at(i) == '8'||input.at(i) == '9') {
            digits.push(input.at(i));
        }
        else { //push to ops
            ops.push(input.at(i));
        }
    }
     
    
    
    digits.print();
    cout << endl;
    
    ops.print();
    cout << endl;

    
    
    
    return 0;
}
