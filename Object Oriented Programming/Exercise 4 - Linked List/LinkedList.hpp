/* File: LinkedList.hpp
   Author: Paul Kafka
   Description: This file contains the implementation of the templated classes
   from LinkedList.h                                                            */

template <typename T> 
std::ostream& operator<<(std::ostream& os, const ListElement<T>& LE){
  os<<"<"<<LE.data<<">";
  return os;
}

template <typename T> 
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
  ListElement<T> *ptr;
  
  /* traverse linked list */
  for(ptr = list.head; ptr; ptr = ptr->next)
    os<<*ptr;
  
  return os;
}

/* Default Constructor (Complete) */
template<typename T>
LinkedList<T>::LinkedList() {

  /* initialize list to be empty (NULL pointer indicates this) */
  this->head = NULL;
}

/* Deallocates dynamic memory associated with calling object. */
template<typename T>
LinkedList<T>::~LinkedList() {
	if (head != NULL) // List is not empty
	   {    
		  ListElement <T> *currentPtr = head;
		  ListElement <T> *tempPtr;

		  while ( currentPtr != 0 ) // delete remaining nodes
		  {  
			 tempPtr = currentPtr;
			 currentPtr = currentPtr->next;
			 delete tempPtr;
		  } // end while
	   } // end if
}

template<typename T>
void LinkedList<T>::AddToEnd(T val) {
  ListElement<T> *ptr;

  /* list is empty */
  if(!this->head) {
    this->head = new ListElement<T>;	// point head to a new node
    this->head->data = val;				// make the new nodes data the value in parameters
    this->head->next = NULL;			// make the next node null
    return;
  }

  /* traverse list until we find end */
  for(ptr = this->head; ptr->next; ptr = ptr->next); // while the next isn't null, go to the next node
    

  ptr->next = new ListElement<T>;	// make the null(next) node a new node
  ptr->next->data = val;			// put the data in the next node
  ptr->next->next = NULL;			// make the next next node null
}

template<typename T>
void LinkedList<T>::RemoveFromEnd() {
  ListElement<T> *ptr;

  /* list empty */
  if(!this->head)
    return;

  /* one element list */
  if(!this->head->next) { // id the first next node as null
    delete this->head;		// delete the head node
    this->head = NULL;		// make the head node null. no more elements
    return;
  }

  /* traverse list until we reach one element before end */
  for(ptr = this->head; ptr->next->next; ptr = ptr->next)
    ;
  
  delete ptr->next;
  ptr->next = NULL;
}


/* Allocates a new ListElement and adds it to the calling object's linked list 
   at position 'pos' in the linked list (numbering begins at 0).  If 'pos' < 0 
   or greater than the size of the list, the element is added at the end of 
   the list.                                                                    */
template<typename T>
void LinkedList<T>::AddElementPos(T val, int pos) {
//Allocates a new ListElement and adds it to the calling object's linked 
//list at the position 'pos' in the linked list (numbering begins at 0). 
//If 'pos' < 0 or greater than the size of the list, the element is added at the end of the list. 

	ListElement <T> *newPtr;		// Creates new node
	newPtr =new ListElement<T>;		// 
	newPtr->data = val;				// Set the new pointer's data to the val
	
	ListElement <T> *temp1 = head;		// create a temporary node
	ListElement <T> *count;				// create a temporary node to count

	int numNodes = -1;			// Used to store # of nodes . starts the index at [0]. to start at [1], set equal to 0.	

	for( count = head ; count!=0 ; count= count->next)		// counts the number of nodes
	numNodes++;

	if ( head == 0 )					// List is empty
	{head = newPtr;
	head->next = NULL;}// added after submitted
	else if ((pos > numNodes) || (pos < 0) )		// Position is more than number of nodes
		AddToEnd(val);
	else if (pos==0)
	{
		temp1->data = val;			// put the data in the next node
		head = temp1;					// aim firstPtr at new node
	}
	else if (pos == 1)				// Position is first or less than zero
	{
		temp1->next->data = val;			// put the data in the next node
		head = temp1;					// aim firstPtr at new node
	}
     else 
      {            
		  for( int i = 1 ; i < pos ; i++ )		// scan nodes
		  {
			temp1 = temp1->next;
		  }
			newPtr->next = temp1->next;    //transfer the address
			temp1->next = newPtr;			 //transfer the address
		}
}

/* Removes the element at the position 'pos'.  If 'pos' is not a valid position,
   nothing is done.                                                             */
template<typename T>
void LinkedList<T>::RemoveElementPos(int pos) {
//Removes the element at the position 'pos'. If 'pos' is not a valid position, nothing is done.

	ListElement <T> *temp1 = head;			// create a temporary node
	ListElement <T> *old_temp = head;		// create a temporary node
	ListElement <T> *count;						// create a temporary node to count

	int numNodes = -1;       // store # of nodes
 
	for( count = head ; count!=0 ; count= count->next)		// counts the number of nodes
	numNodes++;

   if (!this->head)					// List is empty, delete unsuccessful
      return;					
	else if (pos ==0)			// Position is first, remove from front
	{
		head = head->next; // point to previous 2nd node
		//data = temp1->data; // return data being removed
		delete temp1; // reclaim previous front node
   }	
   else if ((pos > numNodes)|| (pos <0))	// Position is more or less than # of nodes, return false
	   return;
   else  // Valid Input
   {
     
		old_temp = temp1;						// transfer the address
		for( int i = 0 ; i < pos; i++)		// start at 0 because the Linkedlist[0]
		{
			 old_temp = temp1;                    // transfer the address
			 temp1 = temp1->next;              // transfer the address
		}
		old_temp->next = temp1->next;  // transfer the address
		delete temp1;	// deallocate
   }

}
template<typename T>
void LinkedList<T>::print() const
{
   if ( !this->head ) // List is empty
   {
      cout << "The list is empty\n\n";
      return;
   } // end if

   ListElement<T> *currentPtr = head;

   cout << "The list is: ";

   while ( currentPtr != 0 ) // get element data
   {
      cout << currentPtr->data 
		  << ' ';
      currentPtr = currentPtr->next;
   } // end while

   cout << "\n\n";
} // end function print