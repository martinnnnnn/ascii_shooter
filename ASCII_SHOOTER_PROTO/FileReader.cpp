#include "FileReader.h"

#include <fstream>
#include <iostream>
#include <string>


using namespace std;



void FileReader::readSprite(string path, vector<pixel>& sprite)
{
	ifstream file(path);
	string str;
	int i = 0;
	unsigned int j;

	CHAR_INFO c;
	c.Attributes = 0x0A;

	while (std::getline(file, str))
	{
		for (j = 0; j < str.length(); ++j)
		{
			c.Char.UnicodeChar = str[j];
			sprite.push_back(pixel{ c,(int)j,i });
		}
		++i;
	}
}
