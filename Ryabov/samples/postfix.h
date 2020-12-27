#pragma once

#include <string>
#include <iostream>
#include "stack.h"

using namespace std;

class CMyPostfix
{
  string inf;
  string postf;
  string op = "+-*/^";
    
  int priority[5] = {1,1,2,2,3};
  bool Icorrect(string str);
public:
  TPostf(string inf1 = "a+b")
  {
	 if (!Icorrect(inf1))
		  throw std::logic_error("Incorrect ");
	 for (int i = 0; i < inf1.length(); i++)
	  if (inf1[i] != ' ')
		 inf += inf1[i];
	 if (inf.length() < 1)
		 throw std::logic_error("length error");
  }
  string getInf() { return inf; }
  string getPostf() { return postf; }
  string ToPostf();
  double Calc(); 
};
