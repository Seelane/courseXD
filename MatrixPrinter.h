#pragma once
#include "Printer.h"

namespace CW {

    class MatrixPrinter : public Printer
    {
    public:
        MatrixPrinter() = default;
        MatrixPrinter(const char* model_name, bool printing, int needles);
        MatrixPrinter(const char* model_name, bool printing, int needles, int width);
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод информации об микрофоне на экран
        virtual void print() const;
        // установить длину провода
        void set_needles_in_head(int needles);
        // установить тип разъема
        void set_carriage_width(int width);
        // получить длину провода
        int get_needles_in_head() const;
        // получить тип разъема
        int get_carriage_width() const;
        void set_all() override;

    private:
        // количество игл в головке
        int needles_in_head;
        // ширина лотка
        int carriage_width;
    };
}