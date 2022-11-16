#include <iostream>
#include <string>
using namespace std;

bool isIdentifier(string token){
    if(!(token[0] >= 'a' && token[0] <= 'z') && !(token[0] >= 'A' && token[0] <= 'Z')) return false;
    for(int i=1; i< token.size(); i++){
        if(!(token[i] >= 'a' && token[i] <= 'z') && !(token[i] >= 'A' && token[i] <= 'Z') && token[i] != '_' && !(token[i] >= '0' && token[i] <= '9')) return false;
    }
    return true;
}

bool isInteger(string token){
    if(token[0] == '0') return false;
    for(int i=0; i < token.size(); i++){
        if(!(token[i] >= '0' && token[i] <= '9')) return false;
    }
    return true;
}

bool checkOperator(char ch){
    if(ch != '+' && ch != '-' && ch != '*' && ch != '/') return false;
    return true;
}

bool checkFistLast(char ch){
    if(!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') && !(ch >= '1' && ch <= '9')) return true;
    return false;
}

bool isValid(string exp){
    bool isOperator = false;
    string token = "";
    if(checkFistLast(exp[0]) || checkFistLast(exp[exp.size() - 1])) return false;

    for (int i = 0; i < exp.size(); i++) {
        if (checkOperator(exp[i]) || i == exp.size() - 1) {
            if(i == exp.size() - 1) token += exp[i];
            isOperator = true;
            if(isOperator && checkOperator(exp[i+1])) return false;
            else isOperator = false;

            if(!(isIdentifier(token)) && !(isInteger(token))) return false;
            
            token = "";
        }
        else token += exp[i];
    }
    return true;
}

int main(){
    string exp = "2+*3+5";
    if(isValid(exp)) 
    cout <<"VALID"<< endl;
    else 
    cout <<"INVALID"<< endl;
    return 0;
}