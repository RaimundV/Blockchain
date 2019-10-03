//
// Created by 123 on 2019-10-03.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

long long int recount(long long int _number, int _times = 3)
{
    long long int uplimit = 9999999999;
    long long int lowlimit= 1000000000;
    if (_number > uplimit)
        return (_number - ((_number - uplimit) * _times));
    if (_number < lowlimit)
        return (_number + ((lowlimit - _number) * _times));

    return _number;
}

std::string hashing(std::vector <long long int> _ascii, int _length)
{
    std::string hashed = "";
    int randNumL1 = 214;
    int randNumL2 = 953;
    int randNumL3 = 5;
    int delL      = 3;

    int randNum1 = 31;
    int randNum2 = 75;
    int randNum3 = 532;
    int del      = 2;

    int value = 10;
    int size = _ascii.size() - 1;

    for (int i = 0; i < value - size; i++)
    {
        _ascii.push_back(_ascii[1] / 3 + (100 * (i + 1)));
    }

    for (int i = value+1; i < _ascii.size(); i++)
    {
        if (i % value != 0)
            _ascii[i % value] += _ascii[i];
        else
            _ascii[value] += _ascii[i];
    }

    _ascii[0] = (_ascii[0] * randNumL2 * randNumL1 * randNumL3) / delL;
    _ascii[0] = recount(_ascii[0]);
    for (int i = 1; i <= value; i++)
    {
        _ascii[i] = (_ascii[i] * randNum2 * randNum1 * randNum3);
        _ascii[i] = recount(_ascii[i], i);
    }

    for (int i = 0; i <= value; i++)
    {
        hashed += ToHex(_ascii[i]);
    }

    return hashed;
}

std::string stringToAscii(std::string _input)
{
    std::vector <long long int> ascii;
    ascii.clear();
    ascii.push_back(_input.length());

    for (int i = 1; i <= _input.length(); i++)
    {
        if (_input[i] % 2 == 0)
            ascii.push_back( _input[i] + (100 * i) );
        else
            ascii.push_back( (_input[i] + (100 - i * 4)) < 0 ? (_input[i] + (100 - i * 4)) * -1: _input[i] + (100 - i * 4)) ;
    }

    return hashing(ascii, _input.length());
}
#endif //BLOCKCHAINHASHING_HASHING_H
