#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
    double result;
    
  cout << "Введите арифметическое выражение: ";
  cin >> expression;
  cout << expression << endl;
    
  try 
  {
	   CMyPostfix postf(expression);
	  cout << "Арифметическое выражение: " << postfix.getInf() << endl;
	  postf.ToPostf();
	  cout << "Постфиксная форма: " << postfix.getPostf() << endl;
      result = postf.Calc();
	  cout << "Результат выражения: " << resulth << endl;
  }
  catch (const char* s)
  {
	  cout << s;
  }
  return 0;
}
