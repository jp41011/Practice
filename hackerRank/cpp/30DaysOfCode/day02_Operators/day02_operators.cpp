#include <bits/stdc++.h>

using namespace std;

/*
link: 
https://www.hackerrank.com/challenges/30-operators/problem
*/

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function accepts following parameters:
 *  1. DOUBLE meal_cost
 *  2. INTEGER tip_percent
 *  3. INTEGER tax_percent
 */

// Round to 2 decimal places.
double roundMoney(double &money)
{
	double roundedMoney = round(money * 100) / 100;
	return roundedMoney;
}

// Prints the total cost of the meal including tip and tax.
void solve(double meal_cost, int tip_percent, int tax_percent) {
	
	double tipAmount = meal_cost * (double)tip_percent / 100;
	double taxAmount = meal_cost * (double)tax_percent / 100;

	tipAmount = roundMoney(tipAmount);
	taxAmount = roundMoney(taxAmount);

	double totalAmount = meal_cost + tipAmount + taxAmount;
	totalAmount = round(totalAmount);

	cout << totalAmount;
}

int main()
{
    string meal_cost_temp;
    getline(cin, meal_cost_temp);

    double meal_cost = stod(ltrim(rtrim(meal_cost_temp)));

    string tip_percent_temp;
    getline(cin, tip_percent_temp);

    int tip_percent = stoi(ltrim(rtrim(tip_percent_temp)));

    string tax_percent_temp;
    getline(cin, tax_percent_temp);

    int tax_percent = stoi(ltrim(rtrim(tax_percent_temp)));

    solve(meal_cost, tip_percent, tax_percent);

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
