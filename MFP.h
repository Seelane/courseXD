#pragma once
#include "PrintingDevice.h"

namespace CW {

    class MFP : public PrintingDevice
    {
    public:
        MFP() = default;
        MFP(const char* model_name, bool scanner);
        MFP(const char* model_name, bool scanner, bool copier);
        //������ �� ����� ������ � ������ � �����
        std::ifstream& read_from_file(std::ifstream& read) override;
        //������ ������ ������ � ����
        std::ofstream& write_to_file(std::ofstream& write) override;
        // ����� ���������� �� ��������� �� �����
        virtual void print() const override;
        // ���������� ����� �������
        void set_scanner(bool scanner);
        // ���������� ��� �������
        void set_copier(bool copier);
        // �������� ����� �������
        bool get_scanner() const;
        // �������� ��� �������
        bool get_copier() const;
        void set_all() override;

    private:
        // ������� ��������������� ������
        bool is_scanner;
        // ��� ������
        bool is_copier;
    };
}