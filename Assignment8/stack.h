#ifndef STACK_H
#define STATK_H

#include <tuple>
#include <iostream>
#include <vector>
using namespace std;


/*
* @Author Alexander Kemos 
* @Version 1.0
* @since 2022-12-02
*/

/*
A templated linked list stack that can peek, pop, push and check if empty
*/

template <typename T>
class stack{
    public:
        
        stack();
        T pop();
        void push(T x);
        T peek();
        bool isEmpty();
        ~stack();
        


    private:
        struct node{
            T data;
            node* next;
        };
        node* top;
};

template <typename T>
stack<T>::stack(){
    top = nullptr;
}

template <typename T>
T stack<T>::pop(){
    T ret = peek();
    node* to_del = top;
    top = top->next;
    delete to_del;
    return ret;
}

template <typename T>
void stack<T>::push(T x){
    top = new node{x, top};
}

template <typename T>
T stack<T>::peek(){
    if(isEmpty()){
        std::cout << "STACK IS EMPTY" << std::endl;
        exit(1);
    }
    return top->data;
}

template <typename T>
bool stack<T>::isEmpty(){
    return top == nullptr;
}

// Destructor
template <typename T>
stack<T>::~stack(){
    node* p = top;
    while(p){
        node* temp = p;
        p = p->next;
        delete temp;

    }
}

#endif
