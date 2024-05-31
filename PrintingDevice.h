#pragma once
#include <string>
#include <iostream>
#include "IPrintingDevice.h"

namespace CW
{
    class PrintingDevice : public IPrintingDevice
    {
    public:
        PrintingDevice();
        PrintingDevice(const char* name);
        PrintingDevice(const char* name, Connection_Type Ctype);
        PrintingDevice(const PrintingDevice& other);
        // PrintingDevice(PrintingDevice&& other) noexcept;
        ~PrintingDevice();
        // получить количество классов
        static void get_count_class();
        //чтение из файла данных и запись в класс
        std::ifstream& read_from_file(std::ifstream& read) override;
        //запись данных класса в файл
        std::ofstream& write_to_file(std::ofstream& write) override;
        // вывод на консоль хар-ки устройства
        void print() const override;
        // установка нового имени устройства
        void set_name(const char* name) override;
        // установка нового типа устройства
        void set_type(Connection_Type connection_type) override;
        // утсановка новой цены устройства
        void set_price(int value) override;
        // получить имя устройства
        char* get_name() const override;
        // получить тип устройства
        std::string get_type() const override;
        // получить цену устройства
        int get_price() const override;
        void set_all() override;
        // Оператор присваивания копированием
        PrintingDevice& operator=(const PrintingDevice& other);
        bool operator ==(int m) const override;
        bool operator<(const IPrintingDevice& obj) const override;
        bool operator>(const IPrintingDevice& obj) const override;
    protected:
        void print_needed() const;
    private:
        //имя устройства
        char* name;
        //тип устройства
        std::string type;
        //цена устройства
        int price;
        // количество классов
        static int count;
        // тип устройства
        Connection_Type connection_type;
    };
}