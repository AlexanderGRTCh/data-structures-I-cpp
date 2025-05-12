#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-11-07
*/

/*
* The assign_obj class represents a vector of structs that 
* that hold pairs of char:integer. 
* The class assign_obj includes methods to compact() and
* insert new items to vector A<item> and
* operators to add two of it's instances or print the data 
* of an instance.
*/
class assign_obj{
    private:
        
        struct item{
            char value;
            int count;
        };
        std::vector<item> A;
        int size;
    public:
        // Construct object with size zero
        assign_obj();

        // Take in a string and store it in A and convert all chacacter to upper case
        assign_obj(std::string);

        // Prints out the whole object 
        // [value:count value:count ....]
        friend std::ostream& operator<<(std::ostream & out, assign_obj & obj);

        // Combine the two objects together. If both objs have the same value add values together. 
        // Call compact on both objects before combining
        friend const assign_obj operator+(assign_obj &,assign_obj &);

        // Compact the A so all identical chars are added together in on item.
        // Sort the resulting vector in alphabetical order
        void compact();

        // Add a new character to the front of the vector
        void f_add(char i);
        // Add a new character to the end of the vector
        void e_add(char i);
};

// Construct object with size zero
assign_obj::assign_obj(){
    size = 0;
    A.resize(0);
}

// Construct an object reciving a string and store it in A<item>.
// Convert all chacacter to upper case and assign value = 1
// @param aString:
// @pre "adea"
// @post [A:1, D:1, E:1, A:1]
assign_obj::assign_obj(string aString){
    size = aString.size();
    A.resize(size);

    item myItem;
    for(int i = 0; i < size; i++){
        myItem = {(char)toupper(aString[i]), 1};
        A[i] = myItem;
    }
}

// Print out the whole object 
// [value:count value:count ....]
std::ostream& operator<<(std::ostream & out, assign_obj & obj){
    out <<"[ ";
    for(assign_obj::item anItem : obj.A){
        out << anItem.value;
        out << ":";
        out << anItem.count;
        out << " ";
    }
    out <<"]";
    return out;
}

// Compact the A so all identical chars are added together in on item.
// The resulting vector is in alphabetical order
// @pre [A:1, D:1, B:1, A:1]
// @post [A:2, B:1, D:1]
void assign_obj::compact(){

    //Create a vector<int> that represents the alphabet and it's values the struct.count
    vector<int> v(26,0);   
    for(int i = 0; i < this->size; i++){
        //Populate the vector<int>
        v[(int)A[i].value-65] += A[i].count;
    }
    vector<item> B;                     
    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i] != 0){

            item myItem;
            myItem.value = (char)(i+65);
            myItem.count = v[i];
            B.push_back(myItem);
        }
    }
    A = B;
    size = A.size();
}

// Combine the two objects together. 
// If both objs have the same value add values together. 
// Call compact on both objects before combining
// @pre [A:2, C:2, D1] + [A:1, B1]
// @post [A:3, B:1, C:2, D:1]
const assign_obj operator+(assign_obj & obj1 ,assign_obj & obj2){
    obj1.compact();
    obj2.compact();
    assign_obj obj3;
    obj3.A.insert( obj3.A.end(), obj1.A.begin(), obj1.A.end() );
    obj3.A.insert( obj3.A.end(), obj2.A.begin(), obj2.A.end() );
    obj3.size = obj2.size + obj1.size;
    obj3.compact();
    return obj3;
}

// Add a new character to the front of the vector
// @param char i
// @pre a, [B:1, V:1]
// @post [A:1, B:1, V:1]
void assign_obj::f_add(char i){
    item myItem;
    myItem.count = 1;
    myItem.value = toupper(i);
    A.insert(A.begin(),myItem);
    size++; 
}
// Add a new character to the end of the vector
// @param char i
// @pre a, [B:1, V:1]
// @post [B:1, V:1, A:1]
void assign_obj::e_add(char i){
    item myItem;
    myItem.count = 1;
    myItem.value = toupper(i);
    A.push_back(myItem);
    size++; 
}
#endif