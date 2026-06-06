#include <iostream>
#include "Phone.hpp"
#include "Smartphone.hpp"
#include "Store.hpp"

int main()
{
    Phone phone("Iphone 16 pro", "Apple", 100);
    Smartphone sPhone(phone, "IOS", 128);
    Smartphone smartphone("Galaxy S20", "Samsung", 1000, "Android", 256);
    /*
    std::cout << "Phone info\n" << phone.getBrand() << " " << phone.getModel() << " " << phone.getPrice() << "\n\n";
    std::cout << "sPhone info\n" << sPhone.getBrand() << " " << sPhone.getModel() << " " << sPhone.getPrice() << " " << sPhone.getOS() << " " << sPhone.getMemory() << "\n\n";
    std::cout << "smartphone info\n" << smartphone.getBrand() << " " << smartphone.getModel() << " " << smartphone.getPrice() << " " << sPhone.getOS() << " " << sPhone.getMemory() << "\n\n";
    */
    Store s(2000);
    s.addPhone(phone);
    s.addPhone(phone);
    s.addPhone(phone);
    s.addPhone(phone);
    s.addPhone(phone);
    s.addPhone(sPhone);
    s.addPhone(sPhone);
    s.print();
}