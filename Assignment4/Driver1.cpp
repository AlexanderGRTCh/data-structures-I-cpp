#include <iostream>
#include <ctime>
using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-10-24
*/

/*
* Generates a string of 16 random upper and 
* lower case characters and prints out that string. 
* Then organizes the string so that all the lower case letters 
* come before the upper case letter and 
* then print out the modified string.
*/

//Generate a string of 16 random upper and lower case characters and print it
void genStr(string & s){
    for(int i = 0; i < 16; i++){
        if(rand()%2 == 1){
            s += (char)(rand()%26 + 97);
        }
        else{
            s+= (char)(rand()%26 + 65);
        }
    }
    cout << s << endl;
}

// Organize string so all the lower case letters come before the upper case letters and
// print out the modified string
void lowerToUpper(string & s){
    string lowerC = "";
    string upperC = "";
    for(unsigned i = 0; i < s.size(); i++){
        if(97 <= (int)s[i] && (int)s[i] <=122){
            lowerC += s[i];
        }else{
            upperC += s[i];
        }
    }
    s = lowerC + upperC;
    cout << s << endl;
}


int main(){

    srand(time(0));
    string s = "";
    genStr(s);
    lowerToUpper(s);
    return 0;
}
