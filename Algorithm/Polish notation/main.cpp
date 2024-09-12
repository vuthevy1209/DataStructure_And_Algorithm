#include <fstream> 
#include "BigNum.h"
#include "Stack.h"
#include "Queue.h" 
#include "FormatExpression.h"

bool checkForCorrectParentheses(string line)
{
    Stack<char> s; 

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '[' || line[i] == '{')
            line[i] = '(';
        if (line[i] == ']' || line[i] == '}')
            line[i] = ')';

        if (line[i] == '(')
        {
            s.push(line[i]);
        }
        else if (line[i] == ')')
        {
            if (s.empty())
            {
                return false;
            }

            char temp = s.top();  
            s.pop();
            if (temp != '(')
                return false;
        }
    }
    if (!s.empty())
        return false;

    return true;
}

bool checkExpressionValidity(const string& line)
{
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!(line[i] >= '0' && line[i] <= '9') && !(line[i] == '(' || line[i] == ')') && !(line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')) {
            return false;
        }
        if ((line[i] == '*' || line[i] == '/' || line[i] == '%'))
        {
            if ((line[i - 1] >= '0' && line[i - 1] <= '9') || line[i - 1] == ')')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        if ((line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%') && line[i + 1] == ')')
        {
            return false;
        }
    }

    return true;
}


Queue<string> readLine(string line)
{
    Queue<string> q;

    string previous = "#";
    for (size_t i = 0; i < line.size(); i++)
    {
        if ((line[i] == '-' || line[i] == '+') && (!(previous[previous.size() - 1] >= '0' && previous[previous.size() - 1] <= '9') || previous == "(") && previous != ")")
        {
            string temp = "";
            temp += line[i];
            i++;
            while (line[i] >= '0' && line[i] <= '9')
            {
                temp += line[i];
                i++;
            }
            i--;
            q.push(temp);
            previous = temp;
        }
        else if (line[i] >= '0' && line[i] <= '9')
        {
            string temp = "";
            while (line[i] >= '0' && line[i] <= '9')
            {
                temp += line[i];
                i++;
            }
            i--;
            q.push(temp);
            previous = temp;
        }
        else if (line[i] == '(' || line[i] == ')' || line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
        {
            string temp = "";
            temp += line[i];
            q.push(temp);
            previous = temp;
        }
        else
        { // line[i] == ' '
            continue;
        }
    }
    return q;
}

int precedence(string x)
{
    if (x == "(" || x == ")")
        return 0;
    if ((x == "+" || x == "-") && x.length() == 1)
        return 1;
    if (x == "*" || x == "/" || x == "%")
        return 2;
    if (x == "^")
        return 3;
    if (x == " ")
        return 4;
    return 5;
}

Queue<string> infixtoPostfix(string line)
{
    Queue<string> infix = readLine(line);
    Queue<string> postfix;
    Stack<string> Stack;

    while (!infix.empty())
    {
        string x = infix.front();
        infix.pop();
        int check = precedence(x);

        if (check == 0)
        {
            if (x == "(")
            {
                Stack.push(x);
            }
            else
            {
                while (Stack.top() != "(")
                {
                    postfix.push(Stack.top());
                    Stack.pop();
                }
                Stack.pop();
            }
        }
        else if (check == 1 || check == 2 || check == 3)
        {
            while (!Stack.empty() && check <= precedence(Stack.top()))
            {
                postfix.push(Stack.top());
                Stack.pop();
            }
            Stack.push(x);
        }
        else if (check == 4)
            continue;
        else
        {
            postfix.push(x);
        }
    }

    return postfix;
}

bigint Value(Queue<string> Queue)
{
    Stack<string> Stack;
    while (!Queue.empty())
    {
        string temp = Queue.front();
        Queue.pop();
        if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "%")
        {
            bigint x;
            bigint y;

            if (!Stack.empty())
            {
                y.setNumber(Stack.top());
                Stack.pop();
            }
            else
                throw runtime_error("Error: INVALID EXPRESSION.");

            if (!Stack.empty())
            {
                x.setNumber(Stack.top());
                Stack.pop();
            }
            else
                throw runtime_error("Error: INVALID EXPRESSION.");

            bigint result("0");
            if (temp == "+")
                result = x + y;
            else if (temp == "-")
                result = x - y;
            else if (temp == "*")
                result = x * y;
            else if (temp == "/")
                result = x / y;
            else if (temp == "%")
                result = x % y;

            Stack.push(result.getNumber());
        }
        else
        {
            Stack.push(temp);
        }
    }

    bigint result = bigint(Stack.top());
    Stack.pop();

    if (Stack.empty())
        return result;
    else
        throw runtime_error("Error: INVALID EXPRESSION.");
}

int main()
{
    string inputFile = "input.txt"; 
    string outputFile = "output.txt"; 
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (input.fail() || output.fail())
    {
        cerr << "Cannot open file !";
        return 0;
    }

    string line = "";
    while (getline(input, line))
    {
        if (line == "") continue;
        if (!checkForCorrectParentheses(line)) {
            output << "Error: INVALID EXPRESSION." << endl;  
            continue; 
        } 
        deleteSpace(line); 
        insertMultiplication(line); 
        deleteRedundantParentheses(line); 
        formatString(line); 
        if (checkExpressionValidity(line))
        {
            try
            {
                output << Value(infixtoPostfix(line)).getNumber() << endl;
            }
            catch (runtime_error e)
            {
                output << e.what() << endl;
            }
        }
        else
            output << "Error: INVALID EXPRESSION." << endl;
    }

    input.close();
    output.close();

    cout << "Write to file successfully.";

    return 0;
}
