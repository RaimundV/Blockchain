#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
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
    long long int uplimit = 99999999;
    long long int lowlimit= 10000000;
    if (_number > uplimit)
        _number = recount(_number - ((_number - uplimit) * _times));
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

    std::vector <unsigned long long int> hasher = { 123, 35, 62, 132, 54, 69, 21, 34, 41, 91, 111, 83, 55, 44, 32, 142, 47, 128, 23, 98, 96};

    int value = 20;
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

std::string stringToAscii(std::string _input)
{
    std::vector <unsigned long long int> ascii;
    ascii.clear();
    ascii.push_back(_input.length());

    for (int i = 0; i < _input.length(); i++)
    {
        ascii.push_back( (unsigned long long int) _input[i] );
    }

    return hashing(ascii, _input.length());
}
#endif //BLOCKCHAINHASHING_HASHING_H