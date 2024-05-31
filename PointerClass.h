#pragma once
#include <stdexcept>
#include <thread>

#include "Container.h"

// Производный класс-шаблон
template <typename T>
class PtrClassTemplate : private Container
{
public:
    void add(T* ptr)
    {
        Container::add(ptr);
    }

    T* get(int index)
    {
        return (T*)Container::get(index);
    }

    void remove(int index)
    {
        Container::remove(index);
    }

    void pop_back()
    {
        Container::pop_back();
    }

    void display_all() const
    {
        for (void* p : pointers)
        {
            T* ptr = (T*)p;
            if (ptr != nullptr)
            {
                ptr->print();
            }
        }
    }

    void sort_by_price()
    {
        for (int i = 0; i < pointers.size() - 1; i++)
        {
            T* first = (T*)pointers[i];
            T* second = (T*)pointers[i + 1];
            if (first != nullptr && second != nullptr)
                if (first->get_price() > second->get_price())
                    std::swap(pointers[i], pointers[i + 1]);
        }
    }
    void sort_by_name()
    {
        for (int i = 0; i < pointers.size() - 1; i++)
        {
            T* first = (T*)pointers[i];
            T* second = (T*)pointers[i + 1];
            if (first != nullptr && second != nullptr)
                if (first->get_name() > second->get_name())
                    std::swap(pointers[i], pointers[i + 1]);
        }
    }
    void find_by_price(int price) const
    {
        if (price < 0) throw std::exception("\nException: Price < 0\n");
        if (price > pow(2, 16)) throw std::out_of_range("\nException: value out of bounds");

        for (void* p : pointers)
        {
            T* ptr = (T*)p;
            if (ptr != nullptr)
                if (ptr->getPrice() == price)
                    ptr->currentMic();
        }
    }

    void clear()
    {
        Container::clear();
    }
};
