#include "Header.h"

using namespace std;

String::String() : str(NULL) {};

String::String(char *s) {
	int l = strlen(s);
	this->str = new char[l];
	strcpy_s(str, l + 1, s);
};

String::String(const String &ob) {
	str = ob.str;
}

int String::operator>(String S) {
	int i = 0, temp;
	while (S.str[i] != '\0' && str[i] != '\0') {
		if((temp = S.str[i] - str[i]) != 0) return temp;
		i++;
	}
	return 0;
}

istream& operator >> (istream& stream, String& object) {
	char n[256];
	stream.getline(n, 256);
	int l = stream.gcount();
	object.str = new char[l];
	strcpy_s(object.str, l, n);
	stream.clear();
	stream.ignore(stream.rdbuf()->in_avail());
	return stream;
}

String::~String() {
	if(str)
		delete [] str;
};
