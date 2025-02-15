#include <iostream>
#include <sstream>

auto main(int argc, char *argv[]) -> int {

    std::stringstream filename{"00205.txt"};

    int num = 0;
    std::string ext;

    filename >> num >> ext;

    std::cout << "Number is: " << num << std::endl;
    std::cout << "Extension is: " << ext << std::endl;

    return 0;
}
