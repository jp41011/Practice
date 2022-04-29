#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


map<string, string> populateAddressBook()
{
	map<string, string> phoneBook;

	int numberOfEntries = 0;
	cin >> numberOfEntries;

	// Get name and phone number and add to phone book.
	for( int i = 0; i < numberOfEntries; i++)
	{
		string name = "";
		string phoneNumber = "";

		cin >> name;
		cin >> phoneNumber;

		phoneBook[name] = phoneNumber;
	}

	return phoneBook;
}

void printPhoneBook(map<string, string>& phoneBook)
{
	cout << "=========== Phone Book ===========" << endl;
	for(map<string, string>::iterator entry = phoneBook.begin(); entry != phoneBook.end(); ++entry)
	{
		cout << entry->first << " = " << entry->second << endl;
	}
	cout << "==================================" << endl;
	return;
}

void printPhoneNumber(map<string, string>& phoneBook, string name)
{
	//cout << "looking for: " << name << endl;

	if( phoneBook.count(name) == 0)
	{
		cout << "Not found" << endl;
		return;
	}

	cout << name << "=" << phoneBook[name] << endl;
	return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

	map<string, string> phoneBook;
	phoneBook = populateAddressBook();

	//printPhoneBook(phoneBook); // Test.

	string queryName = "";

	getline(cin, queryName, '\n'); // Get empty string out of the way.

	while( getline(cin, queryName, '\n') )
	{
		//cout << "queryName1: " << queryName.length() << " - " << queryName << endl;
		printPhoneNumber(phoneBook, queryName);
	}

    return 0;
}