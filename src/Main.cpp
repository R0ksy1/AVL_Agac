/**
* @file Main.cpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#include "../include/List.hpp"
#include "../include/Helper.hpp"
#include <string>
using namespace std;
int main() {
    const string filename = "agaclar.txt";
    NodeList* head = dosyaAc(filename);
    listedeGezin(head);
    return 0;
}
