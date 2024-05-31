#include "Plotter.h"
#include <cstdlib>
namespace CW
{
    Plotter::Plotter(const char* model_name, bool cutter)
        : PrintingDevice(model_name), automatic_cutter(true), paper_type("A3") {}

    Plotter::Plotter(const char* model_name, bool cutter, const char* type) : Plotter(model_name, cutter)
    {
        set_paper_type(type);
    }

    std::ifstream& Plotter::read_from_file(std::ifstream& read)
    {
        std::string data;
        PrintingDevice::read_from_file(read);
        std::getline(read, data);
        std::getline(read, data);
        if (!read) {
            std::cerr << "Error: could not read paper type\n";
            return read;
        }
        set_paper_type(data);
        bool cutter = true;
        read >> cutter;
        if (!read) {
            std::cerr << "Error: could not read cutter info\n";
            return read;
        }
        set_cutter(cutter);
        return read;
    }

    std::ofstream& Plotter::write_to_file(std::ofstream& write)
    {
        PrintingDevice::write_to_file(write);
        write << paper_type << '\n' << get_cutter() << '\n';
        return write;
    }

    void Plotter::print() const
    {
        std::cout << "Plotter:\n";
        print_needed();
        std::cout << "Paper Type: " << get_paper_type()
            << "\nAutomatic Cutter: " << (get_cutter() ? "true" : "false")
            << "\n----------------------\n";
    }


    void Plotter::set_cutter(bool cutter)
    {
        automatic_cutter = cutter;
    }

    void Plotter::set_paper_type(const std::string& value)
    {
        paper_type = value;

    }

    bool Plotter::get_cutter() const
    {
        return automatic_cutter;
    }

    std::string Plotter::get_paper_type() const
    {
        return paper_type;
    }

    void Plotter::set_all()
    {
        PrintingDevice::set_all();
        std::string paper_type; bool cutter;
        std::cout << "Automatic cutter (true/false): "; std::cin >> cutter;
        std::cin.seekg(std::cin.eof());
        std::cout << "Paper type: ";
        std::getline(std::cin, paper_type);
        set_cutter(cutter);
        set_paper_type(paper_type);
    }
}
