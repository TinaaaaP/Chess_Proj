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

Product *Product::get_next() const
{
    return this->p_next;
}
void Product::set_next(Product *next)
{
    this->p_next = next;
};

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

void Shopping_List::insert(Product *p_new_trans) //at the head of the linked list
{
    //this pointer in member function of a class points to the address of the instance of the class it self
    //but no need to use this now because we have access to the private member variable of the class
    if (p_head == nullptr)
    {
        p_head = p_new_trans;
        return;
    }
    p_new_trans->set_next(p_head);
    p_head = p_new_trans;
}
///////////////////

///////////Jerry

// bool Product::operator<(Product const &other)
// {
//     if (this->buy_year < other.buy_year)
//     {
//         return true;
//     }
//     else if (this->buy_year == other.buy_year)
//     {
//         if (this->buy_month < other.buy_month)
//         {
//             return true;
//         }
//         else if (this->buy_month == other.buy_month)
//         {
//             if (this->buy_day < other.buy_day)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool Product::operator<=(Product const &other)
{
    if (this->expiration_year < other.expiration_year)
    {
        return true;
    }
    else if (this->expiration_year == other.expiration_year)
    {
        if (this->expiration_month < other.expiration_month)
        {
            return true;
        }
        else if (this->expiration_month == other.expiration_month)
        {
            if (this->expiration_day < other.expiration_day)
            {
                return true;
            }
        }
    }
    return false;
}

//apply merge sort
Product *merge(Product *lista, Product *listb);
Product *merge_exp(Product *lista, Product *listb);

Product *merge_sort(Product *list, bool buy_or_exp)
{

    //for buy_or_exp
    //true: compare buy_date, false:compare expiration_date

    //if there is only one product in the list, no need to sort, return the list

    Shopping_List *my_list = new Shopping_List();

    if (list->get_next() == nullptr)
    {
        return list;
    }


    //else, divide the list into half, first_half and second_half

    Product *first_half = list;
    Product *second_half = list;
    Product *prev_second_half = nullptr;
    Product *p_through = list;

    
    //algorithm that give the address of the head of the saecond half
    while (p_through != nullptr && p_through->get_next() != nullptr)
    {
        p_through = p_through->get_next()->get_next();
        prev_second_half = second_half;
        second_half = second_half->get_next();

    }

    //break the first_half with the second_half
    //by setting the last one product in the first half point to null

    prev_second_half->set_next(nullptr);

    //keep dividing until there isn only one product in each linked list


    Product *head_new = nullptr;

    if (buy_or_exp)
    {
        first_half = merge_sort(first_half, true);
        second_half = merge_sort(second_half, true);
        head_new = merge(first_half, second_half);

        // my_list->set_head(head_new);
        // my_list->print();
        // std::cout << std::endl;

    }
    else
    {
        first_half = merge_sort(first_half, false);
        second_half = merge_sort(second_half, false);
        head_new = merge_exp(first_half, second_half);
    }

    return head_new;
}

Product *merge(Product *lista, Product *listb)
{

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

    Product *listc = nullptr;

    Product *p_through_a = lista;
    Product *p_through_b = listb;
    Product *p_through_c = listc;

    std::cout << "merge works here" << std::endl;

    while (p_through_a != nullptr && p_through_b != nullptr)
    {
        std::cout << p_through_a->get_buy_year() << "/" << p_through_a->get_buy_month() << "/" << p_through_a->get_buy_date();
        std::cout << " compare with " << p_through_b->get_buy_year() << "/" << p_through_b->get_buy_month() << "/" << p_through_b->get_buy_date();
        std::cout << std::endl;
        std::cout << "compare result: " << (p_through_a < p_through_b) << std::endl; 

        if (*p_through_a < *p_through_b)
        {
            if (p_through_c == nullptr)
            {
                p_through_c = p_through_a;
                listc = p_through_a;
            }
            else
            {
                p_through_c->set_next(p_through_a);
                p_through_c = p_through_c->get_next();
            }
            p_through_a = p_through_a->get_next();
        }
        else
        {
            if (p_through_c == nullptr)
            {
                p_through_c = p_through_b;
                listc = p_through_b;
            }
            else
            {
                p_through_c->set_next(p_through_b);
                p_through_c = p_through_c->get_next();
            }
            p_through_b = p_through_b->get_next();
        }
    }
    // if lista is not empty
    if (p_through_a != nullptr)
    {
        p_through_c->set_next(p_through_a);
    }
    else
    {
        p_through_c->set_next(p_through_b);
    }

    return listc;
}

