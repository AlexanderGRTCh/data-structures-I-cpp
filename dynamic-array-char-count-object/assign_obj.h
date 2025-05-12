#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

/*
* @Author Alexander Kemos
* @Version 1.0
* @since 2022-11-10
*/

/*
* The assign_obj class represents a dynamic array of structs that 
* that hold pairs of char:integer. 
* The class assign_obj includes methods to compact() and
* insert new items to the dynamic array. 
* Includes operators to add two of it's instances or print the data 
* of an instance.
*/

class assign_obj{
    private:
        
        struct item{
            char value;
            int count;
        };
        item * A;
        int size;
    public:
        assign_obj();
        assign_obj(std::string);
        friend std::ostream& operator<<(std::ostream & out, assign_obj & obj);
        friend const assign_obj operator+(assign_obj &,assign_obj &);
        void compact();
        void f_add(char i);
        void e_add(char i);
        const assign_obj& operator=(const assign_obj &); 

        ~assign_obj(); 
        assign_obj(const assign_obj&); 
};

// Construct object with size zero
assign_obj::assign_obj(){
    size = 0;
    A = nullptr;
}

// Construct an object reciving a string and store it's chars in a dynamic array
// of struct items{char value, int count}
// Convert all chacacter to upper case and assign count = 1
// @param aString:
// @pre "adea"
// @post [A:1, D:1, E:1, A:1]
assign_obj::assign_obj(string aString){
    size = (int)aString.size();
    A = new item[size];
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
    for (int i = 0; i < obj.size; i++) {
        out << obj.A[i].value << ":"
            << obj.A[i].count << " ";
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
    for(int i = 0; i < size; i++){
        //Populate the vector<int>
        v[(int)A[i].value-65] += A[i].count;
    }
    item * B = new item[size];   
    int counter = 0;           
    for(unsigned i = 0; i < v.size(); i++){
        if(v[i] != 0){

            item myItem;
            myItem.value = (char)(i+65);
            myItem.count = v[i];
            B[counter] = myItem;
            counter++;
        }
    }
    size = counter;
    delete[] A;
    A = B;
}

//Deep copy the instance of a variable and store it to another instance
assign_obj::assign_obj(const assign_obj& obj){
    this->size = obj.size;
    A = new item[size];
    for(int i = 0; i < obj.size; i++){
        A[i] = obj.A[i];
    }
    cout << "-------------------COPY-------------------" << endl;
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
    obj3.size = obj1.size + obj2.size;
    obj3.A = new assign_obj::item[obj3.size];
    for(int i = 0; i < obj3.size; i++){
        if(i < obj1.size){
            obj3.A[i] = obj1.A[i];
        }
        else{
            obj3.A[i] = obj2.A[i-obj1.size];
        }
    }
    obj3.compact();
    return obj3;
}

//Assignment operator
//Assign new value to an instance of the object
const assign_obj& assign_obj::operator=(const assign_obj & anObj){
    if(this == &anObj){
        return *this;
    }
    delete[] A;
    size = anObj.size;
    A = new item[anObj.size];
    for(int i = 0; i < size; i++ ){
        A[i] = anObj.A[i];
    }
    cout << "-------------------ASSIGNMENT-------------------" << endl;
    return *this;
}

//Destructor
assign_obj::~assign_obj(){
    delete[] A;
    cout << "-------------------DELETE-------------------" << endl;
}

// Add a new character to the front of the vector
// @param char i
// @pre a, [B:1, V:1]
// @post [A:1, B:1, V:1]
void assign_obj::f_add(char i){
    item myItem;
    myItem.count = 1;
    myItem.value = toupper(i);
    size++; 
    item * B = new item[size];
    B[0] = myItem;
    for(int i = 1; i < size; i++){
        B[i] = A[i-1];
    }
    delete[] A;
    A = B;    
}

// Add a new character to the end of the vector
// @param char i
// @pre a, [B:1, V:1]
// @post [B:1, V:1, A:1]
void assign_obj::e_add(char i){
    item myItem;
    myItem.count = 1;
    myItem.value = toupper(i);
    size++;
    item * B = new item[size];
    for(int i = 0; i < size-1; i++){
        B[i] = A[i];
    }
    B[size-1] = myItem;
    delete[] A;
    A = B;
}

#endif