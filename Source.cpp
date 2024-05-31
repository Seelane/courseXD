#include <iostream>
#include <Windows.h>
#include "MFP.h"
#include "Container.h"
#include "MatrixPrinter.h"
#include "InkjetPrinter.h"
#include "Plotter.h"
#include "Connection_Type.h"
#include "Template.h"
#include "PointerClass.h"
using namespace std;
using namespace CW;

template <typename T1, typename T2>
void Message(T1 message1, T2 message2)
{
    cout << message1 << message2 << endl;
}
void SetColor(WORD text, WORD background) {
    const HANDLE h_console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h_console_handle, text | background);
}
void section_create() {
    SetColor(FOREGROUND_BLUE, NULL);
    Message("Section ", "\"Create\"");
    SetColor(15, NULL);
    Message("Print \"create 0\"", " to create Printing Device");
    Message("Print \"create 1\"", " to create MFP");
    Message("Print \"create 2\"", " to create Plotter");
    Message("Print \"create 3\"", " to create Printer");
    Message("Print \"create 4\"", " to create Matrix Printer");
    Message("Print \"create 5\"", " to create Inkjet Printer");
}
void section_print() {
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Print\"");
    SetColor(15, NULL);
    Message("Print \"print 0\"", " to print all Printing Devices");
    Message("Print \"print 1\"", " to print all MFP devices");
    Message("Print \"print 2\"", " to print all Plotters");
    Message("Print \"print 3\"", " to print all Printers");
    Message("Print \"print 4\"", " to print all Matrix Printers");
    Message("Print \"print 5\"", " to print all Inkjet Printers");
    Message("Print \"print ptr\"", " to print all mic");
}
void section_clear() {
    SetColor(FOREGROUND_RED, NULL);
    Message("Section ", "\"Clear\"");
    SetColor(15, NULL);
    Message("Print \"clear all\"", " to clear all devices in all classes");
}
void section_load() {
    SetColor(14, NULL);
    Message("Section ", "\"Load\"");
    SetColor(15, NULL);
    Message("Print \"load all\"", " to load information about each class container to a file");
}
void section_save() {
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Save\"");
    SetColor(15, NULL);
    Message("Print \"save all\"", " to save information about each class container to a file");
}
void section_stop() {
    SetColor(4, NULL);
    Message("Print ", "\"stop\" to close program");
    SetColor(15, NULL);
}
void section_sort() {
    SetColor(6, NULL);
    Message("Section ", "\"Sort\"");
    SetColor(15, NULL);
    Message("Print \"sort by name ptr\"", " to sort all mic in pointer container");
    Message("Print \"sort by price ptr\"", " to sort all mic in pointer container");
    Message("Print \"sort by name\"", " to sort all mic in all container");
    Message("Print \"sort by price\"", " to sort all mic in all container");
}
void info() {
    //create
    Message("Print", "");
    section_create();
    //print
    section_print();
    //clear
    section_clear();
    //load
    section_load();
    //save
    section_save();
    //stop
    section_stop();
    //sort
    section_sort();
}

template <typename PrintingDevice>
void create_printing_device(DynamicVector<PrintingDevice>& container, PtrClassTemplate<IPrintingDevice>& ptr_container) {
    PrintingDevice printing_device;
    printing_device.set_all();
    container.push_back(printing_device);
    ptr_container.add(&container[container.get_size() - 1]);
}

