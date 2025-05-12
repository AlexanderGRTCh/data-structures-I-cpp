#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
* @Author Alexander Kemos
* @Version 1.0
* @since 2022-09-20
*/

/*Check if character ch is in the vector c
* if ch is in the vector increase the count by num
* if it isn't add it to the end of the vectors c and n.
*/
void check(vector<char> & c, vector<unsigned> & n, char ch, int num){

    if(c.empty()){
                c.push_back(ch);
                n.push_back(num);
    }
    else{
        bool matches = false;
        for (unsigned i = 0; i < c.size(); i++){
            if (c[i] == ch){
                n[i] += num; 
                matches = true;
                break;
            }
        }
        if (matches == false){
            c.push_back(ch);
            n.push_back(num);
        }
    }
}

//Print data in vectors in format "ch : count"
void print_input(vector<char> & c, vector<unsigned> & n){

    for(int i = 0; i < c.size(); i++){
        cout << c[i];
        cout << " : " << n[i] << endl;
    }
}

//Read input data and use check function to add to the vectors
void get_vector(string & name, vector<char> & c, vector<unsigned> & n){

    ifstream iFile;
    char ch;
    string numStr;
    int num;

    iFile.open("test1.txt");
    if( iFile.is_open()){
        while(getline(iFile, name)){
            ch = name[0];
            for (int j = 2; j < name.length(); j++){
                numStr.push_back(name[j]);
            }
            num = stoi(numStr);
            check(c, n, ch, num);
            numStr = "";
        }
    iFile.close();
    }
    else{
        cout << "Failed to open file." << endl;
    }
}

/*Find the longest ascending subsequence in the num vector
* and store begining of the sequence in start and len of the sequence in len
*/
void longest_asc_sub(const vector<unsigned> & n, int & start, int & len){
    start = 0;
    len = 0;
    int tempLen = 1;

    for(unsigned i = 1; i < n.size(); ++i){
        if(n[i] > n[i-1]){
            tempLen += 1;
            if(len < tempLen){
                len = tempLen;
                start = i - len + 1;
            }
        }
        else{
             tempLen = 1;
        }
    }
}

//print out the sub elements in the vector starting at star end end at start+len
void print_subset(const vector<char> & c, int start, int len){
    for(unsigned i = start; i < start + len; i++){
        cout << c[i] << " ";
    }
}

int main(){
    
    int start, len;
    string name;
    vector<char> c;
    vector<unsigned> n;

    get_vector(name, c, n);
    print_input(c, n);
    longest_asc_sub(n, start, len);
    print_subset(c, start, len);

    return 0;
}
