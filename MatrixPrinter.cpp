#include "MatrixPrinter.h"
#include <cstdlib>
namespace CW
{
    MatrixPrinter::MatrixPrinter(const char* model_name, bool printing, int needles)
        : Printer(model_name, printing), needles_in_head(needles), carriage_width(0) {}

    MatrixPrinter::MatrixPrinter(const char* model_name, bool printing, int needles, int width) : MatrixPrinter(model_name, printing, needles)
    {
        set_carriage_width(width);
    }

    std::ifstream& MatrixPrinter::read_from_file(std::ifstream& read)
    {
        int needles;
        read >> needles;
        if (!read) {
            std::cerr << "Error: could not read cutter info\n";
            return read;
        }
        set_needles_in_head(needles);
        int width;
        PrintingDevice::read_from_file(read);
        read >> width;
        if (!read) {
            std::cerr << "Error: could not read paper type\n";
            return read;
        }
        set_carriage_width(width);
        return read;
    }

    std::ofstream& MatrixPrinter::write_to_file(std::ofstream& write)
    {
        PrintingDevice::write_to_file(write);
        write << needles_in_head << '\n' << carriage_width << '\n';
        return write;
    }

    void MatrixPrinter::print() const
    {
        std::cout << "MatrixPrinter:\n";
        print_needed();
        std::cout << "Print Type: " << get_print_type()
            << "\nDuplex Printing (true/false): " << (get_duplex_printing() ? "true" : "false")
            << "\n----------------------\n";
    }


    void MatrixPrinter::set_needles_in_head(int needles)
    {
        needles_in_head = needles;
    }

    void MatrixPrinter::set_carriage_width(int width)
	{
		carriage_width = width;
    }

    int MatrixPrinter::get_carriage_width() const
    {
        return carriage_width;
    }

    int MatrixPrinter::get_needles_in_head() const
    {
        return needles_in_head;
    }

    void MatrixPrinter::set_all()
    {
        PrintingDevice::set_all();
        int needles, width;
        std::cout << "Needles in head: "; std::cin >> needles;
        std::cin.seekg(std::cin.eof());
        std::cout << "Carriage width: "; std::cin >> width;
        std::cin.seekg(std::cin.eof());
        set_needles_in_head(needles);
        set_carriage_width(width);
    }
}
