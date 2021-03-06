#pragma once
#include "Product.h"

class Position{
public:
    Position(Product&& product) = delete;
    explicit Position(const Product& product) noexcept: m_ptr_product(&product){};
    const Product* get_ptr_product() const noexcept {return m_ptr_product;}
    virtual double get_cost() const noexcept = 0;
    virtual double get_quantity() const noexcept = 0;
protected:
    const Product* m_ptr_product;
};

class AmountPosition: public Position{
public:
    AmountPosition(AmountProduct&& product, size_t amount) = delete;
    AmountPosition(const AmountProduct& product, size_t amount): Position(product), m_amount(amount) {};
    double get_cost() const noexcept override {return m_amount * m_ptr_product->get_cost();}
    double get_quantity() const noexcept override {return m_amount;}
private:
    size_t m_amount;
};

class WeightPosition: public Position{
public:
    WeightPosition(AmountProduct&& product, double amount) = delete;
    WeightPosition(const WeightProduct& product, double weight): Position(product), m_weight(weight){};
    double get_cost() const noexcept override {return m_weight * m_ptr_product->get_cost();}
    double get_quantity() const noexcept override {return m_weight;}
private:
    double m_weight;
};

