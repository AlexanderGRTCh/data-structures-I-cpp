#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

/*
* @Author Alexander Kemos 100375966
* @Version 1.0
* @since 2022-11-23
*/

/*
* The assign_obj class represents a linked list of nodes that 
* that hold values of char:integer. 
* The class assign_obj includes methods to compact() and
* insert new nodes to the linked list. 
* Includes operators to add two of it's instances or print the data 
* of an instance.
*/
class assign_obj{
    private:
        
        struct node{
            char data;
            int count;
            node* next; 
        };
        node* tail;
        node* head;

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
    head = tail = nullptr;
}

// Construct an object reciving a string and store it's chars in a linked list
// of nodes{char value, int count}
// Convert all chacacter to upper case and assign count = 1
// @param aString:
// @pre "adea"
// @post [A:1, D:1, E:1, A:1]
assign_obj::assign_obj(string aString){

    head = tail = nullptr;
    for(unsigned i = 0; i < aString.size(); i++){
        if(!head){
            head = tail = new node{(char)toupper(aString[i]), 1, nullptr};
        }
        else{
            tail->next = new node{(char)toupper(aString[i]), 1, nullptr};
            tail = tail->next;
        }
    }
}

// Print out the whole object 
// [value:count value:count ....]
std::ostream& operator<<(std::ostream & out, assign_obj & list){
    
    assign_obj::node* p = list.head;

    out <<"[ ";
    while(p){
        out << p->data << ":" << p->count << " ";
        p = p-> next;
    }
    out << "]";
    return out;
}

// Compact the A so all identical chars are added together in on item.
// The resulting linked list is in alphabetical order
// @pre [A:1, D:1, B:1, A:1]
// @post [A:2, B:1, D:1]
void assign_obj::compact(){

    assign_obj::node* p = this->head;

    //Create a vector<int> that represents the alphabet and it's values the struct.count
    vector<int> v(26,0); 

    while(p){
        v[(int)p->data-65] += p->count;
        p = p->next;
    }
    // Delete node
    while(p){
        node* temp = p;
        p = p->next;
        delete temp;
    }
    head = tail = nullptr;
    for(unsigned i = 0; i < v.size(); i++){
        if(v[i] != 0){
            if(!head){
                head = tail = new node{(char)(i+65), v[i], nullptr};
            }
            else{
                tail->next = new node{(char)(i+65), v[i], nullptr};
                tail = tail->next;
            }
        }
    }
}

// Deep copy the instance of a variable and store it to another instance
assign_obj::assign_obj(const assign_obj& obj){

    head = tail = nullptr;
    // Create a pointer that points to node obj.head;
    node* p = obj.head;
    while(p){
        // If there is no head, instantiate one;
        if(!head){
            head = tail = new node{p->data, p->count, nullptr};
        }
        else{
            tail->next = new node{p->data, p->count, nullptr};
            tail = tail->next;
        }
        p = p->next;
    }
    cout << "-------------------COPY-------------------" << endl;
}

// Combine two objects together. 
// If both objs have the same value add values together. 
// Call compact on both objects before combining
// @pre [A:2, C:2, D1] + [A:1, B1]
// @post [A:3, B:1, C:2, D:1]
const assign_obj operator+(assign_obj & obj1 ,assign_obj & obj2){
    obj1.compact();
    obj2.compact();
    assign_obj obj3;

    assign_obj::node* p = obj1.head;
    assign_obj::node* z = obj2.head;
    // Add elements from obj1 to obj3
    while(p){
        if(!obj3.head){
            obj3.head = obj3.tail = new  assign_obj::node{p->data, p->count, nullptr};
        }
        else{
            obj3.tail->next = new  assign_obj::node{p->data, p->count, nullptr};
            obj3.tail = obj3.tail->next;
        }
        p = p->next;
    }

    // Add elements from obj2 to obj3
    while(z){
        if(!obj3.head){
            obj3.head = obj3.tail = new  assign_obj::node{z->data, z->count, nullptr};
        }
        else{
            obj3.tail->next = new  assign_obj::node{z->data, z->count, nullptr};
            obj3.tail = obj3.tail->next;
        }
        z = z->next;
    }
    obj3.compact();
    return obj3;
}

// Assignment operator
// Assign new value to an instance of the object
const assign_obj& assign_obj::operator=(const assign_obj & anObj){

    head = tail = nullptr;
    node* p = anObj.head;
    while(p){
        if(!head){
            head = tail = new  assign_obj::node{p->data, p->count, nullptr};
        }
        else{
            tail->next = new  assign_obj::node{p->data, p->count, nullptr};
            tail = tail->next;
        }
        p = p->next;
    }
    cout << "-------------------ASSIGNMENT-------------------" << endl;
    return *this;
}

// Destructor
assign_obj::~assign_obj(){
    node* p = head;
    while(p){
        node* temp = p;
        p = p->next;
        delete temp;

    }
    cout << "-------------------DELETE-------------------" << endl;
}

// Add a new character to the front of the linked list
// @param char i
// @pre a, [B:1, V:1]
// @post [A:1, B:1, V:1]
void assign_obj::f_add(char i){

    node* aNode = new node{(char)toupper(i), 1, nullptr};
    aNode->next = this->head;
    this->head = aNode;
}

// Add a new character to the end of the vector
// @param char i
// @pre a, [B:1, V:1]
// @post [B:1, V:1, A:1]
void assign_obj::e_add(char i){
    
    tail->next = new node{(char)toupper(i), 1, nullptr};
    tail = tail->next;
}

#endif