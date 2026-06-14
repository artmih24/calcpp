#include "calc_tokens.hpp"

std::vector<std::string> FixRaw(std::vector<std::string> tokens) {
    std::vector<std::string> newTokens(tokens);
    for (size_t i = 0; i < newTokens.size(); i++) {
        if ((i > 0) && (newTokens[i] == "-") && ((newTokens[i - 1] == "+") || (newTokens[i - 1] == "-") || (newTokens[i - 1] == "*") || (newTokens[i - 1] == "/"))) {
            newTokens[i] = "";
            newTokens[i + 1] = "-" + newTokens[i + 1];
        } else if ((i == 0) && (newTokens[i] == "-")) {
            newTokens[i] = "";
            newTokens[i + 1] = "-" + newTokens[i + 1];
        } else if ((newTokens[i] == "*") && (newTokens[i + 1] == "*")) {
            newTokens[i] = "";
            newTokens[i + 1] = "**";
        }
    }
    newTokens = RemoveEmptyTokensFrom(newTokens);
    return newTokens;
}

std::vector<std::string> GetTokensFrom(std::string prompt) {
    std::vector<std::string> tokens{};
    std::string tmp{};
    for (auto c : prompt) {
        if ((c != '+') && (c != '-') && (c != '*') && (c != '/')) {
            tmp += c;
        } else {
            if (tmp.size() != 0) {
                tokens.push_back(tmp);
            }
            tokens.push_back(tmp = c);
            tmp.clear();
        }
    }
    if ((tokens.size() != 0) && (std::to_string(prompt.back()) != tokens.back())) {
        tokens.push_back(tmp);
    } else if ((tokens.size() == 0) && tmp == prompt) {
        tokens.push_back(tmp);
    }
    tokens = FixRaw(tokens);
    return tokens;
}

std::vector<std::string> RemoveEmptyTokensFrom(std::vector<std::string> tokens) {
    std::vector<std::string> newTokens{};
    for (auto t : tokens) {
        if (t != "") {
            newTokens.push_back(t);
        }
    }
    return newTokens;
}

std::string GetResultStringFrom(std::vector<std::string> tokens) {
    std::string result{};
    for (auto t : tokens) {
        result += t;
    }
    return result;
}
