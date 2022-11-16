#include <bits/stdc++.h>

using namespace std;

string syntax;

//E-> EAE
// A->  is operator then operator then operator chack

bool EAE()
{    
    int n = syntax.size() - 1;  //last
    //First chack
    if (syntax[0] == '+' || syntax[0] == '-' || syntax[0] == '*' || syntax[0] == '/')
    {
        return false;

    }

//Last Chack
    if (syntax[n] =='+' ||
        syntax[n] == '-' ||
        syntax[n] == '*' ||
        syntax[n] == '/')
    {
        return false;
    }

//middles value
    for (int i = 1;  i< syntax[i]-1; i++)     //second position to
    {
        if (syntax[i] == '+' ||
             syntax[i] == '-' ||
             syntax[i] == '*' ||
             syntax[i] == '/')



        {                                         //i= +-*/
            if (syntax[i - 1] == '+' ||
                syntax[i - 1] == '-' ||
                syntax[i - 1] == '*' ||
                syntax[i - 1] == '/')
            {
                return false;
            }
                    if (syntax[i - 1] == ('('||')'))     //if (+ or )+
                    {
                        return false;
                    }
        }
    }


    return true;
}

//(E)
// if ( and ) then push to stack


bool E()
{
    stack<char> brackets;
    for (int i = 0; syntax[i]; i++)
    {
        if (syntax[i] == '(') 
        {
             brackets.push('(');
        }
        

        else if (syntax[i] == ')')
        {
            if (brackets.size())
            
             brackets.pop();
            else 
            
            return false;
        }
    }
    
            if (brackets.size() == 0)
            return true;

            else 
            return false;
}

int main()
    { 
    cout<<"Enter Syntax: ";
    cin >> syntax;
    if (EAE() && E())

        cout << "Valid\n";

    else
    
     cout << "Invalid\n";
}