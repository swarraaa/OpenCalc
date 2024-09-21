#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(const string &expression)
{
    vector<string> tokens;
    stringstream ss(expression);
    string token;

    for (char ch : expression)
    {
        if (isspace(ch))
            continue;

        if (isdigit(ch) || ch == '.')
        {
            token += ch;
        }
        else
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
            if (ch == '-' && (tokens.empty() || tokens.back() == "("))
            {
                token += ch;
            }
            else
            {
                tokens.push_back(string(1, ch));
            }
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens;
}

int precedence(const string &op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    return 0;
}

double applyOp(double a, double b, const string &op)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw runtime_error("Division by zero");
        return a / b;
    }
    return 0;
}

vector<string> infixToPostfix(const vector<string> &tokens)
{
    stack<string> opStack;
    vector<string> postfix;

    for (const auto &token : tokens)
    {
        if (isdigit(token[0]) || token[0] == '-' || (token.size() > 1 && token[0] == '-'))
        {
            postfix.push_back(token);
        }
        else if (token == "(")
        {
            opStack.push(token);
        }
        else if (token == ")")
        {
            while (!opStack.empty() && opStack.top() != "(")
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty())
                throw runtime_error("Mismatched parentheses");
            opStack.pop();
        }
        else
        {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token))
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty())
    {
        if (opStack.top() == "(")
            throw runtime_error("Mismatched parentheses");
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    return postfix;
}

double evaluatePostfix(const vector<string> &postfix)
{
    stack<double> valueStack;

    for (const auto &token : postfix)
    {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            valueStack.push(stod(token));
        }
        else
        {
            if (valueStack.size() < 2)
                throw runtime_error("Invalid expression");
            double b = valueStack.top();
            valueStack.pop();
            double a = valueStack.top();
            valueStack.pop();
            valueStack.push(applyOp(a, b, token));
        }
    }

    if (valueStack.size() != 1)
        throw runtime_error("Invalid expression");
    return valueStack.top();
}

int main()
{
    string input;

    cout << "OpenCalc: Your CLI-based calculator" << endl
         << "Type 'exit' to quit" << endl;

    while (true)
    {
        cout << "Enter expression: ";
        getline(cin, input);

        if (input == "exit")
        {
            cout << "Bye!!" << endl;
            break;
        }

        try
        {
            auto tokens = tokenize(input);
            auto postfix = infixToPostfix(tokens);
            double result = evaluatePostfix(postfix);
            cout << "Result: " << result << endl;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
