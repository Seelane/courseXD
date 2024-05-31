#pragma once
#include "Printer.h"

namespace CW {

    class InkjetPrinter : public Printer
    {
    public:
        InkjetPrinter() = default;
        InkjetPrinter(const char* model_name, bool printing, int colors);
        InkjetPrinter(const char* model_name, bool printing, int colors, std::string ink);
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� ���������� �� ��������� �� �����
        virtual void print() const;
        // ���������� ����� �������
        void set_colors_number(int needles);
        // ���������� ��� �������
        void set_ink_type(std::string ink);
        // �������� ����� �������
        int get_colors_number() const;
        // �������� ��� �������
        std::string get_ink_type() const;
        void set_all() override;

    private:
        // ���������� ��� � �������
        int colors_number;
        // ������ �����
        std::string ink_type;
    };
}