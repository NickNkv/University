#include <iostream>
#include "Phone.hpp"
#include "Smartphone.hpp"
#include "Store.hpp"

int main()
{
    try {
        //creating (smart)phones
        Phone phone("Iphone 16 pro", "Apple", 100);
        Smartphone sPhone(phone, "IOS", 128);
        Phone a10("Galaxy A10", "Samsung", 800);
        Smartphone smartphone("Galaxy S20", "Samsung", 1000, "Android", 256);

        //creating a store and adding/selling phones
        Store s(6000);
        s.addPhone(phone);
        s.addPhone(sPhone);
        s.addPhone(smartphone);
        s.addPhone(a10);
        s.print();

        std::cout << "-------------------------- selling Iphone 16 pro, Apple \n\n";
        s.sell("Iphone 16 pro", "Apple");
        s.print();

        std::cout << "-------------------------- adding a new Iphone 16 pro Apple\n\n";
        s.addPhone(sPhone);
        s.addPhone(phone);
        s.print();

        std::cout << "-------------------------- removing the cheapest Apple\n\n";
        s.removeCheapest("Apple");
        s.print();
    }
    catch (std::bad_alloc) {
        std::cout << "Memory problem, please try again later :)";
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
    catch (const char* e) {
        std::cout << e << "\n";
    }
    catch (...) {
        std::cout << "Something went wrong :(";
    }
}