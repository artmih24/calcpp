#include "calc_operations.hpp"

std::string ProcessAdditionsAndSubtractionsIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 1; i < tokens.size() - 1; i++) {
        if (tokens[i] == "+") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(lhs + rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "-") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(lhs - rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}

std::string ProcessMultiplicationsAndDivisionsIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 1; i < tokens.size() - 1; i++) {
        if (tokens[i] == "*") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(lhs * rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "/") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(lhs / rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}

std::string ProcessPowersIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 1; i < tokens.size() - 1; i++) {
        if (tokens[i] == "**") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(std::pow(lhs, rhs));
            tokens[i - 1].clear();
            tokens[i].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}

std::string ProcessFunctionsIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 0; i < tokens.size() - 1; i++) {
        if (tokens[i] == "sqrt") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(std::sqrt(op));
            tokens[i].clear();
        } else if (tokens[i] == "cbrt") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(std::cbrt(op));
            tokens[i].clear();
        } else if (tokens[i] == "sqr") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(op * op);
            tokens[i].clear();
        } else if (tokens[i] == "inv") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(1.0L / op);
            tokens[i].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}
