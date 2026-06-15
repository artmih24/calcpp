#include "calc_operations.hpp"

std::string ProcessAdditionsAndSubtractionsIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 1; i < tokens.size() - 1; i++) {
        if (tokens[i] == "+") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = MakeStringFrom(lhs + rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "-") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = MakeStringFrom(lhs - rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}

long double GetSignOf(long double val) {
    long double result = 1.0L - 2.0L * (val < 0.0L);
    return result;
}

std::string ProcessMultiplicationsAndDivisionsIn(std::string prompt) {
    std::string result{};
    std::vector<std::string> tokens(GetTokensFrom(prompt));
    for (size_t i = 1; i < tokens.size() - 1; i++) {
        if (tokens[i] == "*") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = MakeStringFrom(lhs * rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "/") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = MakeStringFrom(lhs / rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "%") {
            long long int lhs = std::stold(tokens[i - 1]), 
                          rhs = std::stold(tokens[i + 1]);
            tokens[i + 1] = MakeStringFrom(lhs % rhs);
            tokens[i - 1].clear();
            tokens[i].clear();
        } else if (tokens[i] == "//") {
            long double lhs = std::stold(tokens[i - 1]), 
                        rhs = std::stold(tokens[i + 1]),
                        lhsSign = GetSignOf(lhs),
                        rhsSign = GetSignOf(rhs),
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
            tokens[i + 1] = MakeStringFrom(res);
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
            tokens[i + 1] = MakeStringFrom(std::pow(lhs, rhs));
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
        if (std::string f = "sqrt"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::sqrt(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "cbrt"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::cbrt(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "sqr"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(op * op * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "inv"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(1.0L / op * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "abs"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::abs(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "sin"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::sin(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "cos"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::cos(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        } else if (std::string f = "tan"; tokens[i].find(f) != std::string::npos) {
            long double op = std::stold(tokens[i + 1]);
            tokens[i] = MakeStringFrom(std::tan(op) * ((tokens[i] == f) ? 1.0L : -1.0L));
            tokens[i + 1].clear();
        }
    }
    tokens = RemoveEmptyTokensFrom(tokens);
    result = GetResultStringFrom(tokens);
    return result;
}
