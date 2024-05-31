// Device.cpp
#include <iostream>
#include "PrintingDevice.h"

namespace CW {
    PrintingDevice::PrintingDevice()
    {
        count++;
        PrintingDevice::set_name("unknown");
    }

    PrintingDevice::PrintingDevice(const char* name) : PrintingDevice()
    {
        PrintingDevice::set_name(name);
        this->type = "unknown";
        this->price = rand() % 1000;
    }
    PrintingDevice::PrintingDevice(const char* name, Connection_Type connection_type) : PrintingDevice(name)
    {
        connection_type = connection_type;
        PrintingDevice::set_type(connection_type);
    }
    PrintingDevice::PrintingDevice(const PrintingDevice& other) : name(nullptr), type(other.get_type()), price(other.get_price())
    {
        PrintingDevice::set_name(other.name);

        count++;
    }
    PrintingDevice::~PrintingDevice()
    {
        count--;
        delete[] name;
    }
    void PrintingDevice::get_count_class()
    {
        std::cout << "Amount of class objects: " << count << '\n';
    }

    std::ifstream& PrintingDevice::read_from_file(std::ifstream& read)
    {
        std::string data;
        int value = 0;
        std::getline(read, data);
        std::getline(read, data);
        if (!read) {
            std::cerr << "Error: could not read name\n";
            return read;
        }
        set_name(data.c_str());

        std::getline(read, data);
        if (!read) {
            std::cerr << "Error: could not read type\n";
            return read;
        }
        type = data;
        read >> value;
        if (!read) {
            std::cerr << "Error: could not read price\n";
            return read;
        }
        set_price(value);
        return read;
    }

    std::ofstream& PrintingDevice::write_to_file(std::ofstream& write)
    {
        write << get_name() << '\n' << get_type() << '\n' << get_price() << '\n';
        return write;
    }
    int PrintingDevice::count = 0;

    void PrintingDevice::print() const
    {
        std::cout << "PrintingDevice \n"
            << "----------------------\n"
            << "Name: " << get_name()
            << "\nType: " << get_type()
            << "\nPrice: " << get_price()
            << "\n----------------------\n";
    }

    void PrintingDevice::print_needed() const
    {
        std::cout
            << "Name: " << get_name()
            << "\nType: " << get_type()
            << "\nPrice: " << get_price() << '\n';
    }

    void PrintingDevice::set_name(const char* tmp_name)
    {
        delete[] name;

        name = new char[strlen(tmp_name) + 1];
        strcpy_s(name, strlen(tmp_name) + 1, tmp_name);
    }

    void PrintingDevice::set_type(Connection_Type connection_type)
    {
        switch (connection_type)
        {
        case Connection_Type::USB:
            type = "USB";
            break;
        case Connection_Type::Bluetooth:
            type = "Bluetooth";
            break;
        case Connection_Type::Wi_Fi:
            type = "Wi-Fi";
            break;
        case Connection_Type::Unknown:
            type = "Unknown";
            break;
        }
    }

    void PrintingDevice::set_price(int value)
    {

        if (value < 0) throw std::exception("\nException: Price < 0\n");
        if (value > std::pow(2, 16)) throw std::out_of_range("\nException: value out of bounds");
        price = value;
    }

    char* PrintingDevice::get_name() const
    {
        return name;
    }

    std::string PrintingDevice::get_type() const
    {
        return type;
    }

    int PrintingDevice::get_price() const
    {
        return price;
    }

    void PrintingDevice::set_all()
    {
        std::string dname; int dprice = 0, dtype = 0;
        std::cout << "Name: "; std::cin >> dname;
        std::cout << "Type (0 - Bluetooth, 1 - Wi-Fi, 2 - USB): "; std::cin >> dtype;
        std::cout << "Price: "; std::cin >> dprice;
        set_name(dname.c_str());
        set_type(Connection_Type(dtype));
        set_price(dprice);
    }
    // Оператор присваивания копированием
    PrintingDevice& PrintingDevice::operator=(const PrintingDevice& other)
    {
        if (this != &other) {
            set_name(other.name);
            connection_type = other.connection_type;
            price = other.price;
        }
        return *this;
    }

    bool PrintingDevice::operator==(int m) const
    {
        return get_price() == m;
    }

    bool PrintingDevice::operator<(const IPrintingDevice& obj) const
    {
        return get_price() < obj.get_price();
    }

    bool PrintingDevice::operator>(const IPrintingDevice& obj) const
    {
        return get_price() > obj.get_price();
    }
    std::ostream& operator<<(std::ostream& os, const IPrintingDevice& mic)
    {
        std::string tmp = typeid(mic).name();
        tmp.erase(0, 12);
        os << tmp
            << "\n----------------------\n"
            << "Name: " << mic.get_name()
            << "\nType: " << mic.get_type()
            << "\nPrice: " << mic.get_price()
            << "\n----------------------\n";
        return os;
    }
}