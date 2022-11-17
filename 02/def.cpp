#include <bits/stdc++.h>
using namespace std;


bool isFloatVariable(string str)
{
    bool isStarting = false;

    int size = str.size();

    if ((str[0] >= 'a' && str[0] <= 'h') || (str[0] >= 'A' && str[0] <= 'H') || (str[0] >= 'o' && str[0] <= 'z') || (str[0] >= 'O' && str[0] <= 'Z'))
    {
        isStarting = true;
    }

    bool others = true;
    for (int i = 1; i < str.size(); i++)
    {
        if (!isalpha(str[i]) && !isdigit(str[i]))
        {
            others = false;
            break;
        }
    }

    if (isStarting && others)
        return true;
    else
        return false;
}

bool isFloatNumber(string str)
{
  
    int size = str.size();

    if (size < 4)
        return false;

    if (size >= 2 && str[0] == '0' && str[1] == '0')    // minimum two digit without 0 and 2nd 0
        return false;


    int findPosition = 0;
    int point = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.')
        {
            point = true;
            continue;
        }
        if (point)
            findPosition++;
    }

    if (findPosition != 2 || point == 0 || point > 1) // point position is not 2nd or not point or more than one point then it's false
        return false;

    return true;
}

bool isDoubleNumber(string str)
{
    int size = str.size();
    if (size <= 4)
        return false;

    if (size >= 2 && str[0] == '0' && str[1] == '0')
        return false;

    int digitAfterPoint = 0;
    int Point = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.')
        {
            Point = true;
            continue;
        }
        if (Point)
            digitAfterPoint++;
    }

    if (digitAfterPoint <= 2 || Point == 0 || Point > 1)
        return false;

    return true;
}


int main()
{
    string word;
     cout<<" Enter String: "; 
    cin >> word;
    if (isFloatVariable(word)) 
    {
        cout << "Float Variable";
    }
    else if (isFloatNumber(word)) 
    {
        cout << "Float Number";
    }
    else if (isDoubleNumber(word))
    {
        cout << "Double Number";
    }
    else cout << "Invalid Input or Undefined";
    return 0;
}