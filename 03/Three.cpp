// 7. Write a program to recognize C++
// 1. Keyword 2. Identifier 3. Operator 4. Constant

#include <bits/stdc++.h>
using namespace std;
char singleQuote = '\'';
char doubleQuote = '\"';

vector<string> keywords = {"true", "false", "or", "and", "for", "if", "else", "do", "while",
 "break", "continue", "int", "float", "double", "bool", "long", "unsigned", "char", 
 "string", "void", "auto", "new", "switch", "namespace", "class", "const", 
 "sizeof", "typedef", "xor", "delete", "nullptr"};

vector<string> all_operators = {
    "+", "^","-", "*", "/", "%", "++", "--", "+=", "-=", "%=", "*=", "/=", "==", "!=", ">",
     "<", ">>", "<<",">=","<=", "%=","%","||","&&","&","="};

void sort_keywords_operators()
{
    sort(keywords.begin(), keywords.end());
    sort(all_operators.begin(), all_operators.end());
}

bool isConstant(string input)
{
    bool isConstant = false;

    // Check if it is a number
    if (input[0] == doubleQuote && input[input.size() - 1] == doubleQuote)
        return true;

    else if (input[0] == singleQuote && input[input.size() - 1] == singleQuote && input.size() == 3)
        return true;

    else if (isdigit(input[0]))
    {
        isConstant = true;
        int pointCount = 0;

        // Check if rest of the characters are number (and 1 point)
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] == '.')
            {
                pointCount++;
                continue;
            }
            if (!isdigit(input[i]))
            {
                isConstant = false;
                break;
            }
        }
        if (pointCount <= 1 && isConstant)
            return true;
        else
            return false;
    }
    return false;
}

bool isKeyword(string input)
{
    if (binary_search(keywords.begin(), keywords.end(), input))
        return true;
    else
        return false;
}

bool isOperator(string input)
{
    if (binary_search(all_operators.begin(), all_operators.end(), input))
        return true;
    else
        return false;
}

bool isIdentifier(string input)
{
    bool isIdentifier = false;

    if (isalpha(input[0]) || (input[0] == '_'))
    {
        isIdentifier = true;
        for (int i = 1; i < input.size(); i++)
        {
            if (!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '_')
            {
                isIdentifier = false;
                break;
            }
        }
    }
    if (isIdentifier)
        return true;
    else
        return false;
}

vector<string> seperateWords(string str)
{
    vector<string> words;
    string word = "";

    for (auto letter : str)
    {
        if (letter == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else

            word += letter;
    }
    words.push_back(word);
    return words;
}

int main()
{
    sort_keywords_operators();

     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string input;
    getline(cin, input);

    vector<string> lexemes = seperateWords(input);

    for (int i = 0; i < lexemes.size(); i++)
    {
        cout << "Scanned : " << lexemes[i] << endl;

        if (isConstant(lexemes[i]))
        {
            cout << "Constant" << endl;
        }
        else if (isKeyword(lexemes[i]))
        {
            cout << "Keyword" << endl;
        }
        else if (isOperator(lexemes[i]))
        {
            cout << "Operator" << endl;
        }
        else if (isIdentifier(lexemes[i]))
        {
            cout << "Identifier" << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}