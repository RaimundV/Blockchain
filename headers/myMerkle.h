//
// Created by 123 on 2019-12-18.
//

#ifndef BLOCKCHAINHASHING_MYMERKLE_H
#define BLOCKCHAINHASHING_MYMERKLE_H

#include "transactionList.h"
#include "hashing.h"

std::vector<std::string> createMerkle(std::vector<std::string> _transId)
{
    std::vector<std::string> newTrans;

    if (_transId.empty())
    {
        _transId.emplace_back(stringToAsciiDiffCheck("null"));
        return _transId;
    }

    if (_transId.size() == 1)
        return  _transId;

    for (int i = 0; i < _transId.size(); i++)
    {
        if (_transId.size() % 2 != 0)
        {
            auto _size = _transId.size();
            _transId.emplace_back(_transId[_size - 1]);
        }

        newTrans.emplace_back( stringToAsciiDiffCheck( _transId[i] + _transId[i + 1] ) );

        i++;
    }

    if (newTrans.size() != 1)
        newTrans = createMerkle(newTrans);

    return  newTrans;
}


#endif //BLOCKCHAINHASHING_MYMERKLE_H
