#include "calc_process.hpp"

int main(int argc, char** argv) {
    if (argc == 1) {
        while (1) {
            std::string prompt(GetUserInput());
            if ((prompt == "q") || (prompt == "quit") || (prompt == "exit") || (prompt == "Q")) {
                break;
            }
            Calculate(prompt);
        }
    } else {
        std::string prompt{};
        for (int i = 1; i < argc; i++) {
            prompt += argv[i];
        }
        Calculate(prompt);
    }
    return 0;
}
