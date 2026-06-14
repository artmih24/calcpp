#include "print_help_info.hpp"

void PrintHelpInfo() {
    std::cout << "input:" << std::endl;
    std::cout << "    write your prompt" << std::endl;
    std::cout << "    examples:" << std::endl;
    std::cout << "    1 + 2                - addition" << std::endl;
    std::cout << "    2 - 1                - subtraction" << std::endl;
    std::cout << "    2 * 2                - multiplication" << std::endl;
    std::cout << "    2 / 2                - division" << std::endl;
    std::cout << "    2 ** 3               - power (Python-style)" << std::endl;
    std::cout << "    1+2                  - it can process spaces between operators and operands" << std::endl;
    std::cout << "    2 + -1               - it supports negative numbers" << std::endl;
    std::cout << "    1.1 + 2              - it supports fractions" << std::endl;
    std::cout << "    2 / 0                - no division by zero errors!" << std::endl;
    std::cout << "    1 + 2 + 3 + 4 + 5    - supports many operations in prompt!" << std::endl;
    std::cout << "    (1 + 2) * 3          - braces support" << std::endl;
    std::cout << "    supported operators: + - * / **" << std::endl;
    std::cout << "    supported constants: pi, e" << std::endl;
    std::cout << "    supported functions:" << std::endl;
    std::cout << "        sqr(x)           - x ** 2" << std::endl;
    std::cout << "        sqrt(x)          - square root of x" << std::endl;
    std::cout << "        cbrt(x)          - cube root of x" << std::endl;
    std::cout << "        inv(x)           - 1 / x" << std::endl;
    std::cout << std::endl << "    commands:" << std::endl;
    std::cout << "        \"help\" | \"-help\" | \"--help\" | \"h\" | \"-h\" | \"--h\" | \"H\" | \"-H\" | \"--H\" - for help (to view this text)" << std::endl;
    std::cout << "        \"q\" | \"quit\" | \"exit\" | \"Q\"                                           - quit from program" << std::endl;
    std::cout << std::endl << "arguments:" << std::endl;
    std::cout << "    \"help\" | \"-help\" | \"--help\" | \"h\" | \"-h\" | \"--h\" | \"H\" | \"-H\" | \"--H\" - for help (to view this text)" << std::endl;
    std::cout << "    you can also enter your prompt in arguments!" << std::endl;
}
