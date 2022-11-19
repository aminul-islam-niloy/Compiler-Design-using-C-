#include<bits/stdc++.h>
using namespace std;



bool isSeparator(char ch)
{
    string value= " ,;(){}[]";
    for(int i=0; i<value.length(); i++)

    if(ch== value[i] )
    return true;
    return false;
}



bool isOperator(char ch)
{
    string value= "+-*/%<>=!&";
    for(int i=0; i<value.length(); i++)

    if(ch== value[i])
    return true;
    return false;
};


bool isKeyword(string str)
{
    string keywords[] = {"int","namespace","struct","new","switch","and","delete","do","not","this",
                     "double","auto","nullptr","throw","else","true","enum","or","try","bool","typedef",
                     "break","private","case","typename","catch","false","public","union","char","float",
                     "register","unsigned","for","return","class","goto","short","void","if","signed","const",
                     "sizeof","int","static","while","long","xor","continue"};

      for(int i=0;
       i<(sizeof(keywords)/sizeof(string)); 
       i++)

      if(str==keywords[i])
      return true;

      return false;

};

bool isIdentifier(string str)
{
    bool valid= true;

    if(isKeyword(str))
      valid= false;

    if(valid)
    
         if((str[0] >= '0') && (str[0] <= '9'))
         valid = false;

         if(valid)
         
               for(int i=0; i<str.length(); i++)

                    if(((str[i]>='a')&& (str[i]<='z') ||(str[i]>='A')&& (str[i]<='Z') || ((str[i]>='0')&&(str[i]<='9')) || (str[i]=='_') ) )
                    continue;

                        else
                        {
                            valid = false;
                            break;
                        }
                return valid;
}

bool isNumber(string str){
    bool valid=true;

    for(int i=0; i<str.length(); i++)

        if((str[i]>='0')&&(str[i]<='9')|| (str[i]=='.'))
        
        continue;

        else 
        {
            valid= false;
            break;
        }

  return valid;

}





void lex(string str){
      vector<string> tokens;               //vector declaration

      string token= "";                    // token init

      for(int i=0; i<str.length(); i++)
      {
            if(isSeparator(str[i]))
            {
                if(token!="")
                tokens.push_back(token);             //if we find separator
                token = "";                         // make token empty

            }

            else if(isOperator(str[i]))
            {
                if(token!="")
                {
                    tokens.push_back(token);
                    token= "";
                }

                token.push_back(str[i]);            // 
                tokens.push_back(token);
                token="";   
            }

                else
                token.push_back(str[i]); 
      }
      if(token != "")
            {
                tokens.push_back(token);
                token="";
            }


      //output 
     int count=0;
      for( int i=0; i<tokens.size(); i++)
      
      {
        if(isKeyword(tokens[i]))
           cout <<'\"'<< tokens[i]<<"\"   is a keyword "<<endl;

                else if(isIdentifier(tokens[i]))
                  cout <<'\"'<<tokens[i]<< "\"  is a Identifier "<<endl;

                        else if(isNumber(tokens[i]))
                           cout <<'\"'<<tokens[i]<< "\" is a Number "<<endl;

                            else if(isOperator(tokens[i][0])) 
                               cout<<'\"'  <<tokens[i]<<"\"  is a Operator "<<endl;

                               else 
                                  cout <<'\"' <<tokens[i]<<"\"  is a Invalid Identifier  "<<endl;

                                                       

      }

}


int main(){
    ifstream file;
    string line;

    file.open("in.txt");

    while(file){
        getline(file,line);
        lex(line);
    }

    file.close();
    return 0;
}