#include "../headers/hashing.h"

int main()
{
    std::string inputWord;
    std::cout << "input text: ";
    std::cin >> inputWord;

    std::cout << std::endl;
    std::cout << stringToAscii(inputWord) << std::endl;

    std::cout << "input text: ";
    std::cin >> inputWord;
    std::cout << std::endl;
    std::cout << stringToAscii(inputWord) << std::endl;

    return 0;
}