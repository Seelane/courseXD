#pragma once
#include <vector>

// ���������� ������������ �����
class Container {
protected:
    std::vector<void*> pointers; // ������ ��� �������� ���������� �� ������
public:
    void add(void* ptr); // �������� �������
    void remove(int index); //������� ������� �� �������
    void pop_back(); // ������� ��������� �������
    void clear(); // ������� ��� ��������
    void* get(int index) const; // �������� ������� �� �������
    virtual ~Container();
};

