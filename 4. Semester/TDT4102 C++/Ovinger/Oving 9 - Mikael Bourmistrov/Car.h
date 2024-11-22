#pragma once

class Car {
    private:
        int freeSeats;

    public:
        Car(unsigned int numFreeSeats);

    public:
        bool hasFreeSeats() const;

        void reserveFreeSeat();
};
