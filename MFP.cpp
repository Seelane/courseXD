#include "MFP.h"
#include <cstdlib>
namespace CW
{
    MFP::MFP(const char* model_name, bool scanner)
        : PrintingDevice(model_name), is_scanner(true), is_copier(true) {}

    MFP::MFP(const char* model_name, bool scanner, bool copier) : MFP(model_name, is_scanner)
    {
        set_copier(copier);
    }

    std::ifstream& MFP::read_from_file(std::ifstream& read)
    {
        bool scanner;
        read >> scanner;
        if (!read) {
            std::cerr << "Error: could not read scanner\n";
            return read;
        }
        set_scanner(scanner);
        bool copier;
        read >> copier;
        if (!read) {
            std::cerr << "Error: could not read copier\n";
            return read;
        }
        set_copier(copier);
        return read;
    }

    std::ofstream& MFP::write_to_file(std::ofstream& write)
    {
        PrintingDevice::write_to_file(write);
        write << get_scanner() << '\n' << get_copier() << '\n';
        return write;
    }

    void MFP::print() const
    {
        std::cout << "MFP:\n";
        print_needed();
        std::cout << "Scanner: " << (get_copier() ? "true" : "false")
            << "\nCopier: " << (get_copier() ? "true" : "false")
            << "\n----------------------\n";
    }

    void MFP::set_scanner(bool scanner)
    {
        is_scanner = scanner;
	}

    void MFP::set_copier(bool copier)
    {
        is_copier = copier;
	}

    bool MFP::get_scanner() const
    {
        return is_scanner;
    }

    bool MFP::get_copier() const
    {
        return is_copier;
    }

    void MFP::set_all()
    {
        PrintingDevice::set_all();
        bool is_scanner, is_copier;
        std::cout << "Scanner (true/false): "; std::cin >> is_scanner;
        std::cin.seekg(std::cin.eof());
        std::cout << "Copier (true/false): "; std::cin >> is_copier;
        std::cin.seekg(std::cin.eof());
        set_scanner(is_scanner);
        set_copier(is_copier);
    }
}
