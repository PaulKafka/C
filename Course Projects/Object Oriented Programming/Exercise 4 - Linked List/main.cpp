#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> obj;	// Creat Linked List

// Add elements to the back
cout << " Add 5, 3, 2 \n";
obj.AddToEnd(5);
obj.AddToEnd(3);
obj.AddToEnd(2);
cout << obj;

// Remove elements from the back
cout << " Remove 2 \n";
obj.RemoveFromEnd();
cout << obj;
cout << " Remove 3 \n";
obj.RemoveFromEnd();
cout << obj;


// Test these functions (you added)
cout << " Add 7 to the 2nd spot \n";
obj.AddElementPos(7, 2); // at pos 2, added 7
cout << obj;

cout << " Add 8 to the 2nd spot \n";
obj.AddElementPos(8, 2); // at pos 2, added 7
cout << obj;

cout << " Add 0 to the 1 spot \n";
obj.AddElementPos(0, 1); // didn't work
cout << obj;

cout << " Add 4 to the 9 spot \n";
obj.AddElementPos(4, 9); // at pos 2, added 7
cout << obj;

cout << " Add 88 to the 3 spot \n";
obj.AddElementPos(88, 3); // at pos 2, added 7
cout << obj;

cout << " Add 99 to the -1 spot \n";
obj.AddElementPos(99, -1); // at pos 2, added 7
cout << obj;

cout << " Add 33 to the 0 spot \n";
obj.AddElementPos(33, 0); // at pos 2, added 7
cout << obj;

cout << " Add 55 to the 1 spot \n";
obj.AddElementPos(55, 1); // at pos 2, added 7
cout << obj;

cout << " Remove  spot 2 \n";
obj.RemoveElementPos(2);  // removed the 7
cout << obj;

cout << " Remove  spot 10 \n";
obj.RemoveElementPos(10);  // removed the 7
cout << obj;

cout << " Remove spot 1 \n";
obj.RemoveElementPos(1);  // removed the 7
cout << obj;

cout << " Remove spot 0\n";
obj.RemoveElementPos(0);  // removed the 7
cout << obj;

cout << " Remove  spot 3 \n";
obj.RemoveElementPos(3);  // removed the 7
cout << obj;

cout << " Remove  spot -1 \n";
obj.RemoveElementPos(-1);  // removed the 7
cout << obj;

cout << "\n\n\n\n";


LinkedList<int> obj2;	// Creat Linked List

obj2.AddElementPos(0, 0); // at pos 2, added 7
obj2.print();
obj2.AddElementPos(0, 1); // at pos 2, added 7
obj2.print();
obj2.AddElementPos(2, 2); // at pos 2, added 7
obj2.print();
obj2.RemoveElementPos(1);  // removed the 7
obj2.print();
obj2.RemoveElementPos(1);  // removed the 7
obj2.print();
obj2.AddElementPos(5, 1); // at pos 2, added 7
obj2.print();
obj2.AddElementPos(3, 1); // at pos 2, added 7
obj2.print();
obj2.RemoveElementPos(1);  // removed the 7
obj2.print();
obj2.RemoveElementPos(0);  // removed the 7
obj2.print();
/*<0>
<0><1>
<0><1><2> 
<0><2>
<2>
<2><5>
<2><3><5>
<2><5>
<5>
<5>*/
}
