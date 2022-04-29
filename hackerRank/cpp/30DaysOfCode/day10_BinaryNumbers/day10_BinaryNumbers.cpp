#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string convertIntToBinaryString(int);
string reverseString(const string);
int consecutiveCharCount(const string&, const char&);
void printDebug(const int&, const string&, const int&);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // Convert int to binary string.
    string binaryString = convertIntToBinaryString(n);

    // Count consecutive 1's.
    int consecutive1s = consecutiveCharCount(binaryString, '1');

    // Print result.
    cout << consecutive1s << endl;

    //printDebug(n, binaryString, consecutive1s);

    return 0;
}

string convertIntToBinaryString(int integer)
{
    string binaryString = "";

    while(integer != 0)
    {
        int remainder = integer % 2;
        
        if(remainder == 0)
            binaryString += "0";
        else
            binaryString += "1";
        
        integer = integer / 2;
    }
    return reverseString(binaryString);
}

string reverseString(const string inputString)
{
    string reversedString = "";
    
    // string.size() and string.length() returns the size in bytes.
    // reference: 
    // * https://www.cplusplus.com/reference/string/string/length/ 
    // * https://www.cplusplus.com/reference/string/string/size/
    // for(int i=inputString.size()-1; i >= 0; i++)
    // {
    //     reversedString += inputString[i];
    // }

    for(auto char1 : inputString)
    {
        reversedString = char1 + reversedString;
    }

    return reversedString;
}

int consecutiveCharCount(const string& inputString, const char& character)
{
    int currentMax = 0;     // Current max count of consecutive character.
    int currentCount = 0;   // Current count of consecutive characters when in a chord.
    for(int i=0; i < inputString.length(); i++)
    {
        if(inputString[i] == character)
            currentCount++;
        else
            currentCount = 0;
        
        if(currentCount > currentMax)
            currentMax = currentCount;
    }

    return currentMax;
}

void printDebug(const int& base10, const string& base2, const int& consecutiveCount)
{
    cout << "------------------------" << endl;
    cout << "base10: " << base10 << endl;
    cout << "base2: " << base2 << endl;
    cout << "consecutive 1's: " << consecutiveCount << endl;
    cout << "------------------------" << endl;
    return;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
