#include<bits/stdc++.h>
using namespace std;

string keywords[49] = {"int","namespace","struct","new","switch","and","delete","do","not","this",
                     "double","auto","nullptr","throw","else","true","enum","or","try","bool","typedef",
                     "break","private","case","typename","catch","false","public","union","char","float",
                     "register","unsigned","for","return","class","goto","short","void","if","signed","const",
                     "sizeof","int","static","while","long","xor","continue"};

bool isCharacter(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        return true;
    }
    return false;
}

bool isKeyword(string str)
{
    for(int i = 0;i<49;i++)
    {
        if(keywords[i]==str)
        {
            return true;
        }
    }
    return false;
}

    bool isArithmetic(string str)
{
    if(str=="+" || str=="-" || str=="*" || str=="/") 
    
    return true;
    else

    return false;
}

int isFloatOrInt(string str)
{
    int size = str.size();
    int count = 0;
    for(int i = 0; i<size; i++)
    {
        if(str[i]=='.')
         count++;

        else if(!isdigit(str[i]))
        {
            return -1;
        }
    }

    if(count==0)
      return 0;
   
    else if(count==1) 
    return 1;

    else 
    
    return -1;
}

bool isIdentifier(string str)
{
    if(isdigit(str[0]))
     return false;
    else  
     return true;
}

int main()

    {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string str;
    getline(cin,str);
    

    if(isArithmetic(str))
    {
        cout<<"Arithmetic Operator\n";
    }
    
    else if(isKeyword(str))
    {
        cout<<"Keyword\n";
    }

    else if(isFloatOrInt(str)!=-1)
    
        {
            int chack = isFloatOrInt(str);
            if(chack==0) 
            {
                cout<<"Integer\n";
            }
        
            else if(chack==1)
            {
                cout<<"Float\n";
            } 

        }

    else if(isIdentifier(str))
    {
        cout<<"Identifier\n";
    }
    else
    {
        cout<<"Invalid Input\n";
    }
    

}