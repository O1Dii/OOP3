#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class String {
	char *str;
public:
	friend istream& operator >> (istream&, String&);
	String();
	String(char *s);
	String(const String &);
	int operator>(String s);
	~String();
};