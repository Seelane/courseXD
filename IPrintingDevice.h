#pragma once
#include "Connection_Type.h"
#include "iostream"
#include <fstream>
#include <string>

namespace CW
{
    class IPrintingDevice
    {
    public:
        // установка нового имени устройства
        virtual void set_name(const char* name) = 0;
        // установка нового типа устройства
        virtual void set_type(Connection_Type connection_type) = 0;
        // утсановка новой цены устройства
        virtual void set_price(int value) = 0;
        // получить имя устройства
        virtual char* get_name() const = 0;
        // получить тип устройства
        virtual std::string get_type() const = 0;
        // получить цену устройства
        virtual int get_price() const = 0;
        //вывести информацию о устройстве
        virtual void print() const = 0;
        // установка значений для всех переменных класса
        virtual void set_all() = 0;
        virtual std::ifstream& read_from_file(std::ifstream& read) = 0;
        virtual std::ofstream& write_to_file(std::ofstream& write) = 0;
        virtual bool operator ==(int m) const = 0;
        virtual bool operator<(const IPrintingDevice& obj) const = 0;
        virtual bool operator>(const IPrintingDevice& obj) const = 0;
        friend  std::ostream& operator<<(std::ostream& os, const IPrintingDevice& mic);
    };
}