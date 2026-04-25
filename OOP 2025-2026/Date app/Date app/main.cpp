#include <iostream>
#include <exception>
#include "Date.h"
#include "Car.h"
#include "EnumTypes.h"
#include "System.h"

int main()
{
    try{
        Date date(25, 4, 2026);
        Person p("Nick", "Peterson", "3ti", date, Gender::Male);
        Person t("Georg", "Malinov", "4ti", date, Gender::Male);
        Car c("1", "Mitsubishi", date, 205, p);
        Car d("2", "Subaru", date, 225, p);
        Car e("3", "Ford", date, 245, t);
        Car f("4", "Mercedes", date, 245, t);
        Car g("5", "BMW", date, 245);
        System sys(c, p);
        sys.addPerson(t);
        sys.addCar(d);
        sys.addCar(e);
        sys.addCar(f);
        sys.addCar(g);
        //std::cout << "People with many cars: " << sys.countPeopleWithMultipleCars() << "\n";
        //std::cout << "Cars without owner: " << sys.countCarsWithoutOwner() << "\n";

        //sys.printCarsOwnerBy(t);
        sys.printPeopleWithCars(1);
    }
    catch (...) {
        std::cout << "An error has occured, try again!";
    }
    return 0;
}