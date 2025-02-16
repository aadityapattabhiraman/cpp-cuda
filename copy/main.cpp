#include <iostream>
#include <string>

auto main(int argc, char *argv[]) -> int {
    const std::string source{"Copy this!"};
    std::string dest = source;

    std::cout << source << "\n";
    std::cout << dest << "\n";

    return 0;
}
