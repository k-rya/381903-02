  
#include <iostream>
#include <string>
#include "TForm.h"

using namespace std;

int main()
{
  string tmp;
    double res;
    
  cout << "Введите арифметическое выражение: ";
  cin >> tmp;
  cout << tmp << endl;
    
  try 
  {
	  TForm f(tmp);
	  cout << "Арифметическое выражение: " << f.getInf() << endl;
	  f.To_Postf();
	  cout << "Постфиксная форма: " << f.getPostf() << endl;
      res = f.Calculate();
	  cout << "Результат выражения: " << res << endl;
  }
  catch (const char* s)
  {
	  cout << s;
  }
  return 0;
}