template <typename PrintingDevice>
void create_printing_device(DynamicVector<PrintingDevice>& container, PtrClassTemplate<IPrintingDevice>& ptr_container, int index) {
    IPrintingDevice* prototype = ptr_container.get(index);
    if (prototype) {
        PrintingDevice printing_device = *(PrintingDevice*)(prototype);
        printing_device.set_all();
        container.push_back(printing_device);
    }
    else {
        Message("Error: ", "Prototype not found in ptr_container");
    }
}
int main() {
    string command;
    DynamicVector<Printer> printer;
    DynamicVector<MFP> mfp;
    DynamicVector<Plotter> plotter;
    DynamicVector<MatrixPrinter> matrixP;
    DynamicVector<InkjetPrinter> inkjetP;
    DynamicVector<PrintingDevice> printing_device;
    PtrClassTemplate<IPrintingDevice> pointer_container;
    // ƒобавл€ем указатели в контейнер указателей
    pointer_container.add(new MFP());
    pointer_container.add(new Plotter());
    pointer_container.add(new Printer());
    pointer_container.add(new PrintingDevice());
    pointer_container.add(new MatrixPrinter());
    pointer_container.add(new InkjetPrinter());
    Message("Print \"help\" to info", "");
    Message("Select the section", " you are interested in.");
    SetColor(FOREGROUND_BLUE, NULL);
    Message("Section ", "\"Create\"");
    SetColor(15, NULL);
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Print\"");
    SetColor(15, NULL);
    //clear
    SetColor(FOREGROUND_RED, NULL);
    Message("Section ", "\"Clear\"");
    SetColor(15, NULL);
    //load
    SetColor(14, NULL);
    Message("Section ", "\"Load\"");
    SetColor(15, NULL);
    //save
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Save\"");
    SetColor(15, NULL);
    //stop
    SetColor(4, NULL);
    Message("Section ", "\"Stop\"");
    SetColor(15, NULL);
    //sort
    SetColor(6, NULL);
    Message("Section ", "\"Sort\"");
    SetColor(15, NULL);

    while (true) {
        try {
            getline(cin, command);
            if (command.empty()) continue;
            if (command == "help") { info(); }
            else if (command == "Create")
            {
                section_create();
            }
            else if (command == "Print")
            {
                section_print();

            }
            else if (command == "Clear")
            {
                section_clear();

            }
            else if (command == "Load")
            {
                section_load();

            }
            else if (command == "Save")
            {
                section_save();

            }
            else if (command == "Stop")
            {
                section_stop();

            }
            else if (command == "Sort")
            {
                section_sort();

            }
            else if (command == "create 0")
            {
                create_printing_device(printing_device, pointer_container, 2);
            }
            else if (command == "create 1") {
                create_printing_device(mfp, pointer_container, 0);
            }
            else if (command == "create 2") {
                create_printing_device(plotter, pointer_container, 1);
            }
            else if (command == "create 3") {
                create_printing_device(printer, pointer_container, 4);
            }
            else if (command == "create 4") {
                create_printing_device(matrixP, pointer_container, 4);
            }
            else if (command == "create 5") {
                create_printing_device(inkjetP, pointer_container, 4);
            }
            else if (command == "print 0") {
                Message("Print Printing Devices", "");
                printing_device.print();
            }
            else if (command == "print 1") {
                Message("Print MFP", "");
                mfp.print();
            }
            else if (command == "print 2") {
                Message("Print Plotters", "");
                plotter.print();
            }
            else if (command == "print 3") {
                Message("Print Printers", "");
                printer.print();
            }
            else if (command == "print 4") {
                Message("Print Matrix Printers", "");
                matrixP.print();
            }
            else if (command == "print 5") {
                Message("Print Inkjet Printers", "");
                inkjetP.print();
            }
            else if (command == "print ptr") {
                Message("Print all object in pointer container", "");
                pointer_container.display_all();
            }
            else if (command == "clear all") {
                printing_device.clear();
                mfp.clear();
                printer.clear();
                plotter.clear();
                matrixP.clear();
                inkjetP.clear();
                pointer_container.clear();
                Message("Success clear", "");
            }
            else if (command == "load all") {
                printing_device.load("PrintingDevice.txt");
                mfp.load("MFP.txt");
                printer.load("Printer.txt");
                plotter.load("Plotter.txt");
                matrixP.load("MatrixP.txt");
                inkjetP.load("InkjetP.txt");
            }
            else if (command == "save all") {
                printing_device.save("PrintingDevice.txt");
                mfp.save("MFP.txt");
                printer.save("Printer.txt");
                plotter.save("Plotter.txt");
                matrixP.save("MatrixP.txt");
                inkjetP.save("InkjetP.txt");
            }
            else if (command == "stop") {
                break;
            }
            else if (command == "sort by name ptr") {
                pointer_container.sort_by_name();
                Message("Success sort by name", "");
            }
            else if (command == "sort by price ptr") {
                pointer_container.sort_by_price();
                Message("Success sort by price", "");
            }
            else if (command == "sort by name") {
                printing_device.sort_by_name_h();
                mfp.sort_by_name_h();
                printer.sort_by_name_h();
                plotter.sort_by_name_h();
                matrixP.sort_by_name_h();
                inkjetP.sort_by_name_h();
                Message("Success sort by name", "");
            }
            else if (command == "sort by price") {
                printing_device.sort_by_price_h();
                mfp.sort_by_price_h();
                printer.sort_by_price_h();
                plotter.sort_by_price_h();
                matrixP.sort_by_price_h();
                inkjetP.sort_by_price_h();
                Message("Success sort by price", "");
            }
            else {
                Message("Unknown command\n", "Try again");
            }
        }
        catch (const exception& ex) { Message("", ex.what()); }
    }
    pointer_container.clear();
};
