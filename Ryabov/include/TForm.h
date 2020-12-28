#pragma once
#include "stack.h"

#include <string>
#include <iostream>
using namespace std;

class TForm
{
    string inf;
    string postf;

    string operations = "+-*/^";
    int priority[5] = { 1,1,2,2,3 };

public:
    TForm(string s = "a+b");

    bool Correct(string s);

    string getInf() { return inf; }
    string getPostf() { return postf; }
    string To_Inf();
    double Calculate();

    
};
