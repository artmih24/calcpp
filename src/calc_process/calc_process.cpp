#include "calc_process.hpp"

std::string ProcessSubstring(std::string prompt) {
    std::string result{prompt};
    result = ProcessPowersIn(result);
    result = ProcessMultiplicationsAndDivisionsIn(result);
    result = ProcessAdditionsAndSubtractionsIn(result);
    return result;
}

std::string ProcessWhole(std::string prompt) {
    int maxBracesDepth = 0,
        bracesState = 0;
    std::string result{};
    std::vector<std::tuple<int, int, int>> bracesDepthsMap{};
    for (size_t i = 0; i < prompt.size(); i++) {
        if ((i > 0) && (prompt[i - 1] == '(')) {
            bracesState++;
            bracesDepthsMap.emplace_back(bracesState, i, i - 1);
            if (bracesState > maxBracesDepth) {
                maxBracesDepth = bracesState;
            }
        } else if ((i < prompt.size()) && (prompt[i + 1] == ')')) {
            bracesState--;
            bracesDepthsMap.emplace_back(bracesState, i + 1, i + 2);
        }
    }
    if (maxBracesDepth > 0) {
        // std::cout << prompt << std::endl;
        for (int i = 1, d = maxBracesDepth; i < maxBracesDepth + 1; i++, d--) {
            std::vector<std::string> subprompt{};
            for (size_t j = 0; j < bracesDepthsMap.size(); j++) {
                if (std::get<0>(bracesDepthsMap[j]) == d) {
                    // std::cout << "i = " << i << ", j = " << j << ": " << prompt << std::endl;
                    // for (auto it : bracesDepthsMap) {
                    //     std::cout << std::get<0>(it) << "," << std::get<1>(it) << "," << std::get<2>(it) << std::endl;
                    // }

                    // getting substring to change (with braces)
                    int toChangeStart = std::get<2>(bracesDepthsMap[j]),
                        toChangeEnd   = std::get<2>(bracesDepthsMap[j + 1]),
                        toChangeLength = toChangeEnd - toChangeStart;
                    std::string toChange = prompt.substr(toChangeStart, toChangeLength);
                    // getting subprompt to process (in braces)
                    int subpromptStart = std::get<1>(bracesDepthsMap[j]),
                        subpromptEnd   = std::get<1>(bracesDepthsMap[j + 1]),
                        subpromptLength = subpromptEnd - subpromptStart;
                    std::string subprompt = prompt.substr(subpromptStart, subpromptLength);
                    std::string result = ProcessSubstring(subprompt);
                    // position of substring to change
                    int currentPosition = std::get<2>(bracesDepthsMap[j]);
                    prompt.replace(currentPosition, toChange.length(), result);
                    // characters positions shift after substrings change
                    int rightPositionsShift = result.size() - toChangeLength;
                    // changing depths map
                    for (size_t k = j; k < bracesDepthsMap.size() - 2; k++) {
                        bracesDepthsMap[k] = std::make_tuple(std::get<0>(bracesDepthsMap[k + 2]), std::get<1>(bracesDepthsMap[k + 2]) + rightPositionsShift, std::get<2>(bracesDepthsMap[k + 2]) + rightPositionsShift);
                    }
                    // same index value on next iteration
                    j--;
                    // making last two items useless
                    bracesDepthsMap[bracesDepthsMap.size() - 1] = std::make_tuple(-1, 0, 0);
                    bracesDepthsMap[bracesDepthsMap.size() - 2] = std::make_tuple(-1, 0, 0);


                    // std::cout << toChangeLength << " - " << result.size() << " -> " << delta << std::endl;
                    // std::cout << subprompt << ": " << toChange << " -> " << result << ": " << prompt << std::endl;

                }   
            }
        }
    }
    result = ProcessSubstring(prompt);
    return result;
}

std::string Process(std::string prompt) {
    int bracesState = 0;
    for (auto c : prompt) {
        bracesState += ((c == '(') - (c == ')'));
        if (bracesState < 0) {
            break;
        }
    }
    if (bracesState != 0) {
        std::string result = "Incorrect braces!";
        return result;
    } else {
        std::string result = ProcessWhole(prompt);
        return result;
    }
}

void Calculate(std::string prompt) {
    if ((prompt == "help") || (prompt == "-help") || (prompt == "--help") || (prompt == "h") || (prompt == "-h") || (prompt == "--h") || (prompt == "H") || (prompt == "-H") || (prompt == "--H")) {
        PrintHelpInfo();
        return;
    }
    std::string userInput = (DeleteSpacesFrom(prompt));
    std::string processedUserInput(Process(userInput));
    processedUserInput = DeleteTrailingZerosFrom(processedUserInput);
    std::cout << processedUserInput << std::endl;
}