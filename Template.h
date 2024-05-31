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
            Node* current = other.head; // ��������� �� ������ ����������� ������
            while (current) // ���� �� ��������� ����� ����������� ������
            {
                push_back(current->data); // ���������� ��������� � ����� �������� ������
                current = current->next; // ����������� � ���������� ���� ����������� ������
            }
        }

        ~DynamicVector()
        {
            clear();
        }

        // �����  ��� ������� ������
        void clear()
        {
            while (head) // ���� ������ ������ �� 'nullptr'
            {
                const Node* tmp = head; // ��������� ��������� �� ������ ������
                head = head->next; // ����������� ������ � ���������� ����
                delete tmp; // �������� �������� ����
            }
        }

        // �����  ��� ������ ���� ��������� ������
        void print() const
        {
            Node* tmp = head; // ��������� ��������� �� ������ ������
            if (!tmp) std::cout << "Vector is empty\n"; // ���� ������ ����, ����� ���������
            while (tmp) // ���� �� ��������� ����� ������
            {
                std::cout << tmp->data; // ����� �������� �������� ����

                tmp = tmp->next; // ����������� � ���������� ����
            }
        }

        // ����� ��� ��������� ������� ������
        int get_size() const
        {
            return size; // ������� �������� ������� ������
        }

        // �����  ��� ������ �������� �� ����
        void find_by_price(int price) const
        {
            if (price < 0) throw std::exception("\nException: Price < 0\n"); // ����������, ���� ���� ������ 0
            if (price > pow(2, 16)) throw std::out_of_range("\nException: value out of bounds");
            // ����������, ���� ���� ������� �� ������� ����������� ���������

            Node* tmp = head; // ��������� ��������� �� ������ ������
            while (tmp) // ���� �� ��������� ����� ������
            {
                if (tmp->data && *tmp->data == price) // ���� ������� ������������ ����
                {
                    std::cout << *tmp->data; // ����� ���������� ��������
                }
                tmp = tmp->next; // ����������� � ���������� ����
            }
        }

        // �����  ��� ���������� ������ �� �����������
        void sort_by_price_h()
        {
            for (int i = 0; i < size; i++) // ������ �� ����� ������
            {
                Node* tmp = head; // ��������� ��������� �� ������ ������
                while (tmp && tmp->next) // ���� �� ��������� ������������� ����
                {
                    if ((tmp->data) > (tmp->next->data)) // ���� ������� �������� ������ ����������
                    {
                        std::swap(tmp->data, tmp->next->data); // ������ ������� �������� �����
                    }
                    tmp = tmp->next; // ����������� � ���������� ����
                }
            }
        }
        // �����  ��� ���������� ������ �� �����������
        void sort_by_name_h()
        {
            for (int i = 0; i < size; i++) // ������ �� ����� ������
            {
                Node* tmp = head; // ��������� ��������� �� ������ ������
                while (tmp && tmp->next) // ���� �� ��������� ������������� ����
                {
                    if (tmp->data.get_name() > tmp->next->data.get_name()) // ���� ������� �������� ������ ����������
                    {
                        std::swap(tmp->data, tmp->next->data); // ������ ������� �������� �����
                    }
                    tmp = tmp->next; // ����������� � ���������� ����
                }
            }
        }
        // ����� ��� ���������� ������ �� ��������
        void sort_by_price_l()
        {
            for (int i = 0; i < size; i++) // ������ �� ����� ������
            {
                Node* tmp = head; // ��������� ��������� �� ������ ������
                while (tmp && tmp->next) // ���� �� ��������� ������������� ����
                {
                    if ((*tmp->data) < *tmp->next->data) // ���� ������� �������� ������ ����������
                    {
                        std::swap(tmp->data, tmp->next->data); // ������ ������� �������� �����
                    }
                    tmp = tmp->next; // ����������� � ���������� ����
                }
            }
        }

        // �����  ��� ���������� �������� � ����� ������
        void push_back(T device)
        {
            //if (device == nullptr) throw std::exception("\nException: The nullptr device!");
            // ����������, ���� ����������� ������� - nullptr

            Node* tmp = new Node(); // �������� ������ ����
            tmp->data = device; // ������������ ������ ����
            tmp->next = nullptr; // ��������� ���������� ���� ��� nullptr

            if (head) // ���� ������ �� ����
            {
                Node* current = head; // ��������� ��������� �� ������ ������
                while (current->next) // ���� �� ��������� ��������� ����
                    current = current->next; // ����������� � ���������� ����
                current->next = tmp; // ���������� ������ ���� � ����� ������
            }
            else // ���� ������ ����
            {
                head = tmp; // ����� ���� ���������� ������� ������
            }

            size++; // ���������� ������� ������
        }

        // ����� ��� �������� ���������� �������� �� ������
        void pop_back()
        {
            if (head) // ���� ������ �� ����
            {
                if (head->next) // ���� � ������ ����� ������ ��������
                {
                    Node* current = head; // ��������� ��������� �� ������ ������
                    while (current->next->next) // ���� �� ��������� ������������� ����
                        current = current->next; // ����������� � ���������� ����

                    delete current->next; // �������� ���������� ����
                    current->next = nullptr; // ��������� ��������� �� ��������� ����
                }
                else // ���� � ������ ���� �������
                {
                    delete head; // �������� ������ ������
                    head = nullptr; // ��������� ������ ������
                }
                size--; // ���������� ������� ������
            }
            else // ���� ������ ����
            {
                std::cout << "Vector is empty\n"; // ����� ��������� � ������ ������
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
        // ���������� ��������� [] 
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
            T data; // ������ ����
            Node* next; // ��������� �� ��������� ����
        };

        Node* head;
        int size;
    };
}
