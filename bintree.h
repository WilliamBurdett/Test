#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <fstream>
#include "nodedata.h"

class BinTree {               // you add class/method comments and assumptions  
	friend ostream& operator<<(ostream&, BinTree&);
	
public: 
   BinTree();                                // constructor 
   BinTree(const BinTree &);                 // copy constructor 
   ~BinTree();                               // destructor, calls makeEmpty 
   bool isEmpty() const;                     // true if tree is empty, otherwise false 
   void makeEmpty();                         // make the tree empty so isEmpty returns true
   BinTree& operator=(const BinTree &); 
   bool operator==(const BinTree &) const;   
   bool operator!=(const BinTree &) const;   
   bool insert(NodeData*); 
   bool retrieve(const NodeData &, NodeData*&) const;  
   void displaySideways() const;             // provided, displays the tree sideways
   void buildTree(BinTree&, ifstream&);      // Builds tree based on text file
   int getDepth(const NodeData&) const;
   void bstreeToArray(NodeData * []);
   void arrayToBSTree(NodeData * []);

private: 
   struct Node { 
      NodeData* data;                        // pointer to data object  
      Node* left;                            // left subtree pointer  
      Node* right;                           // right subtree pointer  
   }; 
   Node* root;                               // root of the tree 
   
   // utility functions 
   bool insertHelper(Node * , NodeData * );
   void makeEmptyHelper(Node *&);
   void inorderHelper() const; 
   void sideways(Node*, int) const;          // provided, helper for displaySideways() 
   void outputHelper(ostream&, Node *);
   void print(ostream &, Node*);
   void toArrayHelper(NodeData * [], Node *, int);
   Node *copyHelper(const Node*);
   bool equalOperatorHelper(const Node*,const Node*) const; 
 
};

#endif
