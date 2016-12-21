#pragma once

#include "Structures.h"

#include <vector>
#include <string>
#include <utility>

namespace FileReader
{
	void readSprite(std::string path, std::vector<pixel>& sprite);
	void readPhysicsIgnore(std::string path, std::vector<PhysicsIgnore>& ignore);

	void split(const std::string &s, char delim, std::vector<std::string> &elems);
	std::vector<std::string> split(const std::string &s, char delim);
}

