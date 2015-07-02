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
#include"bst.hpp"

int main() {

	//initialize binary search tree structure
	BinarySearchTree bst;
	
	//The following code simply provides a demo for the BST class:
	
	//flags for demo
	char continue_flag;
	bool valid_choice = false;
	char choice;
	
	std::cout << "Welcome to a C++ BST Implementation Demo!\n";
	
	//Main loop where users can interact with BST object
	while(continue_flag != 'n') {
	
		std::cout << "i - insert\nr - remove\ns - get size\np - print bst to console\nq - quit\n";
			
		// Menu
		do {
			std::cin >> choice;
			switch (choice) {
			case 'i':
				//insert
				int insert_value;
				std::cout << "Enter a value to insert: ";
				std::cin >> insert_value;
				if(bst.insert(insert_value)) std::cout << "\nValue successfully inserted.\n";
				else std::cout << "\nValue failed to insert.\n";
				valid_choice = true;
				break;
			case 'r':
				int remove_value;
				std::cout << "Enter a value to remove: ";
				std::cin >> remove_value;
				if(bst.remove(remove_value)) std::cout << "\nValue successfully removed.\n";
				else std::cout << "\nValue failed to remove.\n";
				valid_choice = true;
				break;
			case 's':
				//return size
				std::cout << "Size of BST: ";
				std::cout << bst.size() << std::endl;
				valid_choice = true;
				break;
			case 'p':
				int traversal_type;
				std::cout << "Please select:\n1 - Pre Order\n2 - In Order\n3 - Post Order\n";
				std::cin >> traversal_type;
				std::cout << std::endl;
				bst.print(traversal_type);
				std::cout << std::endl;
				valid_choice = true;
				break;
			case 'q':
				std::cout << "\nQuiting BST Demo...\n\n";
				return(0);
			default:
				std::cout << "You did not enter a valid choice! Please try again: ";
				valid_choice = false;
				break;
			} 
			std::cout << std::endl;
		} while(valid_choice == false); //prompt if input is incorrect
	}
}
