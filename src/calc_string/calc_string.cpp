#include "calc_string.hpp"

std::string GetUserInput() {
    std::string userInput{};
    std::cout << ">> ";
    getline(std::cin, userInput);
    return userInput;
}

std::string DeleteSpacesFrom(std::string userInput) {
    std::string userInputWithoutSpaces{};
    for (auto c : userInput) {
        if (c != ' ') {
            userInputWithoutSpaces += c;
        }
    }
    return userInputWithoutSpaces;
}

std::string DeleteTrailingZerosFrom(std::string str) {
    bool isFraction = false,
         isMessage = false;
    std::string result(str);
    for (auto c : result) {
        if (c == '.') {
            isFraction = true;
            break;
        }
        if (c == '!') {
            isMessage = true;
            break;
        }
    }
    if (isMessage) {
        return result;
    }
    if (isFraction) {
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i] != '0') {
                break;
            } else {
                result.replace(i, 1, " ");
            }
        }
        result = DeleteSpacesFrom(result);
        if (result[result.size() - 1] == '.') {
            result.replace(result.size() - 1, 1, " ");
        }
        result = DeleteSpacesFrom(result);
    }
    return result;
}

std::string MakeStringFrom(long double val) {
    std::stringstream ss;
    const auto default_precision{ss.precision()};
    ss << std::fixed << std::setprecision(std::numeric_limits<long double>::max_digits10) << val << std::setprecision(default_precision);
    std::string result = ss.str();
    return result;
}

std::string MakeStringFrom(long long int val) {
    std::string result = std::to_string(val);
    return result;
}
