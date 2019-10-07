//
// Created by 123 on 2019-10-06.
//
#include <vector>

#ifndef BLOCKCHAINHASHING_RECOUNTVECTOR_H
#define BLOCKCHAINHASHING_RECOUNTVECTOR_H

std::vector <unsigned long long int> hashOption1(std::vector <unsigned long long int> _ascii, std::vector <unsigned long long int> _hasher)
{
    for (int i = 0; i < _hasher.size(); i++)
    {
        _hasher[_hasher.size() - i - 1] = _hasher[_hasher.size() - i - 1] * _ascii[i];
    }

    return _hasher;
}

std::vector <unsigned long long int> hashOption2(std::vector <unsigned long long int> _ascii, std::vector <unsigned long long int> _hasher)
{
    for (int i = 0; i < _hasher.size(); i++)
    {
        if (i < 10)
            _hasher[i] = _hasher[i] * _ascii[i + 10];
        else
            _hasher[i] = _hasher[i] * _ascii[i - 10];
    }

    return _hasher;
}

std::vector <unsigned long long int> hashOption3(std::vector <unsigned long long int> _ascii, std::vector <unsigned long long int> _hasher)
{
    for (int i = 0; i < _hasher.size(); i++)
    {
        if (i >= 15)
            _hasher[i] = _hasher[i] * _ascii[i - 5];
        else if (i >= 10)
            _hasher[i] = _hasher[i] * _ascii[i + 6];
        else if (i >= 5)
            _hasher[i] = _hasher[i] * _ascii[i - 5];
        else
            _hasher[i] = _hasher[i] * _ascii[i + 5];
    }

    return _hasher;
}

std::vector <unsigned long long int> hashOptionDefault(std::vector <unsigned long long int> _ascii, std::vector <unsigned long long int> _hasher)
{
    for (int i = 0; i < _hasher.size(); i++)
    {
        _hasher[i] = _hasher[i] * _ascii[i];
    }

    return _hasher;
}

std::vector <unsigned long long int> hashRecount(std::vector <unsigned long long int> _ascii, std::vector <unsigned long long int> _hasher, int _var)
{
    int size = _hasher.size();

    switch (_var)
    {
        case 1:
            return hashOption1(_ascii, _hasher);
        case 2:
            return hashOption2(_ascii, _hasher);
        case 3:
            return hashOption3(_ascii, _hasher);
        default:
            return hashOptionDefault(_ascii, _hasher);
    }
}

#endif //BLOCKCHAINHASHING_RECOUNTVECTOR_H
