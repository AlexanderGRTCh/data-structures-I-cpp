#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-10-24
*/

/*
* Generates two vectors of 8 random ints. 
* The first vector in ascending order and the second in descending order and prints vectors.
* Then combines the two vectors to create a new vector that contains 
* the values of the other two vectors in non-descending order and prints it.
*/

// Generate vectors of 8 random ints in decenting order
void genAscV(vector<int> & a){
    for(int i = 0; i < 8; i++){
        a.push_back(i*10 + (rand()%10+1));
    }
}
// Generate vectors of 8 random integers in decenting order
void genDecV(vector<int> & d){
    for(int i = 8; i > 0; i--){
        d.push_back(i*10 - (rand()%10+30));
    }
}

// Merge two vectors
vector<int> merge(vector<int> & v, const vector<int> & left, const vector<int> & right){
  vector<int> temp;

    unsigned l = 0;
    unsigned r = 0;
    // While in bounds
    while(r < right.size() && l < left.size()){
        // If value from left vector smaller than right, push back first
        if (left[l] < right[r]){
            temp.push_back(left[l]);
            l++;
        }
        // Else push smaller value first
        else {
            temp.push_back(right[r]);
            r++;
        }
    }

    while(l < left.size()){
        temp.push_back(left[l]);
        l++;
    }

    while(r < right.size()){
        temp.push_back(right[r]);
        r++;
    }

    v = temp;
    return v;
}

// Merge sort a vector
vector<int> ms(vector<int> &v){
    // Base case
    if(v.size() == 1)
        return v;

    // Find the middle
    int mid = ceil(v.size() / 2.0);
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());
  
    left = ms(left);
    right = ms(right);
    return merge(v, left, right);
}

//Print values of Vector<int>
void printV(vector<int> & v){
    for(auto z : v){
        cout << z << " ";
    }
    cout << endl;
}


int main(){

    srand(time(0));
    vector<int> a, d, v;
    genAscV(a);
    genDecV(d);
    printV(a);
    printV(d);
    merge(v, a, d);
    ms(v);
    printV(v);
    return 0;
}