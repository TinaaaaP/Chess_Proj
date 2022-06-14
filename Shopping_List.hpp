#ifndef _Shopping_List_HPP_
#define _Shopping_List_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "Product.hpp"

class Shopping_List
{
public:
	// Constructor
	//
	Shopping_List();

	// Destructor.
	//
	~Shopping_List();

	// Read the Product Shopping_List from file.
	//
	void read_Shopping_List();

	// Insert Product in linked list.
	//
	void insert(Product *p_new_trans);

	// Sort using insertion sort.
	//
	void sort_by_buy_date();

	//
	void sort_by_expiration_date();

	//
	void sort_by_name();

	//
	Shopping_List* sort_by_type();

	// Print the Product Shopping_List.
	//
	void print();

	Product *get_p_head();

	// Product *function_name();

	void set_head(Product *new_head);

private:
	// void set_head(Product *new_head);
	Product *p_head;
};

#endif