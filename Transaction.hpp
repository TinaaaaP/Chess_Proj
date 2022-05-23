#ifndef _TRANSACTION_HPP_
#define _TRANSACTION_HPP_
#include <iomanip>
#include <iostream>
#include <string>

class Transaction{
    public:
    //Constructor
    //
    Transaction(std::string item_name, unsigned int buy_day_date, unsigned int buy_month_date,
    unsigned int buy_year_date, unsigned int expiration_day_date, unsigned int expiration_month_date,
    unsigned int expiration_year_date, double item_amount);

    //Destructor
    //
    ~Transaction();

    std::string get_name() const;
    unsigned int get_buy_date() const;
    unsigned int get_buy_month() const;
    unsigned int get_buy_year() const;
    unsigned int get_expiration_day() const;
    unsigned int get_expiration_month() const;
    unsigned int get_expiration_year() const;
    double get_amount() const;

    Transaction * get_next();

    private:
    std::string name;

    unsigned int buy_day;
    unsigned int buy_month;
    unsigned int buy_year;

    unsigned int expiration_day;
    unsigned int expiration_month;
    unsigned int expiration_year;

    double amount;

    unsigned int item_id;

    Transaction *p_next;


};

#endif