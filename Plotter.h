#pragma once
#include "PrintingDevice.h"

namespace CW {

    class Plotter : public PrintingDevice
    {
    public:
        Plotter() = default;
        Plotter(const char* model_name, bool cutter);
        Plotter(const char* model_name, bool cutter, const char* type);
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� ���������� �� ��������� �� �����
        virtual void print() const override;
        // ���������� ����� �������
        void set_cutter(bool value);
        // ���������� ��� �������
        void set_paper_type(const std::string& value);
        // �������� ����� �������
        bool get_cutter() const;
        // �������� ��� �������
        std::string get_paper_type() const;
        void set_all() override;

    private:
        // ������� ��������������� ������
        bool automatic_cutter;
        // ��� ������
        std::string paper_type;
    };
}