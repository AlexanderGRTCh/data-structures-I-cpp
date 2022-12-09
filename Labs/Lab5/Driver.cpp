#include <iostream>
#include "stack.h"
using namespace std;
/*
reverse polish notation 
//cases of invalid equation
//positive signle integers
// stack should hold doubles
//ss.pushstack make sure minusing zero*/


int main(){

    stack3<double> s;
    double num;
    string input;
    cout << "Enter an equation: " <<endl;
    cin >> input;
    //Invalid cases;
    //Regular cases
    for(char i : input){
        if( i == '*' || i == '+' || i == '-' || i == '/'){ 

            double pop1, pop2;
            pop1 = s.pop();
            //No number to perform operation
            if(s.isEmpty()){
                cout << "Invalid equation" << endl;
                exit(1);
            }
            pop2 = s.pop();

            //If we have 2 numbers to perform operation
            switch(i){
                case '+':
                    //cout << "plus activated" << endl;
                    num = pop2 + pop1;
                    s.push(num);
                    break;
                case '-':
                    //cout << "minus activated" << endl;
                    num = pop2 - pop1;
                    s.push(num);
                    break;
                case '*':
                    //cout << "multiplication activated" << endl;
                    num = pop2 * pop1;
                    s.push(num);
                    break;
                case '/':
                    //cout << "division activated" << endl;
                    if(pop1 == 0){
                        cout << "div by 0 error" << endl;
                        exit(1);
                    }
                    num = pop2 / pop1;
                    s.push(num);
                    break;
            }
        }else{
            s.push(i-'0');
        }
    }
    double result = s.pop();
    if(!s.isEmpty()){
        cout << "Invalid Equation" << endl;
        exit(1);
    }

    cout << "Solution " << result << endl;



    return 0;
}
