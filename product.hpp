
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Product_information {
    int product_ID;
    string product_name;
    int product_quantity;
    float product_price;
};

struct Node {
    Product_information product;
    Node *left;
    Node *right;
};

class ProductList {
    public:
        Node *root;
        int product_size;

        // default constructor 
        ProductList () {
            root = NULL;
            product_size = 0;
        }

        // add to binary search tree
        Node *insert(Node *root, const Product_information& product) {
            if (root == NULL) {
                root = new Node;
                root->product = product;
                root->left = NULL;
                root->right = NULL;
            } else if (product.product_ID > root->product.product_ID) { // go right 
                root->right = insert(root->right, product);
            } else if (product.product_ID < root->product.product_ID) { // go left
                root->left = insert(root->left, product);
            }
            return root; 
        }

            // this is use as a function call in the main file 
        void add(const Product_information& product) {
            root = insert(root, product);
            product_size++;
        }


        // read from file csv to binary search tree
        void readData_toBST () {
            fstream productList_file;
            productList_file.open("productList.csv", ios::in);

            // check if the file is existed
            if (!productList_file.is_open()) {
                cout << "Cannot open file!" << endl;
                return;
            }

            string text;

            // skip header of the csv file
            getline(productList_file, text);

            while (getline(productList_file, text)) {
                stringstream ss(text);
                Product_information product;
                string token;

                // get ID of product
                getline(ss, token, ',');
                product.product_ID = stoi(token); // convert from string to interger 

                // get product name
                getline(ss,product.product_name, ',');

                // get product quantity
                getline(ss, token, ',');
                product.product_quantity = stoi(token);

                // get product price 
                getline(ss, token, ',');
                product.product_price = stof(token);

                add(product);

            }
            productList_file.close();

        }


        // display product with in-order traversal (LDR)
        void inOrder_traversal(Node *root, int &number, int who_enter) {
            
            if (root != NULL) {
                inOrder_traversal(root->left, number, who_enter);
                    if (who_enter == 2) {
                        // for user
                        cout << "| " << setw(5) << left << number
                            << " | " << setw(30) << left << root->product.product_name
                            << " | $ " << setw(12) << root->product.product_price
                            << " |\n";
                        number ++;
                    } else if (who_enter == 1) {
                        // for admin
                        cout << "| " << setw(10) << left << root->product.product_ID
                        << " | " << setw(5) << left << number
                        << " | " << setw(10) << left << root->product.product_ID
                        << " | " << setw(30) << left << root->product.product_name
                        << " | " << setw(10) << root->product.product_quantity
                        << " | " << setw(14) << root->product.product_price
                        << " |\n";

                    }
                inOrder_traversal(root->right, number, who_enter);
            }
        }
        void printout(int who_enter) {
            int number = 1;
            if (who_enter == 2) {
                // for user
                cout << "-----------------------------------------------------------\n";
                cout << "| " << setw(5) << left << "No."
                        << " | " << setw(30) << left << "Name"
                        << " | " << setw(14) << "Price"
                        << " |\n";
                cout << "-----------------------------------------------------------\n";
                inOrder_traversal(root, number, 2);
                cout << "-----------------------------------------------------------\n";
            } else if (who_enter == 1) {
                // for admin
                cout << "--------------------------------------------------------------------------------------------------\n";
                cout << "| " << setw(10) << left << "ID"
                        << " | " << setw(5) << left << "No."
                        << " | " << setw(10) << left << "ID"
                        << " | " << setw(30) << left << "Name"
                        << " | " << setw(10) << "Quantity"
                        << " | " << setw(14) << "Price"
                        << " |\n";
                cout << "--------------------------------------------------------------------------------------------------\n";
                inOrder_traversal(root, number, 1);
                cout << "--------------------------------------------------------------------------------------------------\n";

            }

        }

        // find product
    Node* findProductByNo(Node* root, int input, int& number) {
    if (root != NULL) {
        // Traverse left subtree
        Node* leftProduct = findProductByNo(root->left, input, number);
            if (leftProduct) return leftProduct;  // If found in the left subtree, return

        // Check if the current product matches the input number (No.)
        if (number == input) {
            return root;  // Product found, return the node
        }
        number++;  // Increment number for the next product

            // Traverse right subtree
        return findProductByNo(root->right, input, number);
    }
    return NULL;  // If product not found
}


};

