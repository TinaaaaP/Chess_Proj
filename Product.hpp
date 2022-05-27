#ifndef _Product_HPP_
#define _Product_HPP_
#include <iomanip>
#include <iostream>
#include <string>

class Product
{
public:
    //Constructor
    //
    Product(std::string item_name, int buy_day_date, int buy_month_date,
            int buy_year_date, int expiration_day_date, int expiration_month_date,
            int expiration_year_date, int item_quantity, double item_price);

    //Destructor
    //
    ~Product();

    // Overloaded < operator.
    //
    bool operator<( Product const &other );

    std::string get_name() const;
    std::string get_type() const;
    int get_buy_date() const;
    int get_buy_month() const;
    int get_buy_year() const;
    int get_expiration_day() const;
    int get_expiration_month() const;
    int get_expiration_year() const;
    int get_quantity() const;
    double get_price() const;

    Product *get_next();

private:
    std::string name;
    std::string type;

    int buy_day;
    int buy_month;
    int buy_year;

    int expiration_day;
    int expiration_month;
    int expiration_year;

    int quantity;
    double price;

    int item_id;

    Product *p_next;
};

#endif