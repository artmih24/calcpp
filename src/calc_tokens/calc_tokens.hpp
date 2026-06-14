#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cmath>

std::ostream& operator<<(std::ostream& os, std::vector<std::string> tokens);

std::vector<std::string> FixRaw(std::vector<std::string> tokens);

std::vector<std::string> GetTokensFrom(std::string prompt);

std::vector<std::string> RemoveEmptyTokensFrom(std::vector<std::string> tokens);

std::string GetResultStringFrom(std::vector<std::string> tokens);
