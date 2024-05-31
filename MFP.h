#pragma once
#include "PrintingDevice.h"

namespace CW {

    class MFP : public PrintingDevice
    {
    public:
        MFP() = default;
        MFP(const char* model_name, bool scanner);
        MFP(const char* model_name, bool scanner, bool copier);
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод информации об микрофоне на экран
        virtual void print() const override;
        // установить длину провода
        void set_scanner(bool scanner);
        // установить тип разъема
        void set_copier(bool copier);
        // получить длину провода
        bool get_scanner() const;
        // получить тип разъема
        bool get_copier() const;
        void set_all() override;

    private:
        // наличие автоматического резака
        bool is_scanner;
        // тип бумаги
        bool is_copier;
    };
}