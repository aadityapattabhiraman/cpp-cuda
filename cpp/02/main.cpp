#include <iostream>

int add_numbers(int a, int b) {

    return a + b;
}

auto main(int argc, char *argv[]) -> int {

    int first_number {3};
    int second_number {7};

    std::cout << "First number: " << first_number << "\n";
    std::cout << "Second number: " << second_number << "\n";

    int sum = add_numbers(first_number, second_number);

    std::cout << "Sum: " << sum << "\n";

    return 0;
}
