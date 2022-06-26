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
    std::cout << "User Menu:" << std::endl;
    std::cout << "[I]: insert" << std::endl;
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
