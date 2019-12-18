//
// Created by 123 on 2019-10-17.
//

#ifndef BLOCKCHAINHASHING_BLOCK_H
#define BLOCKCHAINHASHING_BLOCK_H

#include <iostream>
#include <cstdint>
#include <vector>
#include "hashing.h"
#include "transactionList.h"

class Block
{
public:

    std::string Hash;
    std::string PrevHash;

    Block(uint32_t blockIdx, TransAction transIn);

    void addTransAction(TransAction newTrans);
    void MineBlock(uint32_t nDifficulty);

private:
    std::vector<TransAction> trans;
    uint32_t block;
    uint32_t Nonce;
    time_t Time;

    std::string _CalculateHash();
};

Block::Block(uint32_t blockIdx, TransAction transIn) : block(blockIdx)
{
    Nonce = 0;
    Time = std::time(nullptr);

    trans.emplace_back(transIn);

    Hash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    std::string test;
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        test += '1';
    }

    unsigned int size;
    std::string test2;

    do
    {
        Nonce++;
        Hash = _CalculateHash();
        test2 = Hash.substr(0, nDifficulty);
        size = Hash.size();
    }
    while (Hash.substr(0, nDifficulty) != test);

    std::cout << "Block mined: " << Hash << std::endl;
}

inline std::string Block::_CalculateHash()
{
    std::stringstream ss;
    std::string       transIdCombo = "";

    //TODO: add merkle tree?

    for (auto i = 0; i < trans.size(); i++)
        transIdCombo += trans[i].returnId();

    ss << block << PrevHash << Time << transIdCombo << Nonce;

    return stringToAsciiDiffCheck(ss.str());
}

void Block::addTransAction(TransAction newTrans) {

    if (newTrans.returnId() == stringToAsciiDiffCheck(newTrans.returnStrCombo()))
    {
        trans.emplace_back(newTrans);

        Hash = _CalculateHash();
    }
}

#endif //BLOCKCHAINHASHING_BLOCK_H
