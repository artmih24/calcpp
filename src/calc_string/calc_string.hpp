#pragma once

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

std::string GetUserInput();

std::string DeleteSpacesFrom(std::string userInput);

std::string DeleteTrailingZerosFrom(std::string str);

std::string MakeStringFrom(long double val);

std::string MakeStringFrom(long long int val);
