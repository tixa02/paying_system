#pragma once
#include "Position.h"

class Client;

class Order{
public:
    friend Client;
    void add_position(std::unique_ptr<Position>&& ptr_pos){
        int i = 0;
        for(auto& ptr_position: m_ptr_positions){
            if(ptr_position->get_ptr_product()->get_info() == ptr_pos->get_ptr_product()->get_info()){
                m_ptr_positions.at(i) = std::move(ptr_pos);
                return;
            }
            ++i;
        }
        m_ptr_positions.push_back(std::move(ptr_pos));
    }
    double get_cost() const noexcept{
        double sum = 0;
        for(auto& ptr_position: m_ptr_positions){
            sum += ptr_position->get_cost();
        }
        return sum;
    }
    void get_info() const{
        for(auto& ptr_position: m_ptr_positions){
            std::cout << ptr_position->get_ptr_product()->get_info()
                      << "\n\tQuantity: " << ptr_position->get_quantity()
                      << "\n\tCost: " <<ptr_position->get_cost() << std::endl;
        }
    }
    bool empty() const noexcept {return m_ptr_positions.empty();}
private:
    std::vector<std::unique_ptr<Position>> m_ptr_positions;
    void clear(){
        m_ptr_positions.clear();
    }
};
