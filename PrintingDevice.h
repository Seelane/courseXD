#pragma once
#include <string>
#include <iostream>
#include "IPrintingDevice.h"

namespace CW
{
    class PrintingDevice : public IPrintingDevice
    {
    public:
        PrintingDevice();
        PrintingDevice(const char* name);
        PrintingDevice(const char* name, Connection_Type Ctype);
        PrintingDevice(const PrintingDevice& other);
        // PrintingDevice(PrintingDevice&& other) noexcept;
        ~PrintingDevice();
        // �������� ���������� �������
        static void get_count_class();
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� �� ������� ���-�� ����������
        void print() const override;
        // ��������� ������ ����� ����������
        void set_name(const char* name) override;
        // ��������� ������ ���� ����������
        void set_type(Connection_Type connection_type) override;
        // ��������� ����� ���� ����������
        void set_price(int value) override;
        // �������� ��� ����������
        char* get_name() const override;
        // �������� ��� ����������
        std::string get_type() const override;
        // �������� ���� ����������
        int get_price() const override;
        void set_all() override;
        // �������� ������������ ������������
        PrintingDevice& operator=(const PrintingDevice& other);
        bool operator ==(int m) const override;
        bool operator<(const IPrintingDevice& obj) const override;
        bool operator>(const IPrintingDevice& obj) const override;
    protected:
        void print_needed() const;
    private:
        //��� ����������
        char* name;
        //��� ����������
        std::string type;
        //���� ����������
        int price;
        // ���������� �������
        static int count;
        // ��� ����������
        Connection_Type connection_type;
    };
}