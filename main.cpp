#include <iostream>
#include "Shopping_List.hpp"
#include "Product.hpp"
#include "Shopping_List_Product_definition.cpp"
using namespace std;

/*
下周一 5/30
Tina:


Anthony:


Jerry:


*/

/*
while

welcome

 user/password[option]
 user menu
 error/success

quit/end line/license

*/

int main()
{

std::cout << "Welcome to ..." << std::endl;

bool program_running = true;

while (program_running)
{

    // file reader? 

    Shopping_List *newList = new Shopping_List();
    std::cout << "User Menu:" << std::endl;
    std::cout << "[I]: insert   [S]: sort   [P]: print  [C]: clear   [Q]: quit" << std::endl;
    char menuInput;
    std::cin >> menuInput;
    switch (menuInput){
        // insert
        case 'I':
        case 'i':{
            bool entering = true;
            std::string item_name;
            int buy_day_date; int buy_month_date; int buy_year_date;
            int expiration_day_date; int expiration_month_date; int expiration_year_date;
            int item_quantity;
            double item_price;
            while (entering){
                std::cout << "Enter name : " << std::endl;
                std::cin >> item_name;
                std::cout << "Enter buy date : [T]: use today's date    [M]: enter date manually" << std::endl;
                char buyDateOption;
                std::cin >> buyDateOption;
                if (buyDateOption == 'T' || buyDateOption == 't') {
                    
                    // get current time

                } else if (buyDateOption == 'M' || buyDateOption == 'm') {
                    std::cout << "Please enter buy date as (yyyy mm dd)" << std::endl;
                    std::cin >> buy_year_date >> buy_month_date >> buy_day_date;

                    // add constraints to date

                } else {
                    std::cout << "Invalid Input" << std::endl;
                    continue;
                }
                std::cout << "Enter expiration date as (yyyy mm dd)" << std::endl;
                std::cin >> expiration_year_date >> expiration_month_date >> expiration_day_date;

                // add constraints to date

                std::cout << "Enter quantity" << std::endl;
                std::cin >> item_quantity;

                // add unit?/conversion?

                std::cout << "Enter price" << std::endl;
                std::cin >> item_price;

                // add unit?/conversion?

                entering = false;
            }
            Product *input = new Product(item_name, buy_day_date, buy_month_date, buy_year_date, expiration_day_date, expiration_month_date, expiration_year_date, item_quantity, item_price);
            std::cout << item_name;
            
            // add detailed error handling

            // try {
                newList->insert(input);
            //     std::string error = "error";
            //     throw error; 
            // }
            // catch (string error) {
            //     std::cout << error << " Please retry" << std::endl;
            //     continue;
            // }
            break;
        }
        // sort
        case 's':
        case 'S':{
            std::cout << "Sort by: [N]: name  [T]: type  [B]: buy date [E]: expiry date" << std::endl;
            char sortType;
            std::cin >> sortType;
            bool sorting = true;
            while (sorting){
                switch (sortType){
                    case 'n':
                    case 'N':{
                        std::cout << "Sorting by name........" << std::endl;
                        try {
                            newList->sort_by_name();
                            sorting = false;
                            std::string error = "error";
                            throw error; 
                        }
                        catch (string error) {
                            std::cout << error << " Please retry" << std::endl;
                            continue;
                        }
                        break;
                    }
                    case 't':
                    case 'T':{
                        std::cout << "Sorting by type........" << std::endl;
                        try {
                            newList->sort_by_type();
                            sorting = false;
                            std::string error = "error";
                            throw error; 
                        }
                        catch (string error) {
                            std::cout << error << " Please retry" << std::endl;
                            continue;
                        }
                        break;
                    }
                    case 'b':
                    case 'B':{
                        std::cout << "Sorting by buy date........" << std::endl;
                        try {
                            newList->sort_by_buy_date();
                            sorting = false;
                            std::string error = "error";
                            throw error; 
                        }
                        catch (string error) {
                            std::cout << error << " Please retry" << std::endl;
                            continue;
                        }
                        break;
                    }
                    case 'e':
                    case 'E':{
                        std::cout << "Sorting by expiry date........" << std::endl;
                        try {
                            newList->sort_by_expiration_date();
                            sorting = false;
                            std::string error = "error";
                            throw error; 
                        }
                        catch (string error) {
                            std::cout << error << " Please retry" << std::endl;
                            continue;
                        }
                        break;
                    }
                    default:{
                        std::cout << "Error: please retry" << std::endl;
                        continue;
                    }
                }
            }
            std::cout << "List sorted." << std::endl;
            break;
        }
        // print
        case 'p':
        case 'P':{
            newList->print(); 
            break;
        }
        // clear
        case 'c':
        case 'C':{
            delete newList;
            Shopping_List *newList = new Shopping_List();
            break;
        }
        // quit
        case 'q':
        case 'Q':{
            program_running = false;
            std::cout << "Thanks for using." << std::endl;
            delete newList;
            
            // document handling

            break;
        }
        // invalid input
        default:{
            std::cout << "Invalid Input." << std::endl;
            break;
        }
    }
}


/*
//Anthony Testing the sort_by_type function

    Shopping_List *list = new Shopping_List();

    Product *tester1 = new Product("Aaa", 03, 05, 2003, 017, 06, 2003, 5, 23.3);
    Product *tester2 = new Product("Apple", 02, 05, 2003, 04, 06, 2003, 5, 23.3);
    Product *tester3 = new Product("Danny", 03, 05, 1999, 22, 10, 2002, 4, 23.3);
    Product *tester4 = new Product("Danny", 03, 05, 2022, 24, 03, 2003, 10, 19);
    Product *tester5 = new Product("Orange", 30, 04, 2003, 04, 06, 2003, 1, 19);
    Product *tester6 = new Product("Banana", 01, 05, 2003, 10, 06, 1999, 7, 19);
    Product *tester7 = new Product("Orange", 01, 05, 2003, 03, 05, 2003, 7, 19);
    Product *tester8 = new Product("Apple", 02, 05, 2003, 03, 05, 2003, 7, 19);
    Product *tester9 = new Product("Aab", 02, 05, 2003, 03, 05, 2003, 7, 19);

    list->insert(tester1);
    list->insert(tester2);
    list->insert(tester3);
    list->insert(tester4);
    list->insert(tester5);
    list->insert(tester6);
    list->insert(tester7);
    list->insert(tester8);
    list->insert(tester9);
    // list->print();

    list->sort_by_buy_date();
    list->print(); 

    std::cout << std::endl;

    list->sort_by_expiration_date();
    list->print();
    std::cout << std::endl;
    // bool smaller1 = *tester4 < *tester5;
    // bool smaller2 = tester7 < tester8;
    // std::cout << smaller1 << std::endl;
    // std::cout << smaller2 << std::endl;
    list->sort_by_name();
    list->print();
    std::cout << std::endl;

    Shopping_List* list1;

    list1 = list->sort_by_type();
    list1->print();
    std::cout << std::endl;
/*

abcde
fghij
klmno
pqrst
uvwxy
z

Apple
1*10^5 + 16*10^4 + 16*10^3 + 12*10^2 + 5*10 = 277250

Banana
2*10^5 + 1*10^4 + 14*10^3 + 1*10^2 + 14*10 = 224240

*/

    return 0;
}
