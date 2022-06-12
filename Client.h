#pragma once
#include "Order.h"

class Balance{
public:
    void add_money(double money){
        if(money < 0){
            throw std::runtime_error("Can't add negative numbers");
        }
        m_money += money;
    }
    bool waste_money(double money){
        if(money < 0){
            throw std::runtime_error("Can't waste negative numbers");
        }
        if (m_money - money < 0) {
            return false;
        }
        m_money -= money;
        return true;
    }
private:
    double m_money = 0;
};

class Client{
public:
    void earn_money(double money) {m_balance.add_money(money);}
    bool pay_and_receive_order(Order& order){
        if (m_balance.waste_money(order.get_cost())){
            order.clear();
            std::cout << "The order is received!" << std::endl;
            return true;
        }
        std::cout << "Not enough money to pay for order!" << std::endl;
        return false;
    };
private:
    Balance m_balance;
};
