#include "Container.h"

void Container::add(void* ptr)
{
    pointers.push_back(ptr);
}

void Container::remove(int index)
{
    if (index >= 0 && index < pointers.size())
        pointers.erase(pointers.begin() + index); // Удаляем указатель из вектора
}

void Container::pop_back()
{
    pointers.pop_back();
}

void Container::clear()
{
    for (auto& ptr : pointers)
    {
        delete ptr;
        ptr = nullptr;
    }
    pointers.clear();
}

void* Container::get(int index) const
{
    if (index >= 0 && index < pointers.size())
    {
        return pointers[index];
    }
    return nullptr;
}

Container::~Container()
{
    clear();
}
