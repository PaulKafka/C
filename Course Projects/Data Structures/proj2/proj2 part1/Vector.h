// Assignment 2
// Vector.h
// By: Paul Kafka

#ifndef _VECTOR_H
#define _VECTOR_H

#include <iostream>

using namespace std;

template < class T >
class Vector
// Function Declerations. Some are defined in here.
{
public:
	Vector();									// Constructor
	~Vector();									// Destructor
	Vector(const Vector<T> & v);				// Copy Constructor
	Vector& operator= (const Vector<T> & v)		// Assignment Operator
	{
		if (this == &v)
			return *this;
		else
		{
			Size = v.Size;
			delete [] container;
			container = new T[Size];
			for (int i=0; i < Size; i++)
				container[i] = v.container[i];
			return *this;
		}
	}
	T& operator[] (int index) const				// Bracket Operator Overload.
	{
		if(index < 0){
			cerr << "This is not valid" <<endl;
			exit(1);
		}
		else
			return container[index];
	}
	void push_back(const T &e);		// Add to back
	void push_front(const T &e);	// Add to front
	void pop_back();				// Remove from back
	void pop_front();				// Remove from front
	void resize(int newCapac);		// Resize
	void print(std::ostream& os);	// Used to print vector
	int size() const;				// Returns Vector size
	int capacity() const;			// Returns Vector capacity
	
private:
	int Size;			// stores size of vector
	int Capacity;		// stores capacity
	T *container;		// Vector as an array called container
	T *tempc;			// temp array used for push_back
};

// Member function deffinitions

template < class T >
Vector< T >::Vector()
// Default contructor. Initialize member data.
{
	Size = 0;
	Capacity = 4;	
	container = new T[Capacity];  // Allocate array
}

template < class T >
Vector< T >::~Vector()
// Destructor
{
	delete [] container;	// deallocate array
}

template < class T >
Vector< T >::Vector(const Vector<T> & v)
// Copy Constructor. for deep copies.
{
	Size = v.Size;
	container = new T[Size];
	for (int i=0; i < Size; i++)
		container[i] = v.container[i];
}

template < class T >
void Vector< T >::push_back(const T &e)
// Pushes to the back
{
	if (Size >= Capacity) {			// resize if needed
		Capacity *= 2;
		tempc = container;
		container = new T[Capacity];
		for (int i=0; i < Size; i++)
			container[i] = tempc[i];
	}
	Size++;					// Increment the size
	container[Size-1] = e;	// Insert the element
}

template < class T >
int Vector< T >::size() const
{return Size;}	// returns size

template < class T >
int Vector< T >::capacity() const
{return Capacity;}	// returns capacity

template < class T >
void Vector< T >::pop_back()
// Removes and element from the back
{
	Size--;
	container[Size] = 0;
}

template < class T >
void Vector< T >::push_front(const T &e)
// Adds and element to the front
{
	if(Size == Capacity)
		resize(4 * Capacity); 		// resize if needed
	
	// shift the array
	T* temp = container;
	container = new T[Capacity];
	for(int i =0; i < Size; i++)
		container [i+1] = temp[i];
	delete [] temp;
	
	container[0] = e;	// insert element at the first slot
	Size++;				// increment the size
}

template < class T >
void Vector< T >::pop_front()
// Remove element from front
{
	// shift array
	T* temp = container;
	container = new T[Capacity -1];
	for(int i =0; i < Size; i++)
		container[i] = temp[i+1];
	delete [] temp; 
	
	Size--;	// decrement the size
}

template < class T >
void Vector< T >::resize(int newCapac)
// Allocate more space
{
	if( newCapac < Size)
		return;
	T * oldArray = container;
	container = new T[Capacity];
	for(int i =0; i < Size; i++)
		container[i] = oldArray[i];
	Capacity = newCapac;
	delete [] oldArray; 
}
template < class T >
void Vector< T >::print(std::ostream& os)
// Print the vector. Parameter could be "cout"
{
   for(int i =0; i <Size; i++)
   os << container[i] << " "; 
   os <<endl; 
}
 
#endif
