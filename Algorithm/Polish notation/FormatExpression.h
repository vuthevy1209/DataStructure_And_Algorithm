#pragma once
#include <string>
#include "Stack.h" 
using namespace std;

void deleteSpace(string& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s.erase(i, 1);
            i--;
        }
    }
}

void insertMultiplication(string& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ')' && s[i + 1] == '(')
        {
            s.insert(i + 1, "*");
        }
        if (s[i] >= '0' && s[i] <= '9' && s[i + 1] == '(')
        {
            s.insert(i + 1, "*");
        }
    }
}

void formatString(string& s)
{
    s = "(" + s + ")";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-')
        {
            string temp = "";
            int countSign = 0;

            int j = i;
            while (s[j] == '+' || s[j] == '-')
            {
                temp += s[j];
                j++;
                countSign++;
            }

            s.erase(i, countSign);

            int minus = 0;
            for (int j = 0; j < temp.size(); j++)
            {
                if (temp[j] == '-')
                    minus++;
            }
            if (minus % 2 == 1)
                s.insert(i, "-");
            else
                s.insert(i, "+");
        }

        if (s[i] == ':')
            s[i] = '/';
        if (s[i] == '[' || s[i] == '{')
            s[i] = '(';
        if (s[i] == ']' || s[i] == '}')
            s[i] = ')';
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        if ((s[i] == '-' || s[i] == '+') && s[i - 1] == '(')
            s.insert(i, "0");
    }
}

void deleteRedundantParentheses(string& s)
{
    Stack<int> st; 
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (!st.empty()) {
                return;
            }
            int start = st.top();
            st.pop();

            int countNumber = 0;
            for (int j = start + 1; j < i; j++)
            {
                if (s[j] == '(')
                {
                    countNumber++;
                    Stack<char> temp;
                    while (s[j] != ')')
                    {
                        j++;
                        if (s[j] == '(')
                            temp.push(s[j]);
                        if (s[j] == ')' && !temp.empty())
                        {
                            temp.pop();
                            j++;
                        }
                    }
                }
                if (s[j] >= '0' && s[j] <= '9')
                {
                    countNumber++;
                    while (s[j] >= '0' && s[j] <= '9')
                    {
                        j++;
                    }
                    j--;
                }
            }

            if (countNumber == 1)
            {
                s.erase(i, 1);     // remove ')'
                s.erase(start, 1); // remove '('
                i -= 2;
                n -= 2;
            }
        }
    }
}