#include <iostream>
#include <Windows.h>
#include "MFP.h"
#include "Container.h"
#include "Printer.h"
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
void info() {
    //create
    SetColor(FOREGROUND_BLUE, NULL);
    Message("Section ", "\"Create\"");
    SetColor(15, NULL);
    Message("Print \"create 1\"", " to create Printer");
    Message("Print \"create condenser\"", " to create mic");
    Message("Print \"create wired\"", " to create mic");
    Message("Print \"create wireless\"", " to create mic");
    Message("Print \"create default\"", " to create any mic");
    //print
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Print\"");
    SetColor(15, NULL);
    Message("Print \"print 1\"", " to print all Printers");
    Message("Print \"print condenser\"", " to print all mic this class");
    Message("Print \"print wired\"", " to print all mic this class");
    Message("Print \"print wireless\"", " to print all mic this class");
    Message("Print \"print defalut\"", " to print all mic this class");
    Message("Print \"print ptr\"", " to print all mic");
    //clear
    SetColor(FOREGROUND_RED, NULL);
    Message("Section ", "\"Clear\"");
    SetColor(15, NULL);
    Message("Print \"clear all\"", " to clear all devices in all classes");
    //load
    SetColor(14, NULL);
    Message("Section ", "\"Load\"");
    SetColor(15, NULL);
    Message("Print \"load all\"", " to load information about each class container to a file");
    //save
    SetColor(FOREGROUND_GREEN, NULL);
    Message("Section ", "\"Save\"");
    SetColor(15, NULL);
    Message("Print \"save all\"", " to save information about each class container to a file");
    //stop
    SetColor(4, NULL);
    Message("Print ", "\"stop\" to close program");
    SetColor(15, NULL);
    //sort
    SetColor(6, NULL);
    Message("Section ", "\"Sort\"");
    SetColor(15, NULL);
    Message("Print \"sort by name ptr\"", " to sort all mic in ptr container");
    Message("Print \"sort by price ptr\"", " to sort all mic in ptr container");
    Message("Print \"sort by name\"", " to sort all mic in all container");
    Message("Print \"sort by price\"", " to sort all mic in all container");
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
    DynamicVector<Printer> vdynamic_mic;
    DynamicVector<MFP> vcondenser_mic;
    DynamicVector<Plotter> vwired_mic;/*
    DynamicVector<WirelessPrintingDevice> vwireless_mic;*/
    DynamicVector<PrintingDevice> v_mic;
    PtrClassTemplate<IPrintingDevice> ptr_container;
    // ƒобавл€ем указатели в контейнер указателей
    ptr_container.add(new MFP());
    ptr_container.add(new Plotter());
    ptr_container.add(new Printer());
    ptr_container.add(new PrintingDevice());/*
    ptr_container.add(new WirelessPrintingDevice());*/

    Message("Print \"help\" to info", "");
    while (true) {
        try {
            getline(cin, command);
            if (command.empty()) continue;
            if (command == "help") { info(); }
            else if (command == "create 1")
            {
                create_printing_device(vdynamic_mic, ptr_container, 2);
            }
            else if (command == "create condenser") {
                create_printing_device(vcondenser_mic, ptr_container, 0);
            }
            else if (command == "create wired") {
                create_printing_device(vwired_mic, ptr_container, 1);
            }
            else if (command == "create wireless") {
                //create_printing_device(vwireless_mic, ptr_container, 4);
            }
            else if (command == "create default") {
                create_printing_device(v_mic, ptr_container, 3);
            }
            else if (command == "print 1") {
                Message("Print Printers", "");
                vdynamic_mic.print();
            }
            else if (command == "print condenser") {
                Message("Print Condenser mic", "");
                vcondenser_mic.print();
            }
            else if (command == "print wired") {
                Message("Print Wired mic", "");
                vwired_mic.print();
            }
            else if (command == "print wireless") {
                Message("Print Wireless mic", "");
                //vwireless_mic.print();
            }
            else if (command == "print default") {
                Message("Print default mic", "");
                v_mic.print();
            }
            else if (command == "print ptr") {
                Message("Print all object in ptr container", "");
                ptr_container.display_all();
            }
            else if (command == "clear all") {
                v_mic.clear();
                vcondenser_mic.clear();
                vdynamic_mic.clear();
                vwired_mic.clear();
                //vwireless_mic.clear();
                ptr_container.clear();
                Message("Success clear", "");
            }
            else if (command == "load all") {
                v_mic.load("default.txt");
                vcondenser_mic.load("condenser.txt");
                vdynamic_mic.load("dynamic.txt");
                vwired_mic.load("wired.txt");
                //vwireless_mic.load("wireless.txt");
            }
            else if (command == "save all") {
                v_mic.save("default.txt");
                vcondenser_mic.save("condenser.txt");
                vdynamic_mic.save("dynamic.txt");
                vwired_mic.save("wired.txt");
                //vwireless_mic.save("wireless.txt");
            }
            else if (command == "stop") {
                break;
            }
            else if (command == "sort by name ptr") {
                ptr_container.sort_by_name();
                Message("Success sort by name", "");
            }
            else if (command == "sort by price ptr") {
                ptr_container.sort_by_price();
                Message("Success sort by price", "");
            }
            else if (command == "sort by name") {
                v_mic.sort_by_name_h();
                vcondenser_mic.sort_by_name_h();
                vdynamic_mic.sort_by_name_h();
                vwired_mic.sort_by_name_h();
                //vwireless_mic.sort_by_name_h();
                Message("Success sort by name", "");
            }
            else if (command == "sort by price") {
                v_mic.sort_by_price_h();
                vcondenser_mic.sort_by_price_h();
                vdynamic_mic.sort_by_price_h();
                vwired_mic.sort_by_price_h();/*
                vwireless_mic.sort_by_price_h();*/
                Message("Success sort by price", "");
            }
            else {
                Message("Unknown command\n", "Try again");
            }
        }
        catch (const exception& ex) { Message("", ex.what()); }
    }
    ptr_container.clear();
};
