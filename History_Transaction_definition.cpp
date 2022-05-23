#include <cassert>
#include <iomanip>
#include <iostream>

#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

//Constructor
Transaction::Transaction(std::string item_name, unsigned int buy_day_date, unsigned int buy_month_date,
    unsigned int buy_year_date, unsigned int expiration_day_date, unsigned int expiration_month_date,
    unsigned int expiration_year_date, double item_amount){
        name = item_name;
        buy_day = buy_day_date;
        buy_month = buy_month_date;
        buy_year = buy_year_date;
        expiration_day = expiration_day_date;
        expiration_month = expiration_month_date;
        expiration_year = expiration_year_date;
        amount = item_amount;
}


//Destructor
Transaction::~Transaction(){
// need to do something here
}

//memeber functions for transaction - get values
std::string Transaction::get_name() const {return name;};
unsigned int Transaction::get_buy_date() const {return buy_day;};
unsigned int Transaction::get_buy_month() const {return buy_month;};
unsigned int Transaction::get_buy_year() const {return buy_year;};
unsigned int Transaction::get_expiration_day() const {return expiration_day;};
unsigned int Transaction::get_expiration_month() const {return expiration_month;};
unsigned int Transaction::get_expiration_year() const {return expiration_year;};
double Transaction::get_amount() const {return amount;};



////////////////////////////////////////////////////////////////////////////////
// Definitions for History class
////////////////////////////////////////////////////////////////////////////////
//
//

//Constructor
//
History::History(){
    this->p_head = nullptr;
}

//Destructor
//
History::~History(){
    Transaction * p_through = p_head;
    if(p_head != nullptr){
        while(p_through -> get_next() != nullptr){
            Transaction * p_tmp = p_through -> get_next();
            delete p_through;
            p_through = p_tmp;
        }
    }
    delete p_through;
    p_through = nullptr;
    p_head = nullptr;
}

void History::read_history(){

}


void History::insert(Transaction *p_new_trans){

}


void History::sort_by_buy_date(){

}


void History::sort_by_expiration_date(){

}


void History::sort_by_name(){

}

void History::print(){

}

Transaction * History::get_p_head(){
    return p_head;
}