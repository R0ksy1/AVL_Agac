/**
* @file Node.cpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#include "../include/Node.hpp"
#include <string>
using namespace std;

static int ozelToplam(Node* root, bool isSolCocuk) {
    if (!root) return 0;
    int factor = isSolCocuk ? 2 : 1;
    int val = (int)root->data[0];
    return factor * val
           + ozelToplam(root->left, true)
           + ozelToplam(root->right, false);
}

Node::Node(const string& value) : data(value), left(nullptr), right(nullptr) {
    isNumeric = true;
    for (char c : value) {
        if (!isdigit(c)) {
            isNumeric = false;
            break;
        }
    }
}

Node* BSTekle(Node* root, char c) {
    if (!root) {
        Node* newNode = new Node(string(1, c));
        return newNode;
    }

    if (c < root->data[0]) {
        root->left = BSTekle(root->left, c);
    }
    else if (c > root->data[0]) {
        root->right = BSTekle(root->right, c);
    }
    else {
        return root;
    }

    return root;
}

void AgacAynala(Node* root) {
    if (!root) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    AgacAynala(root->left);
    AgacAynala(root->right);
}

int agacDegerHesapla(Node* root) {
    if (!root) return 0;
    return ozelToplam(root, false);
}
