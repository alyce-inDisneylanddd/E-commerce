#include "product.hpp"
#include "search_product.hpp"
#include "home_page.hpp"
#include <iostream>

using namespace std;

int main () {
    ProductList product;
    product.readData_toBST();
    who_enter(product);

    // select_product(product);

    

    return 0;
}