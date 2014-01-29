/* 
By: Paul Kafka
Assignment 4
Binary Search Tree
*/

#ifndef BST_H
#define BST_H
#include <iostream>

using namespace std;

template <typename T>
class BST{
	
	private:
		struct BinaryNode{
			T data;
			BinaryNode *left;      //Left child
			BinaryNode *right;    //Right child
		};
	
	BinaryNode *root; 

	public:
	BST() { 			// Constructor
		root = NULL;
    }

	~BST() {			// Destructor
		makeEmpty(); 
    }
	
	void push(const T& d) {		// Push function
		BinaryNode* t = new BinaryNode;
		BinaryNode* parent;
		t->data =d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;

		if(isEmpty())
			root = t;
		else {
			BinaryNode* current;
			current = root;

			//find's the parent of node
			while(current) {
				parent = current;
				if(t->data > current->data) 
					current = current ->right;
				else 
					current = current->left;
			}
			if(t->data < parent ->data)
				parent ->left = t;
			else 
				parent -> right = t;
		}
	}
  
	void makeEmpty() {
	  makeEmpty(root);
	}

	void PrintPreorder(int n) {		// Print using preorder traversal
		preorder(n, root);
	}
	
	void RotateUp(T& x) {
		BinaryNode *ptr = root;
		BinaryNode *parent = ptr;
		while(ptr!= NULL)
		{
			if( x < ptr->data) {
				parent = ptr;
				ptr = ptr->left;
			}
			else if(ptr->data < x) {
				parent = ptr;
				ptr = ptr ->right;
			}
			else {
				if(ptr->right != NULL)
					rotate(ptr,parent);
			}
		}
	}
	
	
	bool search(const T& d) {		// search the tree
		BinaryNode *ptr = root;
		BinaryNode *parent = ptr;
		while(ptr!= NULL)
		{
			if( d < ptr->data) {
				parent = ptr;
				ptr = ptr->left;
			}
			else if(ptr->data < d) {
				parent = ptr;
				ptr = ptr ->right;
			}
			else {
				if(ptr->right != NULL)
					rotate(ptr,parent);
				return true;
			}
		}
		return false;
	}

	void preorder(int n, BinaryNode* p) {

		static int i = 0;	// stores when to exit (after n cout's)
		
		if ( n <0) {		// if want to print all
			if(p != NULL) {
				cout<< p->data <<endl;
			if(p->left)
				preorder(n, p->left);
			if(p->right)
				preorder(n, p->right);
			}
			else 
				return;
		}
		else {				// if dont want to print all
			if ((p != NULL) && (i !=n)) {
				i++; 		// increment counter 
				cout<< p->data <<endl;
				if(p->left)
					preorder(n, p->left);
				if(p->right)
					preorder(n, p->right);
			}
			else 
				return;
		}
	}

	bool isEmpty() const {
		return root == NULL;
	}
	
	void makeEmpty(BinaryNode *& p) {
		if(p != NULL) {
			makeEmpty(p->left);
			makeEmpty(p->right);
			delete p;
		}
		p = NULL;
	}
	
	void rotate(BinaryNode *& k1, BinaryNode *& parent) {
		if(parent!= k1) {	 	 
			BinaryNode *k2 = k1 -> right;
			k1->right = k2 ->left;
			k2->left = k1;
			k1 = k2;
			if(parent->data > k1->data)
				parent ->left = k1;
			else if(parent->data < k1->data)
				parent ->right = k1;
       
		}
		else {
			BinaryNode *s = root->right;
			root ->right = s->left;
			s->left = root;
			root = s;
		}
    }
};

#endif
