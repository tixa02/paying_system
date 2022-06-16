#include <iostream>
#include "PriceBase.h"

int main() {
    PriceBase& priceBase = PriceBase::Instance();

    Order order;
    std::cout << std::boolalpha << order.empty() << std::endl;
    order.add_position(std::make_unique<WeightPosition>(WeightPosition(
            priceBase.get_product_weight("Apple"), 0.5)));
    order.add_position(std::make_unique<AmountPosition>(AmountPosition(
            priceBase.get_product_amount("Pencil"), 2)));

    order.get_info();

    order.add_position(std::make_unique<WeightPosition>(WeightPosition(
            priceBase.get_product_weight("Apple"), 1.5)));

    order.get_info();

    Client Ivan;
    Ivan.pay_and_receive_order(order);

    Ivan.earn_money(500);
    Ivan.pay_and_receive_order(order);




/*    ProductInfo p1("greeen patatoes");
    AmountProduct g_patatoes(p1, 57);
    std::cout << g_patatoes.get_info() << std::endl;
    AmountPosition pos1(g_patatoes, 10);
    std::cout << pos1.get_cost() << std::endl;

    ProductInfo p2("blue patatoes");
    AmountProduct b_patatoes(p2, 5);
    std::cout << b_patatoes.get_info() << std::endl;
    AmountPosition pos2(b_patatoes, 3);
    std::cout << pos2.get_cost() << std::endl;

    ProductInfo p3("blue apples");
    AmountProduct b_apples(p3, 10);
    std::cout << b_apples.get_info() << std::endl;
    AmountPosition pos3(b_apples, 4);
    std::cout << pos3.get_cost() << std::endl;

    Order order;
    std::cout << std::boolalpha << order.empty() << std::endl;
    order.add_position(std::make_unique<AmountPosition>(pos1));

    order.get_info();
    std::cout << order.get_cost() << std::endl;
    std::cout << std::boolalpha << order.empty() << std::endl;

    Client client;
    client.earn_money(3);
    client.pay_and_receive_order(order);
    std::cout << std::boolalpha << order.empty() << std::endl;

    client.earn_money(3000);
    client.pay_and_receive_order(order);
    order.get_info();
    std::cout << std::boolalpha << order.empty() << std::endl;
*/
    return 0;
}
