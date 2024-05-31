#include "Printer.h"
#include <cstdlib>
namespace CW
{
    Printer::Printer(const char* model_name, bool printing)
        : PrintingDevice(model_name), duplex_printing(printing), print_type("Monochrome") {}

    Printer::Printer(const char* model_name, bool printing, std::string type) : Printer(model_name, printing)
    {
        set_print_type(type);
    }

    std::ifstream& Printer::read_from_file(std::ifstream& read)
    {bool printing = true;
        read >> printing;
        if (!read) {
            std::cerr << "Error: could not read cutter info\n";
            return read;
        }
        set_duplex_printing(printing);
        std::string data;
        PrintingDevice::read_from_file(read);
        std::getline(read, data);
        std::getline(read, data);
        if (!read) {
            std::cerr << "Error: could not read paper type\n";
            return read;
        }
        set_print_type(data);
        return read;
    }

    std::ofstream& Printer::write_to_file(std::ofstream& write)
    {
        PrintingDevice::write_to_file(write);
        write << print_type << '\n' << get_duplex_printing() << '\n';
        return write;
    }

    void Printer::print() const
    {
        std::cout << "Printer:\n";
        print_needed();
        std::cout << "Print Type: " << get_print_type()
            << "\nDuplex Printing (true/false): " << (get_duplex_printing() ? "true" : "false")
            << "\n----------------------\n";
    }

    void Printer::print_needed_P() const
    {
        std::cout << "    Printer:\n    ";
        print_needed();
        std::cout << "Print Type: " << get_print_type()
            << "\nDuplex Printing (true/false): " << (get_duplex_printing() ? "true" : "false")
            << "\n";
    }


    void Printer::set_duplex_printing(bool printing)
    {
        duplex_printing = printing;
    }

    void Printer::set_print_type(const std::string& type)
    {
        print_type = type;
    }

    bool Printer::get_duplex_printing() const
    {
        return duplex_printing;
    }

    std::string Printer::get_print_type() const
    {
        return print_type;
    }

    void Printer::set_all() 
    {
        PrintingDevice::set_all();
        std::string print_type; bool duplex_printing;
        std::cout << "Automatic cutter (true/false): "; std::cin >> duplex_printing;
        std::cin.seekg(std::cin.eof());
        std::cout << "Paper type: ";
        std::getline(std::cin, print_type);
        set_duplex_printing(duplex_printing);
		set_print_type(print_type);
    }
}
