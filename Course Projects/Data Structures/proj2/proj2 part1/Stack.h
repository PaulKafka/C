// Assignment 2
// stack.h
// By: Paul Kafka

#ifndef STACK_H
#define STACK_H

#include "Vector.h"
#include <iostream>

using namespace std;

template<class T>
class Stack {
// member function declarations
public: 
	void push(T& p);	// adds to back
	void pop();			// removes from back
	T& top();			// returns the top element
	bool empty();		// True if not empty
	void print();		// prints the stack
private:
	Vector<T> Stacks;	// Stack made from the vector class I made
};

// function definitions

template<class T>
void Stack< T >::push(T& p)
//adds element to the stack
{Stacks.push_front(p);}

template<class T>
void Stack< T >::pop()
//removes from the stack
{ Stacks.pop_front(); }

template<class T>
T& Stack< T >::top()
//returns the top
{ return Stacks[0]; }

template<class T>
bool Stack< T >::empty()
// Tells if empty
{
	if(Stacks.size()!= 0)
		return false;
	else
		return true; 
}

template<class T>
void Stack< T >::print()
// Prints the contents
{ Stacks.print(cout); }

#endif
