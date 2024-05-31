#include "InkjetPrinter.h"
#include <cstdlib>
namespace CW
{
    InkjetPrinter::InkjetPrinter(const char* model_name, bool printing, int colors)
        : Printer(model_name, printing), colors_number(colors), ink_type(" ") {}

    InkjetPrinter::InkjetPrinter(const char* model_name, bool printing, int colors, std::string type) : InkjetPrinter(model_name, printing, colors)
    {
        set_ink_type(type);
    }

    std::ifstream& InkjetPrinter::read_from_file(std::ifstream& read)
    {
        int colors;
        read >> colors;
        if (!read) {
            std::cerr << "Error: could not read cutter info\n";
            return read;
        }
        set_colors_number(colors);
        std::string type;
        PrintingDevice::read_from_file(read);
        read >> type;
        if (!read) {
            std::cerr << "Error: could not read paper type\n";
            return read;
        }
       set_ink_type(type);
        return read;
    }

    std::ofstream& InkjetPrinter::write_to_file(std::ofstream& write)
    {
        PrintingDevice::write_to_file(write);
        write << colors_number << '\n' << ink_type << '\n';
        return write;
    }

    void InkjetPrinter::print() const
    {
        std::cout << "InkjetPrinter:\n";
        print_needed();
        std::cout << "Print Type: " << get_print_type()
            << "\nDuplex Printing (true/false): " << (get_duplex_printing() ? "true" : "false")
            << "\n----------------------\n";
    }


    void InkjetPrinter::set_colors_number(int colors)
    {
        colors_number = colors;
    }

    void InkjetPrinter::set_ink_type(std::string type) {
		ink_type = type;
    }

    int InkjetPrinter::get_colors_number() const
	{
		return colors_number;
    }

    std::string InkjetPrinter::get_ink_type() const
    {
        return ink_type;
    }

    void InkjetPrinter::set_all()
    {
        PrintingDevice::set_all();
        int colors; std::string type;
        std::cout << "Needles in head: "; std::cin >> colors;
        std::cin.seekg(std::cin.eof());
        std::cout << "Carriage width: "; std::cin >> type;
        std::cin.seekg(std::cin.eof());
        set_colors_number(colors);
        set_ink_type(type);
    }
}
