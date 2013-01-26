// binTree.cpp
// 

#include "bintree.h"

void BinTree:: print(ostream& out, Node* root){
	outputHelper(out, root);
}

ostream& operator << (ostream &out, BinTree & tree){
	if(!tree.isEmpty()){
		tree.print(out, tree.root);
	}
	return out;
	
}

void BinTree::outputHelper(ostream &out, Node * current){
	if(current->left!=NULL && current->right!=NULL){
		outputHelper(out, current->left);
		cout << *current->data;
		outputHelper(out, current->right);
	}
	else if(current->left!=NULL && current->right == NULL){
		outputHelper(out, current->left);
		cout << *current->data;
	}
	else if(current->right!=NULL && current->left == NULL){
		cout << *current->data;
		outputHelper(out, current->right);
	} else {
		cout << *current->data;
	}
}

BinTree::BinTree(){
	root = new Node();
	root->left = NULL;
	root->right = NULL;
	root->data = NULL;
}

BinTree::BinTree(const BinTree & tree){
	makeEmpty();
	root = copyHelper(tree.root);
}

BinTree::Node* BinTree::copyHelper(const Node * oldNode){
	if(oldNode==NULL){
		return NULL;
	}
	Node *newNode = new Node;
	newNode->data = oldNode->data;
	newNode->left = copyHelper(oldNode->left);
	newNode->right = copyHelper(oldNode->right);
	return newNode;
}

BinTree::~BinTree(){
	cout << "@@ CALLING DESTURCTOR @@" << endl;
	this->makeEmpty();
	delete root;
	cout << "@@ TERMINATING DESTURCTOR @@" << endl;
}

bool BinTree::isEmpty() const{
	//cout << "@@ CALLING ISEMPTY() @@" << endl;
	return(root->left == NULL && root->right == NULL && root->data==NULL);
}	

void BinTree::makeEmpty(){
	//cout << "@@ CALLING MAKE EMPTY() @@" << endl;
	makeEmptyHelper(root);
	root = new Node();
	root->left=NULL;
	root->right=NULL;
	root->data=NULL;
	//cout << "@@ TERMINATING MAKE EMPTY() @@" << endl;
}

void BinTree::makeEmptyHelper(Node *& current){
	if(current!=NULL){
		makeEmptyHelper(current->right);
		makeEmptyHelper(current->left);
		delete current;
	}
	current = NULL;
}

BinTree & BinTree::operator=(const BinTree & original){
	cout << "@@ operator= @@" << endl;
	makeEmpty();
	root = copyHelper(original.root);
	return *this;
}

bool BinTree::operator==(const BinTree& right) const{
	cout << "@@ CALLING operator== @@" << endl;
	Node *leftCurr = root;
	Node *rightCurr = right.root;
	if(root->data==NULL && right.root->data==NULL){
		return true;
	}
	else if((root->data==NULL && right.root->data!=NULL) || (root->data!=NULL 
				&& right.root->data==NULL)){
		return false;
	}
	cout << "comparing " << *root->data << " to " << *right.root->data << endl;
	if(*root->data!=*right.root->data){
		cout << "@@ TERMINATING operator== @@" << endl;
		return false;
	}
	cout << "@@ TERMINATING operator== @@" << endl;
	return true;
}

bool BinTree::equalOperatorHelper(const Node *leftCurr, const Node *rightCurr) const{
	cout << "@@ CALLING equalOperatorHelper @@" << endl;
	if(leftCurr->data!=rightCurr->data){
		cout << "@@ TERMINATING equalOperatorHelper @@" << endl;
		return false;
	}
	if(leftCurr->left!=rightCurr->left && leftCurr->left!=NULL){
		if(!equalOperatorHelper(leftCurr->left, rightCurr->left)){
			cout << "@@ TERMINATING equalOperatorHelper @@" << endl;
			return false;
		}
	}
	if(leftCurr->right!=rightCurr->right && leftCurr->right!=NULL){
		if(!equalOperatorHelper(leftCurr->right, rightCurr->right)){
			cout << "@@ TERMINATING equalOperatorHelper @@" << endl;
			return false;
		}
	}
}
/*
bool BinTree::operator==(const BinTree& right) const{
	cout << "@@ CALLING operator== @@" << endl;
	return equalOperatorHelper(root, right.root);
}

bool BinTree::equalOperatorHelper(const Node *leftCurr, const Node *rightCurr) const{
	cout << "@@ CALLING equalOperatorHelper @@" << endl;
	if(leftCurr==NULL){
		return rightCurr==NULL;
	}
	if(rightCurr==NULL){
		return false;
	}
	if(*leftCurr->data!=*rightCurr->data){
		return false;
	}
	return equalOperatorHelper(leftCurr->left, rightCurr->left) && 
			equalOperatorHelper(leftCurr->right, rightCurr->right);
}*/

