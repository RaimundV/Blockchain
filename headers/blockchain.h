//
// Created by 123 on 2019-10-17.
//

#ifndef BLOCKCHAINHASHING_BLOCKCHAIN_H
#define BLOCKCHAINHASHING_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t Difficulty;
    std::vector<Block> Chain;

    Block _GetLastBlock() const;
};

Blockchain::Blockchain()
{
    TransAction trans;
    trans.AddTrans("","","","","");
    Chain.emplace_back(Block(0, trans));
    Difficulty = 1;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.PrevHash = _GetLastBlock().Hash;
    bNew.MineBlock(Difficulty);
    Chain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return Chain.back();
}

#endif //BLOCKCHAINHASHING_BLOCKCHAIN_H
