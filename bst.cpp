/****************************************************************************
*****************************************************************************
**********                                                         **********
**********                  Binary Search Tree                     **********
**********                                                         **********
**********                  C++ Implementation                     **********
**********                                                         **********
**********                      Writen By                          **********
**********                                                         **********
**********                     YAZAN OBEIDI                        **********
**********                                                         **********
*****************************************************************************
*****************************************************************************
*****************************************************************************
***                                                                       ***
***   Copyright 2015 Yazan Obeidi                                 		  ***
***                                                                       ***
***   This is free software: you can redistribute it and/or modify        ***
***   it under the terms of the GNU General Public License as published   ***
***   by the Free Software Foundation, either version 3 of the License,   ***
***   or (at your option) any later version.                              ***
***                                                                       ***
***   This program is distributed in the hope that it will be useful,     ***
***   but WITHOUT ANY WARRANTY; without even the implied warranty of      ***
***   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU    ***
***   General Public License for more details:                            ***
***    <http://www.gnu.org/licenses/>              						  ***
***                                                                       ***
****************************************************************************/

#include<iostream>
#include "bst.hpp"

typedef BinarySearchTree::data_type data_type;
	
BinarySearchTree::Node::Node(BinarySearchTree::data_type newval){ //new Node construct
	val = newval;
	right = NULL;
	left = NULL; //initialize left and right pointers to null
}
BinarySearchTree::BinarySearchTree(){ //bst construto
	root_ = NULL;
	size_ = 0;
}
///recursive delete function for ~bst()
void cleanUp(BinarySearchTree::Node* node) {
	if (node == NULL) return;
	cleanUp(node->left);
	cleanUp(node->right);	
	delete node;
};
BinarySearchTree::~BinarySearchTree() {
	cleanUp(root_);
}
bool BinarySearchTree::insert(data_type val) {
	if(size() == 0){//empty tree
		Node* newNode = new Node(val);
		root_ = newNode;
	}
	else {
		Node* nodeptr = root_; //node  pointer initially at root
		Node* newNode = new Node(val); //new node to insert
		
		while(true) {//find correct insertion location
			if(val < nodeptr->val) {
				if(nodeptr->left == NULL) break;
				nodeptr = nodeptr->left;
			} 
			else {
				if (nodeptr->right == NULL) break;
				nodeptr = nodeptr->right;	
			}
		}
		if(val < nodeptr->val) nodeptr->left = newNode; //insert in correct location
		else nodeptr->right = newNode;
	}
	size_++;
	return true;
}
bool BinarySearchTree::remove(data_type val) {
	if(!exists(val)) return false; //if value to be removed is not in tree, return
	Node* nodeptr = root_; //node  pointer initially at root
	Node* nodeptrparent = root_; //node pointer to parent of nodeptr, initially to root_
	while(true){//This function locates the node to delete and its parent. //works because val exists //see output below
		if (val == nodeptr->val) break;
		else if(val < nodeptr->val && nodeptr->left != NULL) {
			nodeptrparent = nodeptr;
			nodeptr = nodeptr->left;
		}
		else if (val >= nodeptr->val && nodeptr->right != NULL){
			nodeptrparent = nodeptr;
			nodeptr = nodeptr->right;
		}		
	}///OUTPUT: nodeptr poinsts to node to be deleted, nodeptrparent points to parent of node to be deleted
	//delete(): three cases, node is leaf, node has one child, node has two children
	if(nodeptr->left == NULL && nodeptr->right == NULL){ //node is a leaf
		if(size() == 1) root_ = NULL;
		else if(nodeptrparent->left->val == val) nodeptrparent->left = NULL; //if node is left of parent, set to null
		else nodeptrparent->right = NULL; //if node is right of parent, set to null
	} 
	else if(nodeptr->left != NULL && nodeptr->right == NULL) { ///node to delete has left child, comments identical to right child below
		Node* temp = nodeptr->left; //////only difference between this else if and the next
		if(nodeptrparent->left->val != NULL && nodeptrparent->left->val == val) nodeptrparent->left = temp; // null check not needed, double check
		else nodeptrparent->right = temp; 
		delete nodeptr;
	}
	else if(nodeptr->right != NULL && nodeptr->left == NULL) { //node to delete has right child
		Node* temp = nodeptr->right; //pointing to child of node to delete
		if(nodeptrparent->left->val != NULL && nodeptrparent->left->val == val) nodeptrparent->left = temp;//if nodeLeftParent, Parentright->nodechild
		else nodeptrparent->right = temp; //if node is right of parent, set node child to right of parent
		delete nodeptr;
	}
	else { 	//two children
		Node* temp = nodeptr->left; //pointer to find biggest node in left subtree
		Node* tempparent = nodeptr;
		while(temp->right != NULL) {
			tempparent = temp;
			temp = temp->right;
		} //now temp is pointed to largest node in left subtree
		nodeptr->val = temp->val; //exchange values
		tempparent->right = temp->left; //set temp node's children (if any) to its parents right
		delete temp;
	}
	size_--;
	return true;
}
bool BinarySearchTree::exists(data_type val) const {
	Node* nodeptr = root_; //node  pointer initially at root
	if(size() == 0) return false; //empty tree
	else {
		while(nodeptr != NULL) {//locate correct location
			if (val == nodeptr->val) return true;
			else if(val < nodeptr->val) { //if val is less than current node, go  left
				nodeptr = nodeptr->left;
			}
			else { //val is greater than current node, go right
				nodeptr = nodeptr->right;
			}		
		}
		return false;
	}
}
data_type BinarySearchTree::min() const { //return smallest value in t
	Node* node = root_;
	while(node->left != NULL) {
		node = node->left;
	}
	return node->val;
}
data_type BinarySearchTree::max() const { //return largest value in t
	Node* node = root_;
	while(node->right != NULL) {
		node = node->right;
	}
	return node->val;
}
unsigned int BinarySearchTree::size() const{ //return size of t
	return size_;
}
unsigned int BinarySearchTree::depth() const{ //return greatest branceh depth... 1 node, depth 
	Node* nodeptr = root_;
	return getNodeDepth(nodeptr);
}

//////////// print() helper functions...... /////////
void  preOrder(BinarySearchTree::Node* node) { // BinarySearchTree::Node with return NULL; works, as well as void with return; why
	if (node == NULL) return;
	std::cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);	
};
void inOrder(BinarySearchTree::Node* node) {
	if (node == NULL) return;
	preOrder(node->left);
	std::cout << node->val << " ";
	preOrder(node->right);	
	
};
void postOrder(BinarySearchTree::Node* node) {
	if (node == NULL) return;
	preOrder(node->left);
	preOrder(node->right);	
	std::cout << node->val << " ";
};
void BinarySearchTree::print(int traversal_type) const{
	Node* nodeptr = root_;
	//Traversal Types: 1 = preOrder, 2 = inOrder, 3 = postOrder
	switch (traversal_type) {
		case 1:
			preOrder(root_);
			break;
		case 2:
			inOrder(root_);
			break;
		case 3:
			postOrder(root_);
			break;
	}
}
int BinarySearchTree::getNodeDepth(Node* n) const {
	if(n == NULL) return 0;
	return 1 + std::max(getNodeDepth(n->left), getNodeDepth(n->right));
}
