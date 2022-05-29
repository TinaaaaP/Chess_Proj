#include <cassert>
#include <iomanip>
#include <iostream>

#include "Shopping_List.hpp"
#include "Product.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Definitions for Product class
////////////////////////////////////////////////////////////////////////////////
//
//

//Constructor
Product::Product(std::string item_name, int buy_day_date, int buy_month_date,
                 int buy_year_date, int expiration_day_date, int expiration_month_date,
                 int expiration_year_date, int item_quantity, double item_price)
{
    name = item_name;
    buy_day = buy_day_date;
    buy_month = buy_month_date;
    buy_year = buy_year_date;
    expiration_day = expiration_day_date;
    expiration_month = expiration_month_date;
    expiration_year = expiration_year_date;
    quantity = item_quantity;
    price = item_price;
    this->p_next = nullptr;
}

//Destructor
Product::~Product()
{
    // need to do something here
}

//memeber functions for Product - get values
std::string Product::get_name() const { return name; };
std::string Product::get_type() const { return type; };
int Product::get_buy_date() const { return buy_day; };
int Product::get_buy_month() const { return buy_month; };
int Product::get_buy_year() const { return buy_year; };
int Product::get_expiration_day() const { return expiration_day; };
int Product::get_expiration_month() const { return expiration_month; };
int Product::get_expiration_year() const { return expiration_year; };
int Product::get_quantity() const { return quantity; };
double Product::get_price() const { return price; };

////////////////////////////////////////////////////////////////////////////////
// Definitions for Shopping_List class
////////////////////////////////////////////////////////////////////////////////
//
//

//Constructor
//
Shopping_List::Shopping_List()
{
    this->p_head = nullptr;
}

//Destructor
//
Shopping_List::~Shopping_List()
{
    Product *p_through = p_head;
    if (p_head != nullptr)
    {
        while (p_through->get_next() != nullptr)
        {
            Product *p_tmp = p_through->get_next();
            delete p_through;
            p_through = p_tmp;
        }
    }
    delete p_through;
    p_through = nullptr;
    p_head = nullptr;
}

void Shopping_List::read_Shopping_List()
{
}

/////////Anthony

void Shopping_List::insert(Product *p_new_trans)
{
}
///////////////////

///////////Jerry

bool Product::operator<(Product const &other)
{
    if (this->buy_year < other.buy_year)
    {
        return true;
    }
    else if (this->buy_year == other.buy_year)
    {
        if (this->buy_month < other.buy_month)
        {
            return true;
        }
        else if (this->buy_month == other.buy_month)
        {
            if (this->buy_day < other.buy_day)
            {
                return true;
            }
        }
    }
    return false;
}

//apply merge sort
Product * merge_sort (Product * list){

    //if there is only one product in the list, no need to sort, return the list
    if(list->get_next() == nullptr){
        return list;
    }

    //else, divide the list into half, shopping_list1 and shopping_list2

    //shopping_list1 = mergesort(shopping_list1)
    //shopping_list2 = mergesort(shopping_list2)


    //Product * head_new = merge(shopping_list1.get_p_head(), shopping_list2.get_p_head())

    //return head_new

    //have not done yet
    return list;

}

Product * merge (Product * lista, Product * listb){

    /*
    implement seudo algorithm here:

    Product * listc ;

    while(lista and listb still have elements){
        if(a[0] < b[0]){
            append a[0] to c
            remove a[0] from a
        }else{
            append b[0] to c
            remove b[0] from b
        }
    }

    either a or b is empty at this point

    while(lista has element){
        append a[0] to c
        remove a[0] from a
    }

    while(listb has element){
        append b[0] to c
        remove b[0] from b
    }

    if it is linked list, we can directly, it seems that we can directly merge two list

    return the head of listc
    */
   return nullptr;
}

void Shopping_List::sort_by_buy_date()
{
    
}

void Shopping_List::sort_by_expiration_date()
{
}

////////////////////

///////////////Tina
void Shopping_List::sort_by_name()
{
}
////////////////

///////////////Anthony
void Shopping_List::sort_by_type()
{
}

//Apple Orange Cola Apple Cola Orange  <--original shopping list
//Apple->3 Cola->2 Orange ->2       <--new list
//Apple Apple Apple Cola Cola Orange Orange      <--original list

//////////////////Anthony
void Shopping_List::print()
{
    while (this->p_head != nullptr)
    {
        cout << " Item Name: ";
        cout << "- " + p_head->get_name();
        cout << "  Quantity: ";
        cout << p_head->get_quantity();
        cout << "  Price: ";
        cout << p_head->get_price();
        cout << "  Type: ";
        cout << p_head->get_type();
        cout << "   Bought on: ";

        if (p_head->get_buy_year() != -1 && p_head->get_buy_year() != 0)
        {
            cout << p_head->get_buy_year();
            cout << '/';
            cout << p_head->get_buy_month();
            cout << '/';
            cout << p_head->get_buy_date();
        }

        if (p_head->get_expiration_year() != -1 && p_head->get_expiration_year() != -0)
        {
            cout << "Expires on:";
            cout << p_head->get_expiration_year();
            cout << '/';
            cout << p_head->get_expiration_month();
            cout << '/';
            cout << p_head->get_expiration_day();
        }

        p_head = p_head->get_next();
        cout << endl;
    }
}

Product *Shopping_List::get_p_head()
{
    return p_head;
}