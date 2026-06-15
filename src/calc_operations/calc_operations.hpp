#pragma once

#include <cmath>

#include "calc_string.hpp"
#include "calc_tokens.hpp"

std::string ProcessAdditionsAndSubtractionsIn(std::string prompt);

std::string ProcessMultiplicationsAndDivisionsIn(std::string prompt);

std::string ProcessPowersIn(std::string prompt);

std::string ProcessFunctionsIn(std::string prompt);
