#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

// function declaration
void who_enter(ProductList &product);




void press_anykey_to_retrun() {
    cout << "Press anykey to return...";
    getch();
}

void ask_for_input() {
    system("cls");
    cout << "Log in as " << endl;
    cout << "\t1. Admin" << endl;
    cout << "\t2. User" << endl;
    cout << "\t3. Exit the program" << endl;
}

void ask_to_buy() {
    system ("cls");
    cout << "Choose to: " << endl;
    cout << "\t1. Buy Product/ Add Product to Cart" << endl;
    cout << "\t2. View Cart" << endl;
    cout << "\t3. Exit" << endl;
}

void admin_product() {
    cout << "Choose to: " << endl;
    cout << "\t1. View Current Product" << endl;
    cout << "\t2. Add new product" << endl;
    cout << "\t3. Update Product" << endl;
    cout << "\t4. Delete Product" << endl;
    cout << "\t5. Get Sale Report" << endl;
    cout << "\t6. Exit" << endl;
}

void user(ProductList &product) {
    int input;
    
    do {
        system ("cls");
        ask_to_buy();
        cout << "Enter your choice: ";
        cin >> input;

        // add switch to control the input 
        switch (input) {
            case 1:
                // do sth with buy and add product
                system ("cls");
                select_product_user(product);
                break;
            
            case 2:
                // view there cart
                system ("cls");
                // add the printout function in cart library
                press_anykey_to_retrun();
                break;

            case 3: 
                who_enter(product);
                break;

            default: 
                if (input < 1 || input > 3) {
                    system("cls");
                    cout << "Invalid Input! Please input again!" << endl;
                }
                break;

        }
    }while (input < 1 || input > 3);

    // add switch to control the input 
}

void admin(ProductList &product) {
    int input;
    do {
        system ("cls");
        cout << "\n\tWelcome, Admin!\n" << endl;
        admin_product();
        cout << "Enter your choice: ";
        cin >> input;

        switch (input) {
            case 1:
                // display the in-stock product
                system("cls");
                product.printout(1);
                cout << "Products currently available in your inventory!\n" << endl;
                press_anykey_to_retrun();
                admin(product);
                break;

            case 3:
                // admin update the product information 
                system("cls");
                // this function is used to display back the product that admin wanted to update
                select_product_admin(product);
                break;
        }
        if (input < 1 || input > 6) {
            system("cls");
            cout << "Invalid Input! Please input again!" << endl;
        }
    } while (input < 1 || input > 6);

    // add switch to handle the input and to perform other task
}

void who_enter(ProductList &product) {
    int whoEnter;
      
    do {
        ask_for_input();
        cout << "Enter your choice: ";
        cin >> whoEnter;
        
        // using switch case to handle whether admin or user is entering this shop
        switch (whoEnter) {
            case 1:
                system("cls");
                admin(product); // Call the admin function
                break;

            case 2:
                system("cls");
                user(product); // Call the user function
                break;

            case 3:
                return; // Exit the program
                break;

            default:
                system ("cls");
                cout << "Invalid input. Please try again.\n"; // Handle invalid input
                break;
        }
    } while (whoEnter < 1 || whoEnter > 3);

}

