#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Takes a string and printout the odd and even indexed charaters.
*/
void oddEvenStringSplit(string inputString)
{
	string oddLetters = "";
	string evenLetters = "";

	for(int i = 0; i < inputString.length(); i++)
	{
		if( i % 2 == 0)
			evenLetters = evenLetters + inputString[i];
		else
			oddLetters = oddLetters + inputString[i];
	}

	cout << evenLetters << " " << oddLetters << endl;

	return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int numberOfInputStrings = 0;

	cin >> numberOfInputStrings;

	for(int i = 0; i < numberOfInputStrings; i++)
	{
		string inputString = "";
		cin >> inputString;
		oddEvenStringSplit(inputString);
	}

    return 0;
}
