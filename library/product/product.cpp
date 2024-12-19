#include "productList.h"
#include <iostream>
#include <fstream>
#include 

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

        void add(const Product_information& product) {
            root = insert(root, product);
            product_size++;
        }

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

            }

        }
};

