#include "postf.h"
#include "stack.h"

static const size_t npos = -1;

bool CMyPostfix::Icorrect(string str)
{
	string prohibite = "!@#&.,<>{}[]_=?";
	int count = 0, k = 0, countOp = 0, length = str.length();
	if ((op.find(str[0]) != npos) || (op.find(str[length - 1]) != npos))
		return false;
	for (int i = 0; i < length; i++)
	{
		if (prohibite.find(str[i]) != npos)
			return false;
		if (str[i] == '(')
			count++;
		if (str[i] == ')')
			count--;
		if ((str[i] - 'a' >= 0) && (str[i] - 'a' <= 26))
			k++;
		else
			k = 0;
		if (op.find(str[i]) != npos)
			countOp++;
		else
			countOp = 0;
		if ((k > 1) || (countOp > 1))
			return false;
	}
	if (count != 0)
		return false;
	return true;
}

string CMyPostfix::ToPostf()
{
	CMyStack<char> opStack(MaxSize);
	string tmp = "+-*^/()";
	int length = inf.length();
	for (int i = 0; i < length; i++)
	{
		if (tmp.find(inf[i]) == npos)
			postf += inf[i];
		if ((inf[i] >= '0') && (inf[i] <= '9'))
			if (i != length)
			{
				if ((inf[i + 1] < '0') || (inf[i + 1] > '9'))
					postf += ' ';
			}
			else { postf += ' '; }
		if (inf[i] == '(')
			opStack.push(inf[i]);
		if (inf[i] == ')')
		{
			char temp = opStack.pop();
			while (temp != '(')
			{
				postf += temp;
				temp = opStack.pop();
			}
		}
		if (op.find(inf[i]) != npos)
		{
			if (opStack.IsEmpty())
				opStack.push(inf[i]);
			else
			{
				int index2 = op.find(inf[i]);
				while (!opStack.IsEmpty())
				{
					char temp = opStack.pop();
					if (temp == '(')
					{
						opStack.push(temp);
						break;
					}
					int index1 = op.find(temp);
					if (priority[index2] <= priority[index1])
						postf += temp;
					else
					{
						opStack.push(temp);
						break;
					}
				}
				opStack.push(inf[i]);
			}
		}
	}
	while (!opStack IsEmpty())
	{
		postf += opStack.pop();
	}
	return postf;
}

double CMyPostfix::Calc()
{
	if (postf.length() == 0) ToPostf();
	int length = postf.length();
	CMyStack<double> result(MaxSize);
	string nameValues;
	double* values = new double[length];
	for (int i = 0; i < length; i++)
	{
		if (op.find(postf[i]) == npos)
		{
			double p;
			if ((postf[i] < 48) || (postf[i] > 57))
			{
				if (nameValues.find(postf[i]) == npos)
				{

					nameValues += postf[i];
					cout << "Введите значение переменной - " << postf[i] << endl;
					cin >> p;
					values[nameValues.length() - 1] = p;
				}
				else
				{
					p = values[nameValues.find(postf[i])];
				}
			}
			else
			{
				string number;
				while (postf[i] != ' ')
				{
					number += postf[i];
					i++;
				}
				p = stoi(number);      //преобразует строку в число
			}
			result.push(p);
		}
		else
		{
			double val1, val2, val3;
			val2 = result.pop();
			val1 = result.pop();
			switch (postf[i])
			{
			case '+': val3 = val1 + val2; break;
			case '-': val3 = val1 - val2; break;
			case '*': val3 = val1 * val2; break;
			case '/': val3 = val1 / val2; break;
			case '^': val3 = pow(val1, val2); break;
			}
			result.push(val3);
		}
	}
	delete[] values;
	return result.pop();
}
