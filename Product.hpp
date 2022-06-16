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

    /* Overloaded < operator.
    
    If one date is earlier than the other date, then "<" and "<=" will return true, otherwise, return false
    For example, 

    date1 : 17-June-2022
    date2 : 18-June-2022
    date3 : 17-May-2022
    
    date1 < date2 would returen true
    date1 < date3 would return false
    */

    //for buy date
    bool operator < (Product const &other);

    //for expiration date
    bool operator <= ( Product const &other);

    //for name
    bool operator % ( Product const &other);

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

    void set_next(Product * next);

    Product * get_next() const;

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