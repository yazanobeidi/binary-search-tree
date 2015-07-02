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

#ifndef BST_HPP
#define BST_HPP

class BinarySearchTree {
	public:
 	 //set data type
 	 typedef int data_type;

	  struct Node {
	    // sets left and right children to NULL, and initializes val.
	    Node(data_type newval);
	    
	    data_type val;  // Value of the node.
	    Node* left;    // Pointer to the left node.
	    Node* right;   // Pointer to the right node.
	  };
	
	private:
	  friend class BinarySearchTreeTest;
	
	  // Optional function that recursively gets the maximum depth for a given node. 
	  int getNodeDepth(Node* n) const;
	  
	  // Pointer to the root node of the tree.
	  Node* root_;
	  // Number of nodes in the tree.
	  unsigned int size_;
	
	  // Sets copy constructor and assignment operator to private.
	  BinarySearchTree(const BinarySearchTree& other) {}
	  BinarySearchTree& operator=(const BinarySearchTree& other) {}
	  
	public:
	  // Default constructor to initialize the root.
	  BinarySearchTree();
	  // Destructor. Deallocates memory space allocated for the binary search tree. 
	  ~BinarySearchTree();
	  
	  // Returns the number of nodes in the tree. 
	  unsigned int size() const;
	  // Returns the maximum value of a node in the tree. Should not be called on empty tree	
	  data_type max() const;
	  // Returns the minimum value of a node in the tree. Should not be called on empty tree
	  data_type min() const;
	  // Returns the maximum depth of the tree. Should not be called on empty tree
	  unsigned int depth() const;
	  // You can print the tree in whatever order you prefer.
	  void print(int traversal_type) const;
	  // Returns true if a node with the value val exists in the tree; otherwise, 
	  // it returns false.
	  bool exists(data_type val) const;
	  
	  // Inserts the value val into the tree. Returns false if val already exists in 
	  // the tree, and true otherwise.
	  bool insert(data_type val);
	  // Removes the node with the value val from the tree. Returns true if successful, 
	  // and false otherwise.
	  bool remove(data_type val);
};

#endif
