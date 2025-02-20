#include <iostream>

auto main(int argc, char *argv[]) -> int {

    int number1 = 15;
    int number2 = 017;
    int number3 = 0x0F;
    int number4 = 0b00001111;

    std::cout << "number1: " << number1 << "\n";
    std::cout << "number2: " << number2 << "\n";
    std::cout << "number3: " << number3 << "\n";
    std::cout << "number4: " << number4 << "\n";


    return 0;
}
