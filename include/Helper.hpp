/**
* @file Helper.hpp
* @description interaktif bir arayuzle birlikte agaclar arasinda gezindigimiz ve gorsellestirebildigimiz bir programdir.
* @course 2C
* @assignment 2. odev
* @date 15.12.2024
* @author Yigit Talha Adagulu ||| yigit.adagulu@ogr.sakarya.edu.tr
*/

#ifndef HELPER_H
#define HELPER_H

#include <string>
using namespace std;

int myMaximum(int a, int b);
int myMinimum(int a, int b);
void sabitAlanYazdir(const string& value, int fieldWidth = 5);
string sonUcDigit(void* ptr);
void ekraniTemizle();

#endif
