/**
* @file Node.hpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Node {
    string data;
    bool isNumeric;
    Node* left;
    Node* right;

    Node(const string& value);
};

Node* BSTekle(Node* root, char c);
void AgacAynala(Node* root);
int agacDegerHesapla(Node* root);


#endif
