#include <iostream>
#include "Phone.hpp"
#include "Smartphone.hpp"

int main()
{
    Phone phone("Iphone 16 pro", "Apple", 1000);
    Smartphone sPhone(phone, "IOS", 128);
    Smartphone smartphone("Galaxy S20", "Samsung", 1000, "Android", 256);
    std::cout << "Phone info\n" << phone.getBrand() << " " << phone.getModel() << " " << phone.getPrice() << "\n\n";
    std::cout << "sPhone info\n" << sPhone.getBrand() << " " << sPhone.getModel() << " " << sPhone.getPrice() << " " << sPhone.getOS() << " " << sPhone.getMemory() << "\n\n";
    std::cout << "smartphone info\n" << smartphone.getBrand() << " " << smartphone.getModel() << " " << smartphone.getPrice() << " " << sPhone.getOS() << " " << sPhone.getMemory() << "\n\n";

}
