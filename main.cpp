#include <iostream>
#include <string>
#include <sstream>

std::string ToHex(int hashedString)
{
    std::string hash;
    std::stringstream hexstr;
    hexstr << std::hex << hashedString;
    hash = hexstr.str();
    return hash;
}

std::string hashing(std::string input)
{
    int randNum1 = 23134;
    int randNum2 = 55123;
    int randNum3 = 29510;
    int hash;
    for (int i = 0; i < input.length(); i++)
    {
        hash = (hash ^ input[i]) * randNum1 * randNum2 ^ input[i] / randNum3;
    }
    std::cout << hash << std::endl;
    return ToHex(hash);
}

int main()
{
    std::string inputWord;
    std::cout << "input text: ";
    std::cin >> inputWord;
    std::cout << std::endl;
    std::cout << hashing(inputWord) << std::endl;
    std::cout << "input text: ";
    std::cin >> inputWord;
    std::cout << std::endl;
    std::cout << hashing(inputWord) << std::endl;

    return 0;
}