bool BinTree::operator!=(const BinTree & right) const{
	cout << "@@ CALLING operator!= @@" << endl;
	return !(*this==right);
}

bool BinTree::insert(NodeData * data){
	cout << "@@ CALLING INSERT @@" << endl;
	cout << *data << endl;
	cout << "## checking if root is null ##" << endl;
	if(root->data==NULL){
		root->data = data;
		return true;
	}
	else{
		insertHelper(root, data);
		cout << "@@ TERMINATING INSERT @@" << endl;
		return true;
	}
	
	return false;
}

bool BinTree::insertHelper(Node * current, NodeData * data){
	cout << "@@ CALLING INSERT HELPER @@" << endl;
	cout << "DATA BEING COMPARED. Current data: " << *current->data << " Data: " << *data << endl;
	if(current->data == data){
		return false;
	}
	else if(*current->data < *data){
		cout << "## DATA GREATER ##" << endl;
		if(current->right == NULL){
			Node *node = new Node();
			node->data = data;
			node->right=NULL;
			node->left=NULL;
			current->right = node;
			return true;
		}
		insertHelper(current->right, data);
	}
	else if(*current->data > *data){
		cout << "## DATA LESS ##" << endl;
		if(current->left == NULL){
			Node *node = new Node();
			node->data = data;
			node->right=NULL;
			node->left=NULL;
			current->left = node;
			return true;
		}
		insertHelper(current->left, data);
	}
	
	cout << "@@ TERMINATING INSERT HELPER @@" << endl;
}

bool BinTree::retrieve(const NodeData & desired, NodeData *& found) const{
	return false;
}

int BinTree::getDepth(const NodeData & desired) const{
	return 5;
}

void BinTree::displaySideways() const {
   sideways(root, 0);
}

void BinTree::sideways(Node* current, int level) const {
   if (current != NULL) {
      level++;
      sideways(current->right, level);

      // indent for readability, 4 spaces per depth level 
      for(int i = level; i >= 0; i--) {
          cout << "    ";
      }

      cout << *current->data << endl;        // display information of object
      sideways(current->left, level);
   }
}

void BinTree::inorderHelper() const{

}

void BinTree::bstreeToArray(NodeData * bst [] ){
	int position; 
	toArrayHelper(bst, root, position);
}

/*

void BinTree::outputHelper(ostream &out, Node * current){
	if(current->left!=NULL && current->right!=NULL){
		outputHelper(out, current->left);
		cout << *current->data;
		outputHelper(out, current->right);
	}
	else if(current->left!=NULL && current->right == NULL){
		outputHelper(out, current->left);
		cout << *current->data;
	}
	else if(current->right!=NULL && current->left == NULL){
		cout << *current->data;
		outputHelper(out, current->right);
	} else {
		cout << *current->data;
	}
}*/

void BinTree::toArrayHelper(NodeData * toFill [] , Node * current, int position){
	if(current->left != NULL && current->right != NULL){
		toArrayHelper(toFill, current->left, position++);
		toFill[position] = current->data;
		toArrayHelper(toFill, current->right, position++);
	}
	else if(current->left != NULL && current->right == NULL){
		toArrayHelper(toFill, current->left, position++);
		toFill[position] = current->data;
	}
	else if(current->right != NULL && current->left == NULL){
		toFill[position] = current->data;
		toArrayHelper(toFill, current->right, position++);
	}
	else {
		toFill[position] = current->data;
	}
}
/*
void BinTree::arrayToBSTree(NodeData * arr []){
	int position = arr.length();
	NodeData * temp = arr[0];
		
}*/
