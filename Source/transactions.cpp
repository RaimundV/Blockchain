//
// Created by 123 on 2019-11-27.
//

#include "../headers/userList.h"
#include "../headers/block.h"
#include "../headers/transactionList.h"
#include <ctime>

void generateUsers()
{
    auto amount = 1000;
    Users user[amount];
    std::vector<TransAction> transactions;
    Blockchain bChain = Blockchain();

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    int amountMoney;
    srand((unsigned)time(0));
    int userFrom;
    int userTo;

    for (auto i = 0; i < amount / 10; i++)
    {
        user[i].AddUser(i + 1, "user" + std::to_string(i + 1), "surname" + std::to_string(i + 1), amount * 10);
    }

    //transactions
    for (auto i = 0; i < amount; i++)
    {
        userFrom = (rand() % amount);
        amountMoney = (rand() % amount / 10) + 1;
        userTo = (rand() % amount);

        time (&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
        std::string dateVal(buffer);
        strftime(buffer,sizeof(buffer),"%H:%M:%S",timeinfo);
        std::string timeVal(buffer);

        if (!user[userFrom].tranaction(amountMoney, user[userTo]))
        {
            //std::cout << user[userFrom].userNameAndSurname() << " does not have enough money: " << amountMoney << std::endl;
            i--;
        }
        else
        {
            transactions.emplace_back(TransAction(
                    std::to_string(userFrom),
                    std::to_string(userTo),
                    std::to_string(amountMoney),
                    dateVal,
                    timeVal)
                    );
        }
    }

    Block _1A = Block(1, TransAction());
    Block _1B = Block(2, TransAction());
    Block _1C = Block(3, TransAction());
    Block _1D = Block(4, TransAction());
    Block _1E = Block(5, TransAction());

    for (int i = 0; i < transactions.size(); i++)
    {
        switch (i % 5)
        {
            case 0:
                _1A.addTransAction(transactions[i]);
                break;
            case 1:
                _1B.addTransAction(transactions[i]);
                break;
            case 2:
                _1C.addTransAction(transactions[i]);
                break;
            case 3:
                _1D.addTransAction(transactions[i]);
                break;
            case 4:
                _1E.addTransAction(transactions[i]);
                break;
            default:
                break;
        }
    }


    bChain.AddBlock(_1A);
    bChain.AddBlock(_1B);
    bChain.AddBlock(_1C);
    bChain.AddBlock(_1D);
    bChain.AddBlock(_1E);

    std::cout << std::endl;
    std::cout << "merkle hashes" << std::endl;
    std::cout << "1 A: " << _1A.MerkleHash << std::endl;
    std::cout << "1 B: " << _1B.MerkleHash << std::endl;
    std::cout << "1 C: " << _1C.MerkleHash << std::endl;
    std::cout << "1 D: " << _1D.MerkleHash << std::endl;
    std::cout << "1 E: " << _1E.MerkleHash << std::endl;
}