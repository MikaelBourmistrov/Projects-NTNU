#include "MeetingWindow.h"

int main() {
    Car andreBil(3);
    Car oleBil(1);
    Car adamBil(0);

    std::shared_ptr<Person> per(new Person("Per", "PerOlav@ntnu.no"));
    Person andre("Andre", "AndreDal@ntnu.no", std::make_unique<Car>(andreBil));
    Person ole("Ole", "OleBerg@ntnu.no", std::make_unique<Car>(oleBil));
    Person adam("Adam", "AdamFjell@ntnu.no", std::make_unique<Car>(adamBil));

    std::cout << *per << "\n";
    std::cout << andre << "\n";
    std::cout << ole << "\n";
    std::cout << adam << "\n\n";

    /////////////////////////////
    {
    Meeting KjemiTMT4110Meeting2(78, 1100, 1200, Campus::Trondheim, "Andre referansemote i Kjemi TMT4110, 24.03.2023", std::shared_ptr<Person>(std::make_shared<Person>("Leif", "LeifBerg@ntnu.no", std::make_unique<Car>(3))));

    KjemiTMT4110Meeting2.addParticipant(per);     // Når jeg legget til partisipant vil ikke koden terminere, får exception, sannsynlighvis prøver å slette minne ikke har acces til.
    // KjemiTMT4110Meeting2.addParticipant(std::shared_ptr<Person>(&andre)); 
    // KjemiTMT4110Meeting2.addParticipant(std::shared_ptr<Person>(&ole)); 
    // KjemiTMT4110Meeting2.addParticipant(std::shared_ptr<Person>(&adam));

    std::cout << KjemiTMT4110Meeting2;
    }
    MeetingWindow win(220, 160, 1280, 720, "My GUI");
    
    win.wait_for_close();

    win.printPeople();

    return 0;
}

