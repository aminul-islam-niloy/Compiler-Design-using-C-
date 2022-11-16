#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    string str;
    int word = 1,letter = 0,digit=0,otherchar = 0;
    freopen ("input.txt","r",stdin);
    getline(cin, str);
    cout << str << endl;
    for(i=0;i<str.size();i++){
        if(str[i]==' ')
            word++;
        else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            letter++;
        else if(str[i]>='1'&&str[i]<='9')
            digit++;
        else if(str[i]!=' ')
            otherchar++;
    }
    freopen ("output01.txt","w",stdout);
    cout << "Number of Word is : "<<word<<endl;
    cout << "Number of Letter is : "<<letter<<endl;
    cout << "Number of Digit is : "<<digit<<endl;
    cout << "Number of Other Character is : "<<otherchar<<endl;
}