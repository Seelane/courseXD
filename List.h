// List.h
#pragma once
#include <vector>
#include "PrintingDevice.h"
#include "Connection_Type.h"
#include <string>



class DeviceList {
public:
    struct Node {
        Device device;
        Node* next;
        Node* prev;

        Node(PrintingDevice device, Node* prev, Node* next);
    };

    Node* head;
    Node* tail;

    DeviceList();

    ~DeviceList();

    void addDevice(const PrintingDevice& device);

    void removeDevice(const char* model);

    void displayDevices() const;

    void SortModel() const;
    void SortPrice() const;

    PrintingDevice* searchDevice(const char* model) const;

    int getSize() const;

    std::vector<PrintingDevice> getDevices() const;
};