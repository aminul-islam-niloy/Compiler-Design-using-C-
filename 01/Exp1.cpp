
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
vector<string> words;
int totalWords = 0;
ifstream MyReadFile("Input1.txt");
ofstream OutFile("Output1.txt");

void removeDupWord(string str)
{
    string word = "";
    int letters;
    for (auto x : str)
    {
        if (x == ' ')
        {
            //word += '\0';
            //cout << word << endl;
            words.push_back(word);
            totalWords +=1;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    words.push_back(word);
    totalWords +=1;
}

bool isDigit(char s)
{
    char digits[ ] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(auto digit: digits)
    {
        if(s == digit)
            return true;
    }

    return false;
}

bool isLetter(char s)
{
    if(s >= 'a' && s<= 'z')
    {
        // cout << "Yes";
        return true;
    }

    else if(s >='A' && s<= 'Z')
    {   
        // cout << "Yes";
        return true;
    }

    // cout << "No";
    return false;
}


void check(vector<string> words)
{
    int totalLetter = 0;
    int totalDigit = 0;
    int totalOtherCharacters = 0;
    vector<char> letters;
    vector<char> digits;
    vector<char> otherCharacters;

    for(auto word: words)
    {
        for(auto ch: word)
        {
            if(isDigit(ch))
            {
                totalDigit += 1;
                digits.push_back(ch);
            }

            else if(isLetter(ch))
            {
                totalLetter +=1;
                letters.push_back(ch);
            }

            else
            {
                if(ch != '\0')
                {
                    totalOtherCharacters +=1;
                    otherCharacters.push_back(ch);
                }
                
            }

        }
    }

    OutFile << "Total Letters are " << totalLetter << endl;
    OutFile << "Total Digits are " << totalDigit << endl;
    OutFile << "Number of other characters are " << totalOtherCharacters << endl;

    OutFile << "The letters are: ";
    for(auto ch: letters)
    {
        OutFile << ch << " ";
    }
    OutFile << endl;

    OutFile << "The Digits are: ";
    for(auto ch: digits)
    {
        OutFile << ch << " ";
    }
    OutFile << endl;

    OutFile << "Other Characters are: ";
    for(auto ch: otherCharacters)
    {
        OutFile << ch << " ";
    }
    OutFile << endl;
}

int main()
{

    string str;

    while (getline (MyReadFile, str)) 
    {
        removeDupWord(str);
        OutFile << "Total Words are: " << totalWords << ", and they are listed below: "<< endl;

        for(auto word: words)
        {
            OutFile << word << endl;
        }

        check(words);
    }
    
    // Close the file
    MyReadFile.close();
    OutFile.close();


    return 0;
}