#pragma once
#include "Connection_Type.h"
#include "iostream"
#include <fstream>
#include <string>

namespace CW
{
    class IPrintingDevice
    {
    public:
        // ��������� ������ ����� ����������
        virtual void set_name(const char* name) = 0;
        // ��������� ������ ���� ����������
        virtual void set_type(Connection_Type connection_type) = 0;
        // ��������� ����� ���� ����������
        virtual void set_price(int value) = 0;
        // �������� ��� ����������
        virtual char* get_name() const = 0;
        // �������� ��� ����������
        virtual std::string get_type() const = 0;
        // �������� ���� ����������
        virtual int get_price() const = 0;
        //������� ���������� � ����������
        virtual void print() const = 0;
        // ��������� �������� ��� ���� ���������� ������
        virtual void set_all() = 0;
        virtual std::ifstream& read_from_file(std::ifstream& read) = 0;
        virtual std::ofstream& write_to_file(std::ofstream& write) = 0;
        virtual bool operator ==(int m) const = 0;
        virtual bool operator<(const IPrintingDevice& obj) const = 0;
        virtual bool operator>(const IPrintingDevice& obj) const = 0;
        friend  std::ostream& operator<<(std::ostream& os, const IPrintingDevice& mic);
    };
}