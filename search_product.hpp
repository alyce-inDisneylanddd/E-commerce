#include <iostream>
#include <cstdlib>

using namespace std;

void product_details(Node *productNode, int who_enter) {
    system ("cls");
    if (who_enter == 2) {
        cout << "\nProduct Details:\n";
        cout << "--------------------------\n";
        cout << "Name: " << productNode->product.product_name << endl;
        cout << "Price: $ " << productNode->product.product_price << endl;
        cout << "--------------------------\n";
    } else if (who_enter == 1) {
        cout << "\nProduct Details:\n";
        cout << "--------------------------\n";
        cout << "ID: " << productNode->product.product_ID << endl;
        cout << "Name: " << productNode->product.product_name << endl;
        cout << "Quantity: " << productNode->product.product_quantity << endl;
        cout << "Price: $ " << productNode->product.product_price << endl;
        cout << "--------------------------\n";
    }
}

void productDisplay_admin(Node *productNode) {
    system ("cls");
    cout << "\nProduct Details:\n";
    cout << "--------------------------\n";
    cout << "Name: " << productNode->product.product_name << endl;
    cout << "Price: $ " << productNode->product.product_price << endl;
    cout << "--------------------------\n";

}

// Function to print the full details of a selected product
void printProductDetails(Node* productNode, int who_enter) {
    if (productNode != NULL) {
        int quantity;
        // Print the full product details
        product_details(productNode, who_enter);
        cout << "\nEnter the quantity for this product: "; 
        cin >> quantity;
        // compare quantity and add it into cart
        // compare it in the class to check whether the product is still instock
        // after checking the stock; add the product and order quantity into the cart

    } else {
        cout << "Product not found.\n";
    }
}

// Function to handle the product selection and display its details
void select_product_user(ProductList &product) {
    // input: which product is selected
    int input;
    do {
        product.printout(2);  // Display the product list with numbers
        cout << "Choose your product (by No.): ";
        cin >> input;

        if (input < 1 || input > product.product_size) {
            system("cls");
            cout << "Invalid input. Currently, we have only <" << product.product_size << "> in the store!!\n";
        } else {
            int number = 1;  // Start with No. 1 for the first product
           Node* selectedProduct = product.findProductByNo(product.root, input, number);

            if (selectedProduct != NULL) {
                // Display the details of the selected product
                printProductDetails(selectedProduct, 2);
                // add to cart 

            }
        
        }
    } while (input < 1 || input > product.product_size);  // Continue until valid input
}

// use it to work with deletion and product updates
void select_product_admin (ProductList &product) {
    int input;
    do {
        product.printout(1);
        cout << "Choose your product (by No.): ";
        cin >> input;

        if (input < 1 || input > product.product_size) {
            system("cls");
            cout << "Invalid input. Currently, we have only <" << product.product_size << "> in the store!!\n";
        } else {
            int number = 1;  // Start with No. 1 for the first product
           Node* selectedProduct = product.findProductByNo(product.root, input, number);

            if (selectedProduct != NULL) {
                // Display the details of the selected product
                printProductDetails(selectedProduct, 1);
            }
        
        }

    } while (input < 1 || input > product.product_size); 

}


