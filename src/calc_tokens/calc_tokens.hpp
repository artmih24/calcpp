#pragma once

#include <string>
#include <vector>

std::vector<std::string> FixRaw(std::vector<std::string> tokens);

std::vector<std::string> GetTokensFrom(std::string prompt);

std::vector<std::string> RemoveEmptyTokensFrom(std::vector<std::string> tokens);

std::string GetResultStringFrom(std::vector<std::string> tokens);
