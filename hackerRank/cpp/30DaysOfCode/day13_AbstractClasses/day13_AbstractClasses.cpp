#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

// Write your MyBook class here
class MyBook: Book{
	protected: 
	int price;

	public:
		MyBook(string title, string author, int price) : Book(title, author)
		{
			// could also set the price before the constructor body
			// and after the Book() constructor call.
			this->price = price;
		}

		void display()
		{
			cout << "Title: " << this->title << endl;
			cout << "Author: " << this->author << endl;
			cout << "Price: " << this->price << endl;
			return;
		}
};
// End class

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