Product *merge_exp(Product *lista, Product *listb)
{

    //same algorithm but for expiration date instead of buy date

    Product *listc = nullptr;

    Product *p_through_a = lista;
    Product *p_through_b = listb;
    Product *p_through_c = listc;

    while (p_through_a != nullptr && p_through_b != nullptr)
    {
        if (*p_through_a <= *p_through_b)
        {
            if (p_through_c == nullptr)
            {
                p_through_c = p_through_a;
                listc = p_through_a;
            }
            else
            {
                p_through_c->set_next(p_through_a);
                p_through_c = p_through_c->get_next();
            }
            p_through_a = p_through_a->get_next();
        }
        else
        {
            if (p_through_c == nullptr)
            {
                p_through_c = p_through_b;
                listc = p_through_b;
            }
            else
            {
                p_through_c->set_next(p_through_b);
                p_through_c = p_through_c->get_next();
            }
            p_through_b = p_through_b->get_next();
        }
    }
    // if lista is not empty
    if (p_through_a != nullptr)
    {
        p_through_c->set_next(p_through_a);
    }
    else
    {
        p_through_c->set_next(p_through_b);
    }

    return listc;
}

void Shopping_List::sort_by_buy_date()
{
    std::cout << "p0" << std::endl;
    Product *head_new = merge_sort(this->get_p_head(), true);
    this->set_head(head_new);
}

void Shopping_List::sort_by_expiration_date()
{
    Product *head_new = merge_sort(this->get_p_head(), false);
    this->set_head(head_new);
}

////////////////////

///////////////Tina
void Shopping_List::sort_by_name()
{
}
////////////////

///////////////Anthony
Shopping_List* Shopping_List::sort_by_type()
{
    this->sort_by_name();

    Product* p_traverse_front = get_p_head();
    Product* p_traverse_back = get_p_head();

    Shopping_List *grouped_by_type_list = new Shopping_List;

    int quantity_count;
    double total_price;

    while(p_traverse_back != nullptr && p_traverse_front != nullptr){

        while(p_traverse_front != nullptr  && p_traverse_front->get_name() == p_traverse_back->get_name()){
            quantity_count += p_traverse_front->get_quantity();
            total_price += p_traverse_front->get_quantity() * p_traverse_front->get_price();
            p_traverse_front = p_traverse_front->get_next();
        }

        Product *ProductWithQuantity = new Product(p_traverse_back->get_name(), -1, -1, -1, -1, -1, -1, quantity_count, total_price);
        grouped_by_type_list->insert(ProductWithQuantity);
        quantity_count = 0;
        total_price = 0;
        p_traverse_back = p_traverse_front;
    }
    return grouped_by_type_list;
}

//Apple Orange Cola Apple Cola Orange  <--original shopping list
//Apple->3 Cola->2 Orange ->2       <--new list
//Apple Apple Apple Cola Cola Orange Orange      <--original list

//////////////////Anthony
void Shopping_List::print()
{
    Product *temp_head = this->p_head;
    

    while (temp_head != nullptr)
    {
        cout << " Item Name: ";
        cout << "- " + temp_head->get_name();
        cout << "  Quantity: ";
        cout << temp_head->get_quantity();

        if(temp_head->get_buy_year() != -1 && temp_head->get_buy_year() != 0){
            cout << "  Item Price: ";
            cout << temp_head->get_price();
        }else{
            cout << "  Total Price: ";
            cout << temp_head->get_price();
        }

//        cout << "  Type: ";
//        cout << p_head->get_type();


        if (temp_head->get_buy_year() != -1 && temp_head->get_buy_year() != 0)
        {
            cout << "   Bought on: ";
            cout << temp_head->get_buy_year();
            cout << '/';
            cout << temp_head->get_buy_month();
            cout << '/';
            cout << temp_head->get_buy_date();
        }

        if (temp_head->get_expiration_year() != -1 && temp_head->get_expiration_year() != -0)
        {
            cout << "Expires on:";
            cout << temp_head->get_expiration_year();
            cout << '/';
            cout << temp_head->get_expiration_month();
            cout << '/';
            cout << temp_head->get_expiration_day();
        }

        temp_head = temp_head->get_next();
        cout << endl;
    }
}

Product *Shopping_List::get_p_head()
{
    return p_head;
}

void Shopping_List::set_head(Product *new_head)
{
    this->p_head = new_head;
}
