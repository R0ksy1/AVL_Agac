/**
* @file Helper.cpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#include "../include/Helper.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int myMaximum(int a, int b) {
    return (a > b) ? a : b;
}

int myMinimum(int a, int b) {
    return (a < b) ? a : b;
}

void sabitAlanYazdir(const string& value, int fieldWidth) {
    cout << "-";
    int len = (int)value.size();
    cout << value;
    if (len < fieldWidth) {
        for (int i = 0; i < fieldWidth - len; i++) {
            cout << " ";
        }
    }
    cout << "-   ";
}

string sonUcDigit(void* ptr) {
    if (ptr == nullptr) return " 0 ";
    ostringstream oss;
    oss << ptr;
    string addr = oss.str();
    int len = (int)addr.size();
    if (len < 3) return addr;
    return addr.substr(len - 3);
}

void ekraniTemizle() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
