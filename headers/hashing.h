#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include "recountVector.h"

#ifndef BLOCKCHAINHASHING_HASHING_H
#define BLOCKCHAINHASHING_HASHING_H

std::string ToHex(long int hashedString)
{
    std::string hash;
    std::stringstream hexstr;
    hexstr << std::hex << hashedString;
    hash = hexstr.str();
    return hash;
}

unsigned long long int recount(unsigned long long int _number, int _times = 2)
{
    long long int uplimit = 9999999;
    long long int lowlimit= 1000000;
    if (_number > uplimit)
        _number = recount(_number - ((_number - uplimit)));// * _times));
    if (_number < lowlimit)
        _number = recount(_number + (lowlimit * _times));

    return _number;
}

unsigned long long int avgAscii(std::vector <unsigned long long int> _ascii)
{
    long long int num = 0;

    for (int i = 0; i < _ascii.size(); i++)
    {
        num += _ascii[i];
    }

    return num / _ascii.size();
}

std::string hashing(std::vector <unsigned long long int> _ascii, int _length)
{
    std::string hashed = "";

    std::vector <unsigned long long int> hasher = { 123, 335, 762, 132, 254, 369, 421, 234, 741, 191,
                                                    111, 83, 455, 244, 132, 142, 347, 128, 623, 398, 296,
                                                    215, 333, 159, 420, 320, 301, 555, 101, 196, 299};

    int value = 30;
    int size = _ascii.size() - 1;

    for (int i = 0; i < value - size; i++)
    {
        switch(avgAscii(_ascii) % 3)
        {
            case 0:
                _ascii.push_back( hasher[avgAscii(_ascii) % 10] );
                break;
            case 1:
                _ascii.push_back( hasher[(avgAscii(_ascii) % 11) + 10] );
                break;
            case 2:
                _ascii.push_back( hasher[avgAscii(_ascii) % 6 * 2] );
                break;
            default:
                _ascii.push_back( hasher[avgAscii(_ascii) % 21] );
                break;
        }
    }

    for (int i = value+1; i < _ascii.size(); i++)
    {
        if (i % value != 0)
            _ascii[i % value] += _ascii[i];
        else
            _ascii[value] += _ascii[i];
    }

    if (_ascii.size() > value + 1)
        _ascii.erase(_ascii.begin() + value + 1, _ascii.end());

    _ascii = hashRecount(_ascii, hasher, (_ascii[0] + _ascii[1]) % 4);

    for (int i = 0; i < _ascii.size(); i++)
    {
        _ascii[i] = recount(_ascii[i]);
    }

    for (int i = 0; i <= value; i++)
    {
        hashed += ToHex(_ascii[i]);
    }

    return hashed;
}

long long int stringToAscii(std::string _input)
{
    std::vector <unsigned long long int> ascii;
    ascii.erase(ascii.begin(), ascii.end());
    auto start = std::chrono::high_resolution_clock::now();
    ascii.push_back(_input.length());

    for (int i = 0; i < _input.length(); i++)
    {
        ascii.push_back( (unsigned long long int) _input[i] );
    }

    std::string hash = hashing(ascii, _input.length());

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << _input << " = " << hash << std::endl;
    std::cout << "In " << duration.count() << " nanoseconds" << std::endl;

    std::ofstream fileOut;

    fileOut.open("..\\Output files\\output.txt", std::fstream::app);

    fileOut << hash + "\n\r";
    fileOut.close();

    return duration.count();
}

std::string stringToAsciiDiffCheck(std::string _input)
{
    std::vector <unsigned long long int> ascii;

    ascii.erase(ascii.begin(), ascii.end());

    ascii.push_back(_input.length());

    for (int i = 0; i < _input.length(); i++)
    {
        ascii.push_back( (unsigned long long int) _input[i] );
    }

    return hashing(ascii, _input.length());
}
#endif //BLOCKCHAINHASHING_HASHING_H