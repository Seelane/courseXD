#pragma once
#include "PrintingDevice.h"

namespace CW {

    class Printer : public PrintingDevice
    {
    public:
        Printer() = default;
        Printer(const char* model_name, bool printing);
        Printer(const char* model_name, bool printing, std::string type);
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� ���������� �� ��������� �� �����
        virtual void print() const;
        // ���������� ����� �������
        void set_duplex_printing(bool value);
        // ���������� ��� �������
        void set_print_type(const std::string& value);
        // �������� ����� �������
        bool get_duplex_printing() const;
        // �������� ��� �������
        std::string get_print_type() const;
        void set_all() override;

    protected:
        void print_needed_P() const;

    private:
        // ������� ��������������� ������
        bool duplex_printing;
        // ��� ������
        std::string print_type;
    };
}