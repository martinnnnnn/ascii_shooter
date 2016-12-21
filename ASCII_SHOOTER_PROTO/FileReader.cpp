#include "FileReader.h"

#include "Structures.h"

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;



void FileReader::readSprite(string path, vector<pixel>& sprite)
{
	ifstream file(path);
	string str;
	int i = 0;
	unsigned int j;

	CHAR_INFO c;
	c.Attributes = 0x0A;

	while (getline(file, str))
	{
		for (j = 0; j < str.length(); ++j)
		{
			c.Char.UnicodeChar = str[j];
			sprite.push_back(pixel{ c,(int)j,i });
		}
		++i;
	}
}

void FileReader::readPhysicsIgnore(string path, vector<PhysicsIgnore>& ignore)
{
	ifstream file(path);
	string str;

	vector<string> splitedLine;

	while (getline(file, str))
	{
		splitedLine = split(str, ':');
		ignore.push_back({ splitedLine[0],splitedLine[1] });
	}
}



void FileReader::split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


vector<std::string> FileReader::split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}