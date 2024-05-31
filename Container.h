#pragma once
#include <vector>

// Обобщенный контейнерный класс
class Container {
protected:
    std::vector<void*> pointers; // Вектор для хранения указателей на данные
public:
    void add(void* ptr); // добавить элемент
    void remove(int index); //удалить элемент по индексу
    void pop_back(); // удалить последний элемент
    void clear(); // удалить все элементы
    void* get(int index) const; // получить элемент по индексу
    virtual ~Container();
};

