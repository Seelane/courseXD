#pragma once
#include "PrintingDevice.h"

namespace CW {

    class Printer : public PrintingDevice
    {
    public:
        Printer() = default;
        Printer(const char* model_name, bool printing);
        Printer(const char* model_name, bool printing, std::string type);
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод информации об микрофоне на экран
        virtual void print() const;
        // установить длину провода
        void set_duplex_printing(bool value);
        // установить тип разъема
        void set_print_type(const std::string& value);
        // получить длину провода
        bool get_duplex_printing() const;
        // получить тип разъема
        std::string get_print_type() const;
        void set_all() override;

    protected:
        void print_needed_P() const;

    private:
        // наличие автоматического резака
        bool duplex_printing;
        // тип бумаги
        std::string print_type;
    };
}