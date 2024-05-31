#pragma once
#include "PrintingDevice.h"

namespace CW {

    class Plotter : public PrintingDevice
    {
    public:
        Plotter() = default;
        Plotter(const char* model_name, bool cutter);
        Plotter(const char* model_name, bool cutter, const char* type);
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод информации об микрофоне на экран
        virtual void print() const override;
        // установить длину провода
        void set_cutter(bool value);
        // установить тип разъема
        void set_paper_type(const std::string& value);
        // получить длину провода
        bool get_cutter() const;
        // получить тип разъема
        std::string get_paper_type() const;
        void set_all() override;

    private:
        // наличие автоматического резака
        bool automatic_cutter;
        // тип бумаги
        std::string paper_type;
    };
}