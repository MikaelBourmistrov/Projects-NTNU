#pragma once

#include "Car.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>

class Person {
    private:
        std::string name, email;
        std::unique_ptr<Car> car;

    public:     // Konstruktorer
        Person(std::string pName, std::string pEmail, std::unique_ptr<Car> pCar = nullptr);

    public:     // Funksjoner
        std::string getName() const;
        std::string getEmail() const;

        void setEmail(std::string pEmail);

        bool hasAvailableSeats() const;
    
    public:     // Opperatorer
        friend std::ostream& operator << (std::ostream& os, const Person& p);
};