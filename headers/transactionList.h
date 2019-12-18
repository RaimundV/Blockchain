//
// Created by 123 on 2019-12-16.
//

#ifndef BLOCKCHAINHASHING_TRANSACTIONLIST_H
#define BLOCKCHAINHASHING_TRANSACTIONLIST_H

#include "block.h"
#include "hashing.h"

class TransAction
{
public:
    TransAction();
    TransAction(    std::string _from,
                    std::string _to,
                    std::string _amount,
                    std::string _date,
                    std::string _time);

    bool AddTrans(  std::string _from,
                    std::string _to,
                    std::string _amount,
                    std::string _date,
                    std::string _time);

    std::string returnStrCombo();
    std::string returnId();
private:
    std::string from;
    std::string to;
    std::string amount;
    std::string date;
    std::string time;
    std::string id;
};

std::string TransAction::returnStrCombo() {
    return from + to + amount + date + time;
}

bool TransAction::AddTrans(std::string _from, std::string _to, std::string _amount, std::string _date,
                           std::string _time) {
    if (id == "")
    {
        from = _from;
        to = _to;
        amount = _amount;
        date = _date;
        time = _time;
        id = stringToAsciiDiffCheck(returnStrCombo());
    }
    else
    {
        return id == stringToAsciiDiffCheck(returnStrCombo());
    }

    return true;
}

std::string TransAction::returnId() {
    return id;
}

TransAction::TransAction() {
    from = "";
    to = "";
    amount = "";
    date = "";
    time = "";
    id = "";
}

TransAction::TransAction(std::string _from, std::string _to, std::string _amount, std::string _date,
                         std::string _time) {
    from = _from;
    to = _to;
    amount = _amount;
    date = _date;
    time = _time;
    id = stringToAsciiDiffCheck(returnStrCombo());
}
#endif //BLOCKCHAINHASHING_TRANSACTIONLIST_H
