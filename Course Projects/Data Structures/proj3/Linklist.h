#ifndef LINKLIST_H
#define LINKLIST_H

// Assignment 3
// By: Paul Kafka
// Notes: The textbook had the code on how to implement
// a doubly linked list, so I just modeled it. The book 
// had the iterator class inside the List Class, so I kept
// it that way, but I put that portion in a diffetent file
// and #included it. This is an extremely generic List class; 
// It probably has more than it needed for this assignment.
// I tried to seperate the declaration and implementation the
// best i could. There is a self-organinzing function which 
// does the required organizing when called.

#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 

using namespace std;

/*------------------  CLASS DECLARATIONS ----------------------*/
template <typename object> 	// Templated Doubly Linked List Class
class List
{
	private:
		struct Node{			// Each Node contains
			string data;
			int counter;
			Node *prev, * next;
			Node( const string &d = string(), Node *p = NULL, Node *n = NULL) : data(d), prev(p), next(n){counter =0;}
  		};
	public:
		#include"iterator.h" // iterator class. because the List class uses it
							 // and it uses the List class, i put it in here and not the
							 // top. It acts as a code segment to save space.
	
		List();						// Constructor
		~List();					// Destructor
 		List( const List & rhs );	// Copy Contructor
		const List & operator= ( const List & rhs );	// Assignment Operator
		void clear( );		// Clears
		int Size() const;	// Returns the size of the List
		bool empty();		// Boolean Empty 
		void Self_Organinize(iterator itr, const object & x) {		// THIS IS WHERE IT SELF ORGANIZES!!
			if (itr==head->next->next) {	// if at 2 after the head
				insert(--itr, x);	// insert right after the head
				erase(++itr); 		// Deletes the old one
			}
			else if (itr!=head->next)  {	// If not at front
				insert(--(--itr), x);	// Inserts  a copy closer to the front by 2
				erase( ++(++itr) ); 	// Deletes the old one
			}
		}
		iterator erase( iterator start, iterator end ) {	// Erases a portion of the list
			for( iterator itr = start; itr != end; )
      			itr = erase( itr );
   			return end;
		};
		iterator insert( iterator itr, const object & x ) { // Inserts x before itr.
			Node *p = itr.current;
			size++;
        	return iterator( p->prev = p->prev->next = new Node( x, p->prev, p ) );
		};
		iterator erase( iterator itr )	{// Erase item at itr.
			Node *p = itr.current;
			iterator returnVal( p->next );
        	p->prev->next = p->next;
        	p->next->prev = p->prev;
        	delete p;
        	size--;
        	return returnVal;
		};
		
		// The common List methods
		object & front( ) 					{ return *begin( ); }
		const object & front( ) const 		{ return *begin( ); }
		object & back( ) 					{ return *--end( ); }
		const object & back( ) const 		{ return *--end( ); }
		void push_front( const object & x ) { insert( begin( ), x ); }
		void push_back( const object & x ) 	{ insert( end( ), x ); }
		void pop_front( ) 					{ erase( begin( ) ); }
		void pop_back( ) 					{ erase( --end( ) ); }
		
		iterator begin( )					// Begin iterator (Mutator) 
			{ return iterator( head->next ); }
		const_iterator begin( ) const		// Begin iterator (Accessor)  
			{ return const_iterator( head->next ); }
		iterator end( )						// End iterator (Mutator)
			{ return iterator( tail ); }
		const_iterator end( ) const			// End iterator (Accessor)
			{ return const_iterator( tail ); }

 	private:
		int size;				   // Stores the size of the list
		Node *head, *tail,*ptr;    // Each List object has these 3 Nodes
};

/*------------------  CLASS DEFFIn Word-List: n is a NITIONS ----------------------*/
template < class object >
List< object >::List() {
// Default constructor
	size = 0;
	head = new Node;
	tail = new Node;
	head -> next = tail;
	tail -> prev = head;
	ptr =this-> head -> next;
}

template < class object >
List< object >::~List() {
// Destructor
	clear(); 
 	delete head;
	delete tail;
}

template < class object >
List< object >::List( const List & rhs ) {
// Copy Constructor
 	size = 0;
	head = new Node;
	tail = new Node;
	head -> next = tail;
	tail -> prev = head;
	ptr =this-> head -> next;
	*this = rhs;
}

template < class object >
const List< object > & List<object>::operator= ( const List & rhs ) {
// Assignment Operator
	if( this == &rhs )
        return *this;
	clear( );
	for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
		push_back( *itr );
	return *this;
}

template < class object >
void List< object >::clear( ) {
// Empties the List
	while( !empty( ) )
		pop_front( );
}

template < class object >
int List< object >::Size() const
{ return size;} // returns size

template < class object >
bool List<object> ::empty() 
{ return size == 0; } // Return true if the list is empty.

#endif
