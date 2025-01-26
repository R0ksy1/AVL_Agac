/**
* @file List.hpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#ifndef LIST_H
#define LIST_H

#include "Node.hpp"
#include <string>
using namespace std;

struct NodeList {
    Node* tree;
    NodeList* next;
    NodeList(Node* tree);
};

void ListeyeEkle(NodeList*& head, Node* tree);
NodeList* dosyaAc(const string& filename);
void listeSayfaYazdir(NodeList* head, NodeList* aktif, int baslangicIndex, int maxSayfaS);
void listedeGezin(NodeList*& head);

#endif
