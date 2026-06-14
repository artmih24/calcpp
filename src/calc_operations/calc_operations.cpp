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
        } else if (tokens[i] == "%") {
            long long int lhs = std::stold(tokens[i - 1]), 
                          rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = std::to_string(lhs % rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "//") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]),
                        lhsSign = 1.0L - 2.0L * (lhs < 0),
                        rhsSign = 1.0L - 2.0L * (rhs < 0),
                        res = 0.0L;
            while (lhs / lhsSign > 0) {
                if ((lhs - lhsSign * std::abs(rhs)) / lhsSign >= 0) {
                    res += 1.0L;
                    lhs -= lhsSign * std::abs(rhs);
                } else {
                    break;
                }
            }
            res *= rhsSign;
            tokens[i + 1] = std::to_string(res);
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
    for (int i = tokens.size() - 1; i >= 0; i--) {
        if (tokens[i] == "sqrt") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::sqrt(op));
            tokens[i + 1].clear();
        } else if (tokens[i] == "cbrt") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::cbrt(op));
            tokens[i + 1].clear();
        } else if (tokens[i] == "sqr") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(op * op);
            tokens[i + 1].clear();
        } else if (tokens[i] == "inv") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(1.0L / op);
            tokens[i + 1].clear();
        } else if (tokens[i] == "abs") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::abs(op));
            tokens[i + 1].clear();
        } else if (tokens[i] == "sin") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::sin(op));
            tokens[i + 1].clear();
        } else if (tokens[i] == "cos") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::cos(op));
            tokens[i + 1].clear();
        } else if (tokens[i] == "tan") {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = std::to_string(std::tan(op));
            tokens[i + 1].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}
