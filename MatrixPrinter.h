#pragma once
#include "Printer.h"

namespace CW {

    class MatrixPrinter : public Printer
    {
    public:
        MatrixPrinter() = default;
        MatrixPrinter(const char* model_name, bool printing, int needles);
        MatrixPrinter(const char* model_name, bool printing, int needles, int width);
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� ���������� �� ��������� �� �����
        virtual void print() const;
        // ���������� ����� �������
        void set_needles_in_head(int needles);
        // ���������� ��� �������
        void set_carriage_width(int width);
        // �������� ����� �������
        int get_needles_in_head() const;
        // �������� ��� �������
        int get_carriage_width() const;
        void set_all() override;

    private:
        // ���������� ��� � �������
        int needles_in_head;
        // ������ �����
        int carriage_width;
    };
}