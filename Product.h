#pragma once
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>

class ProductInfo{
public:
    explicit ProductInfo(const std::string& info) noexcept: m_info(info){};
    const std::string& get_info() const noexcept {return m_info;}
private:
    std::string m_info;
};

class Product{
public:
    explicit Product(const ProductInfo& productInfo) noexcept: m_product_info(productInfo){};
    virtual std::string get_info() const = 0;
    virtual double get_cost() const noexcept = 0;
protected:
    ProductInfo m_product_info;
};

class WeightProduct: public Product{
public:
    WeightProduct(const ProductInfo& productInfo, double cost): m_cost_per_kg(cost),
                                                        Product(productInfo){};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info();
        ss << ": ";
        ss << m_cost_per_kg;
        ss << " per kg";
        return ss.str();
    }
    double get_cost() const noexcept override{
        return m_cost_per_kg;
    }
private:
    double m_cost_per_kg;
};

class AmountProduct: public Product{
public:
    AmountProduct(const ProductInfo& productInfo, double cost): m_cost_per_one(cost),
                                                           Product(productInfo){};
    std::string get_info() const override {
        std::stringstream ss;
        ss << m_product_info.get_info();
        ss << ": ";
        ss << m_cost_per_one;
        ss << " per one";
        return ss.str();
    }
    double get_cost() const noexcept override{
        return m_cost_per_one;
    }
private:
    double m_cost_per_one;
};
