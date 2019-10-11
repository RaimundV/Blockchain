#include "../headers/hashing.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <algorithm>

void option1()
{
    std::ifstream file;

    std::string symbol;

    file.open("..\\input files\\1letterFile_1.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }

    std::getline(file, symbol);

    stringToAscii(symbol);
    file.close();
    file.open("..\\input files\\1letterFile_2.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }
    std::getline(file, symbol);

    stringToAscii(symbol);
    file.close();
}

void option2()
{
    std::ifstream file;

    std::string symbols;

    file.open("..\\input files\\10kString_1.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }

    std::getline(file, symbols);

    stringToAscii(symbols);
    file.close();
    file.open("..\\input files\\10kString_2.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }
    std::getline(file, symbols);

    stringToAscii(symbols);
    file.close();
}

void option3()
{
    std::ifstream file;

    std::string symbols;

    file.open("..\\input files\\1SymbolDiff_1.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }

    std::getline(file, symbols);

    stringToAscii(symbols);
    file.close();
    file.open("..\\input files\\1SymbolDiff_2.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }
    std::getline(file, symbols);

    stringToAscii(symbols);
    file.close();
}

void option4()
{
    std::string input;

    std::cout << "Write symbols: ";
    std::cin >> input;
    stringToAscii(input);
}

void option5()
{
    std::ifstream file;

    std::string symbols;

    long long int nanoseconds = 0;
    file.open("..\\input files\\konstitucija.txt");

    if (!file)
    {
        std::cout << "file does not exits" << std::endl;
        return;
    }


    while(std::getline(file, symbols))
    {
        nanoseconds += stringToAscii(symbols);
    }

    std::cout << "Sum of nanoseconds taken: " << nanoseconds << std::endl;

}

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

void option6()
{
    int limit = 1000000;
    std::string symbolset1, symbolset2, hash1, hash2;

    for (int i = 0; i < limit; i++)
    {
        symbolset1 = random_string(5);
        symbolset2 = random_string(5);

        hash1 = stringToAsciiDiffCheck(symbolset1);
        hash2 = stringToAsciiDiffCheck(symbolset2);
        if (hash1 != hash2)
        {
            std::cout << symbolset1 << " good " << symbolset2 << i << std::endl;
        }
        else
        {
            if (symbolset1 != symbolset2)
            {
                std::cout << "bad" << std::endl;
                std::cout << symbolset1 << " " << symbolset2 << std::endl;
                break;
            }
        }
    }
}

void option7()
{
    int limit = 100000;
    std::string symbolset1, symbolset2, hash1, hash2;

    double symbolCounter;
    int counter;
    double size;
    double sum = 0;
    double min = 100000;
    double max = 0;

    for (int i = 0; i < limit; i++)
    {
        symbolset1 = random_string(5);
        symbolset2 = symbolset1;
        counter = 0;
        while (symbolset2 == symbolset1)
        {
            symbolset2[counter % 5] = symbolset2[counter % 5] + 1;
            counter ++;
        }

        hash1 = stringToAsciiDiffCheck(symbolset1);
        hash2 = stringToAsciiDiffCheck(symbolset2);

        size = hash1.length();
        symbolCounter = 0;
        for (int y = 0; y < size; y++)
        {
            if (hash1[y] != hash2[y])
            {
                symbolCounter++;
            }
        }

        if (symbolCounter > max)
            max = symbolCounter;

        if (symbolCounter < min)
            min = symbolCounter;

        sum += symbolCounter;
    }

    std::cout << "Average: " << sum * 100 / (size * limit) << std::endl;
    std::cout << "Min: " << min * 100 / size << std::endl;
    std::cout << "Max: " << max * 100 / size << std::endl;
}


int main()
{
    std::string inputWord;
    int         choice;

    std::cout << "Tests:" << std::endl;
    std::cout << "1. 2 files 1 symbol each" << std::endl;
    std::cout << "2. 2 files 10000 symbols each" << std::endl;
    std::cout << "3. 2 files with 1 different symbol" << std::endl;
    std::cout << "4. write your own inputs" << std::endl;
    std::cout << "5. Konstitucija.txt test" << std::endl;
    std::cout << "6. 1000000 random pairs" << std::endl;
    std::cout << "7. 100000 random pairs with 1 symbol difference" << std::endl;
    std::cout << "input choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            option1();
            break;
        case 2:
            option2();
            break;
        case 3:
            option3();
            break;
        case 4:
            option4();
            break;
        case 5:
            option5();
            break;
        case 6:
            option6();
            break;
        case 7:
            option7();
            break;
        default:
            std::cout << "There is no such option" << std::endl;
            break;
    }

    return 0;
}