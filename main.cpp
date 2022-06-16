#include <iostream>
#include "PriceBase.h"

int main() {
    PriceBase& priceBase = PriceBase::Instance();

    Order order;
    std::cout << std::boolalpha << order.empty() << std::endl;
    order.add_position(std::make_unique<WeightPosition>(priceBase.get_product_weight("Apple"), 0.5));
    order.add_position(std::make_unique<AmountPosition>(priceBase.get_product_amount("Pencil"), 2));

    order.get_info();

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(
            priceBase.get_product_weight("Apple"), 1.5)));

    order.get_info();

    Client Ivan;
    Ivan.pay_and_receive_order(order);

    Ivan.earn_money(500);
    Ivan.pay_and_receive_order(order);
    return 0;
}
