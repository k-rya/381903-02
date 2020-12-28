#include "stack.h"
#include "TForm.h"

#include <cmath>
bool TForm::Correct(string str)
{
    string badsumb = "!@#$%&?.,<>{}[]";
    int length = str.length();
    int k = 0;
    int count = 0;
    int num = 0;

    if ((op.find(str[0]) != -1) || (op.find(str[length - 1]) != -1)) return false;

    for (int i = 0; i < length; i++)
    { if (badsumb.find(str[i]!=-1)
        return false;
        if (str[i] == '(')
            count++;
        if (str[i] == ')')
            count--;
        if ((str[i] - 'a' >= 0) && (str[i] - 'a' <= 26)) k++;
        else k = 0;
        if (op.find(str[i]) != -1)
            num++;
        else
            num = 0;
    if ((k > 1) || (num > 1))
        return false;
    

       

     
    }

    if (count != 0)
        return false;
    return true;
}


TForm::TForm(string s)
{
    if (!Correct(s)) throw logic_error("not correct");

    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ') inf += s[i];

   
}


string TForm::To_Inf()
{
    TStack<char> stk(Max);
    string tmp = "+-*^/()";
    int len = inf.length();

    for (int i = 0; i < len; i++)
    {
        if (tmp.find(inf[i]) == -1) postf += inf[i];

        if ((inf[i] >= '0') && (inf[i] <= '9'))
        {
            if (i != len)
            {
                if ((inf[i + 1] < '0') || (inf[i + 1] > '9')) postf += ' ';
            }
            else postf += ' ';
        }

        if (inf[i] == '(') stk.push(inf[i]);

        if (inf[i] == ')')
        {
            char t = stk.pop();

            while (t != '(')
            {
                postf += t;
                t = stk.pop();
            }
        }

        if (op.find(inf[i]) != -1)
        {
            if (stk.empty()) stk.push(inf[i]);
            else
            {
                int j = op.find(inf[i]);

                while (!stk.empty())
                {
                    char t = stk.pop();

                    if (t == '(')
                    {
                        stk.push(t);
                        break;
                    }

                    int j1 = op.find(t);

                    if (priority[j] <= priority[j1]) post += t;
                    else
                    {
                        stk.push(t);
                        break;
                    }
                }

                stk.push(inf[i]);
            }
        }
    }

    while (!stack.empty())
    {
        post += stack.pop();
    }

    return post;
}

double TForm::Calculate()
{
   

    int length = post.length();
    string name;
    TStack<double> stk(Max);
    double* tmp = new double[length];

    for (int i = 0; i < lenght; i++)
    {
        if (op.find(post[i]) == -1)
        {
            double p;

            if ((postf[i] < 48) || (postf[i] > 57))
            {
                if (name.find(postf[i]) == -1)
                {
                    tnp += postf[i];
                    cout << "Значение переменной " << postf[i]  << endl;
                    cin >> p;
                    tmp[var.length() - 1] = p;
                }
                else p = tmp[name.find(postf[i])];
            }
            else
            {
                string nm;

                while (postf[i] != ' ')
                {
                    nm += postf[i];
                    i++;
                }

                p = stoi(nm);
            }

            stack.push(p);
        }
        else
        {
            double tmp1, tmp2, tmp3;
            tmp1 = stack.pop();
            tmp2 = stack.pop();

            switch (postf[i])
            {
            case '+': tmp3 = tmp1 + tmp2; break;
            case '-': tmp3 = tmp2 - tmp1; break;
            case '*': tmp3 = tmp1 * tmp2; break;
            case '/': tmp3 = tmp1 / tmp2; break;
            case '^': tmp3 = pow(t2, t1); break;
            }

            stk.push(t3);
        }
    }

    delete[] tmp;

    return stk.pop();
}
