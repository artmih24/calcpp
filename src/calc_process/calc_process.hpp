#pragma once

#include <tuple>

#include "calc_operations.hpp"
#include "calc_string.hpp"
#include "print_help_info.hpp"

std::string ProcessSubstring(std::string prompt);

std::string ProcessWhole(std::string prompt);

std::string Process(std::string prompt);

void Calculate(std::string prompt);
