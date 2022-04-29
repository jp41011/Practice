#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
link:
https://www.hackerrank.com/challenges/30-conditional-statements/problem?h_r=next-challenge&h_v=zen
*/

void isNumberWeird(int number)
{
	if(number % 2 == 1) // number is odd.
		cout << "Weird" << endl;
	else if (2 <= number && number <= 5) // number is even and [2, 5] inclusive.
		cout << "Not Weird" << endl;
	else if (6 <= number && number <= 20) // number is even and [6, 20] inclusive.
		cout << "Weird" << endl;
	else if ( number >= 20) // number is even and greater than 20.
		cout << "Not Weird" << endl;
	else 
		cout << "Error" << endl;
}

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

	isNumberWeird(N);

    return 0;
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
