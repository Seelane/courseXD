#pragma once
#include <iostream>

namespace CW
{
    template <typename T>
    class DynamicVector
    {
    public:
        DynamicVector()
        {
            head = nullptr;
            size = 0;
        }

        DynamicVector(const DynamicVector& other)
        {
            head = nullptr;
            size = 0;
            Node* current = other.head; // Указатель на голову копируемого списка
            while (current) // Пока не достигнут конец копируемого списка
            {
                push_back(current->data); // Добавление элементов в конец текущего списка
                current = current->next; // Перемещение к следующему узлу копируемого списка
            }
        }

        ~DynamicVector()
        {
            clear();
        }

        // Метод  для очистки списка
        void clear()
        {
            while (head) // Пока голова списка не 'nullptr'
            {
                const Node* tmp = head; // Временный указатель на голову списка
                head = head->next; // Перемещение головы к следующему узлу
                delete tmp; // Удаление текущего узла
            }
        }

        // Метод  для вывода всех элементов списка
        void print() const
        {
            Node* tmp = head; // Временный указатель на голову списка
            if (!tmp) std::cout << "Vector is empty\n"; // Если список пуст, вывод сообщения
            while (tmp) // Пока не достигнут конец списка
            {
                std::cout << tmp->data; // Вывод значения текущего узла

                tmp = tmp->next; // Перемещение к следующему узлу
            }
        }

        // Метод для получения размера списка
        int get_size() const
        {
            return size; // Возврат текущего размера списка
        }

        // Метод  для поиска элемента по цене
        void find_by_price(int price) const
        {
            if (price < 0) throw std::exception("\nException: Price < 0\n"); // Исключение, если цена меньше 0
            if (price > pow(2, 16)) throw std::out_of_range("\nException: value out of bounds");
            // Исключение, если цена выходит за пределы допустимого диапазона

            Node* tmp = head; // Временный указатель на голову списка
            while (tmp) // Пока не достигнут конец списка
            {
                if (tmp->data && *tmp->data == price) // Если найдено соответствие цены
                {
                    std::cout << *tmp->data; // Вывод найденного значения
                }
                tmp = tmp->next; // Перемещение к следующему узлу
            }
        }

        // Метод  для сортировки списка по возрастанию
        void sort_by_price_h()
        {
            for (int i = 0; i < size; i++) // Проход по всему списку
            {
                Node* tmp = head; // Временный указатель на голову списка
                while (tmp && tmp->next) // Пока не достигнут предпоследний узел
                {
                    if ((tmp->data) > (tmp->next->data)) // Если текущее значение больше следующего
                    {
                        std::swap(tmp->data, tmp->next->data); // Меняем местами значения узлов
                    }
                    tmp = tmp->next; // Перемещение к следующему узлу
                }
            }
        }
        // Метод  для сортировки списка по возрастанию
        void sort_by_name_h()
        {
            for (int i = 0; i < size; i++) // Проход по всему списку
            {
                Node* tmp = head; // Временный указатель на голову списка
                while (tmp && tmp->next) // Пока не достигнут предпоследний узел
                {
                    if (tmp->data.get_name() > tmp->next->data.get_name()) // Если текущее значение больше следующего
                    {
                        std::swap(tmp->data, tmp->next->data); // Меняем местами значения узлов
                    }
                    tmp = tmp->next; // Перемещение к следующему узлу
                }
            }
        }
        // Метод для сортировки списка по убыванию
        void sort_by_price_l()
        {
            for (int i = 0; i < size; i++) // Проход по всему списку
            {
                Node* tmp = head; // Временный указатель на голову списка
                while (tmp && tmp->next) // Пока не достигнут предпоследний узел
                {
                    if ((*tmp->data) < *tmp->next->data) // Если текущее значение меньше следующего
                    {
                        std::swap(tmp->data, tmp->next->data); // Меняем местами значения узлов
                    }
                    tmp = tmp->next; // Перемещение к следующему узлу
                }
            }
        }

        // Метод  для добавления элемента в конец списка
        void push_back(T device)
        {
            //if (device == nullptr) throw std::exception("\nException: The nullptr device!");
            // Исключение, если добавляемый элемент - nullptr

            Node* tmp = new Node(); // Создание нового узла
            tmp->data = device; // Присваивание данных узлу
            tmp->next = nullptr; // Установка следующего узла как nullptr

            if (head) // Если список не пуст
            {
                Node* current = head; // Временный указатель на голову списка
                while (current->next) // Пока не достигнут последний узел
                    current = current->next; // Перемещение к следующему узлу
                current->next = tmp; // Добавление нового узла в конец списка
            }
            else // Если список пуст
            {
                head = tmp; // Новый узел становится головой списка
            }

            size++; // Увеличение размера списка
        }

        // Метод для удаления последнего элемента из списка
        void pop_back()
        {
            if (head) // Если список не пуст
            {
                if (head->next) // Если в списке более одного элемента
                {
                    Node* current = head; // Временный указатель на голову списка
                    while (current->next->next) // Пока не достигнут предпоследний узел
                        current = current->next; // Перемещение к следующему узлу

                    delete current->next; // Удаление последнего узла
                    current->next = nullptr; // Обнуление указателя на следующий узел
                }
                else // Если в списке один элемент
                {
                    delete head; // Удаление головы списка
                    head = nullptr; // Обнуление головы списка
                }
                size--; // Уменьшение размера списка
            }
            else // Если список пуст
            {
                std::cout << "Vector is empty\n"; // Вывод сообщения о пустом списке
            }
        }
        void load(const std::string& path)
        {
            std::ifstream read(path, std::ios::in);
            if (!read.is_open()) {
                std::cerr << "Error: could not open file " << path << '\n';
                return;
            }
            T obj_to_load;
            int size1;
            read >> size1;
            if (!read) {
                std::cerr << "Error: could not read size from file\n";
                return;
            }
            for (int i = 0; i < size1; i++)
            {
                obj_to_load.read_from_file(read);
                if (!read) {
                    std::cerr << "Error: could not read object " << i << " from file " << path << '\n';
                    return;
                }
                push_back(obj_to_load);
            }
            read.close();
            std::cout << "Success load in container type " << typeid(T).name() << '\n';
        }
        void save(const std::string& path)
        {
            if (get_size() == 0)
            {
                std::cout << "Nothing to save to a file from a container type " << typeid(T).name() << '\n'; return;
            }
            std::ofstream write(path, std::ios::out | std::ios::trunc);
            if (!write.is_open()) return;
            Node* tmp = head;
            T obj_to_save;
            write << get_size() << '\n';
            while (tmp)
            {
                obj_to_save = tmp->data;
                obj_to_save.write_to_file(write);
                tmp = tmp->next;
            }
            write.close();
            std::cout << "Success save to a file from a container type " << typeid(T).name() << '\n';
        }
        // Перегрузка оператора [] 
        T& operator[](const int index)
        {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of bounds");

            Node* tmp = head;
            for (int i = 0; i < index; ++i)
            {
                tmp = tmp->next;
            }

            return tmp->data;
        }

    private:
        struct Node
        {
            T data; // Данные узла
            Node* next; // Указатель на следующий узел
        };

        Node* head;
        int size;
    };
}
