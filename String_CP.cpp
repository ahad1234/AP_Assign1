#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

#include <conio.h>
using namespace std;
class String
{
public:

	String()
	{
		length = 0;
		string = NULL;
	}

	String(const char* str)
	{	
		length = strlen(str);
		string = new char[length];
		//strcpy_s(string, length, str);
		strcpy(string, str);
	}

	//Contructor to create a Copy
	String(const String& str)
	{
		length = str.length;
		string = new char[length];
		//strcpy_s(string, length, str.string);
		strcpy(string, str.string);
	}
	

	char charAt(int index) const
	{
		return string[index];
	}

	void print(char* str)
	{		for (int i = 0; i < strlen(str); i++)

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

	void newChar(int charLength)
	{
		char* temp = new char[length];
		//strcpy_s(temp, length,string);
		strcpy(temp, string);


		string = new char[length + charLength];
		//strcpy_s(string, length+charLength, temp);
		strcpy(string, temp);
		length += charLength;
	}

	void append(char addChar)
	{
		newChar(1);
		string[length - 1] = addChar;
		string[length] = '\0';
	}

	~String()
	{
		if (string != NULL)
		{
			cout << "Destrcuted!" << endl;
			delete[] string;
			string = NULL;
			
		}
	}

private:

	int length;
	char* string;
};


void main()
{
	String string("Testing my String.");
	String string2(string);
	cout << "Printing the Original!" << endl;;
	string.print();
	cout << "Printing the copy!" << endl;
	string2.append('a');
	string2.print();
	cout << "Char at 3 index: " << string2.charAt(3) << endl;
}
