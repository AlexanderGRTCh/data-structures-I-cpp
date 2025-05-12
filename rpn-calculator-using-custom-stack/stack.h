#ifndef MV3_H
#define MV3_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class stack3{

    public:
        stack3(){
            top = nullptr;
        }
        void push(T x){

            top = new node{x, top}; //Make a new node and point it to new point
        };

        T peek(){
            if(isEmpty()){
                cout << "STACK IS EMPTY" << endl;
                exit(1);
            }
            return top->data;

        };

        T pop(){
            T ret = peek(); //Save whatever memory is in this one
            node* to_del = top; //take whatever value it has save it that and rid
            top = top->next;//reroot top to point to the next one
            delete to_del; //get rid of the node
            return ret; //return the value we wont to return
        };

        bool isEmpty(){
            return top == nullptr;
        };

        //Memory stuff
        //copy, decustractor, assignment
    private: 
        struct node{
            T data;
            node* next;
        };
        node* top;

};


#endif