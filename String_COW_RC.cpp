#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class String
{
public:

	String()
	{
		length = 0;
		string = NULL;
		refC = 1; //initialiizng reference Count to 1 for first pointer
	}

	String(const char* str)
	{
		length = strlen(str);
		string = new char[length];
		refC = 1;

		strcpy(string, str);
	}

	//Constructor to create a Copy 
	String(const String& str)
	{
		length = str.length;
		string = new char[length];
		refC += 1; //increments reference count by 1

		strcpy(string, str.string);
	}

	char charAt(int index) const
	{
		return string[index];
	}


	void print(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	void print()
	{
		for (int i = 0; i < length; i++)
		{
			cout << string[i];
		}
		cout << endl;
	}

	void reserve(int charL)
	{
		char* temp = new char[length];
		strcpy(temp, string);

		string = new char[length + charL];
		strcpy(string, temp);
		length += charL;
	}

	void append(char newC)
	{
		reserve(1);
		string[length - 1] = newC;
		string[length] = '\0';
	}

	~String()
	{
		refC -= 1; // decrementing refCount by -1
		// Checks if refCount = 0 then deletes the pointer
		if (refC == 0)  
		{
			if (string != NULL)
			{
				cout << "Destructed!" << endl;
				delete[] string;
				string = NULL;
			}
		}
	}

private:

	int length;
	static int refC;
	char* string;
};

int String:: refC = 0;

int main(int argc, char *argv[])
{
	String string("Testing my String."); //Original String
	String string2(string);	//Copy of String
	cout << "Printing the Original!" << endl;;
	string.print();
	cout << "Printing the copy!" << endl;
	string2.append('a');
	string2.print();
	cout << "Char at 3 index: " << string2.charAt(3) << endl;

	return 0;
}

