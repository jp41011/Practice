#include <bits/stdc++.h>

using namespace std;

/*
Day 11: 2D Arrays
link: https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true
*/

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int getMaxHourglassSum(const vector< vector<int> >& grid)
{
	int currentMax = INT_MIN;
	for(int row=0; row <= grid.size()-3; row++)
	{
		for(int col=0; col <= grid[row].size()-3; col++)
		{
			int currentSum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
			currentSum += grid[row+1][col+1];
			currentSum += grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

			if(currentSum > currentMax)
				currentMax = currentSum;
		}
	}
	return currentMax;
}

void printGrid(const vector<vector<int>>& grid)
{
	cout << "-----------------" << endl;
	for(int row=0; row < grid.size(); row++)
	{
		for(int col=0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

int main()
{

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

	//printGrid(arr);
	cout << getMaxHourglassSum(arr) << endl;

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
