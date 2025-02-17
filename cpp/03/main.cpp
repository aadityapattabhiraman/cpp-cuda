#include <algorithm>
#include <iostream>

auto main(int argc, char *argv[]) -> int {

    int age;
    std::string name;

    std::cout << "Enter your name and age: ";
    std::getline(std::cin, name);
    std::cin >> age;

    std::cout << "Hello " << name << " you are " << age << " years old! \n";
    return 0;
}
