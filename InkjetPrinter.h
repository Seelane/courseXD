#pragma once
#include "Printer.h"

namespace CW {

    class InkjetPrinter : public Printer
    {
    public:
        InkjetPrinter() = default;
        InkjetPrinter(const char* model_name, bool printing, int colors);
        InkjetPrinter(const char* model_name, bool printing, int colors, std::string ink);
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод информации об микрофоне на экран
        virtual void print() const;
        // установить длину провода
        void set_colors_number(int needles);
        // установить тип разъема
        void set_ink_type(std::string ink);
        // получить длину провода
        int get_colors_number() const;
        // получить тип разъема
        std::string get_ink_type() const;
        void set_all() override;

    private:
        // количество игл в головке
        int colors_number;
        // ширина лотка
        std::string ink_type;
    };
}