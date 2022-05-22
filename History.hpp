#ifndef _HISTORY_HPP_
#define _HISTORY_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#include "Transaction.hpp"

class History {
public:
	// Constructor
	//
	History();

	// Destructor.
	//
	~History();

	// Read the transaction history from file.
	//
	void read_history();

	// Insert transaction in linked list.
	//
	void insert(Transaction *p_new_trans);

	// Sort using insertion sort.
	//
	void sort_by_buy_date();

    //
    void sort_by_expiration_date();

    //
    void sort_by_name();


	// Print the transaction history.
	//
	void print();

	Transaction *get_p_head();

private:
	Transaction *p_head;
};

#endif