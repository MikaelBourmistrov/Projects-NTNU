#include "Meeting.h"

std::ostream& operator << (std::ostream& os, const Campus& campus) {
    switch (campus) {
        case Campus::Gjøvik: os << "Gjøvik"; break;
        case Campus::Trondheim: os << "Trondheim"; break;
        case Campus::Ålesund: os << "Ålesund"; break;
    }
    return os;
}

int Meeting::getDay() const {
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

Campus Meeting::getLocation() const {
    return location;
}

std::string Meeting::getSubject() const {
    return subject;
}

const std::shared_ptr<Person> Meeting::getLeader() const {
    return leader;
}

void Meeting::addParticipant(const std::shared_ptr<Person> person) { //er dette en dårlig idealtså å ta en refrence a pointern?
    participants.emplace_back(person);
}

Meeting::Meeting(int d, int sT, int eT, Campus loc, std::string sub, const std::shared_ptr<Person> lead): 
            day(d), startTime(sT), endTime(eT), location(loc), subject(sub), leader(lead) 
            {
                addParticipant(lead);
            }

std::vector<std::string> Meeting::getParticipantList() const {
    std::vector<std::string> names;

    for (auto person : participants) { names.emplace_back(person->getName()); }

    return names;
}

std::ostream& operator << (std::ostream& os, const Meeting& m) {
    os << "Subject: " << m.getSubject() << "\n";
    os << "Location: " << m.getLocation() << "\n";
    os << "Start time: " << m.getStartTime() << "\n";
    os << "End time: " << m.getEndTime() << "\n";
    os << "Meeting leader: " << m.getLeader()->getName() << "\n";
    os << "Participants: " << "\n";

    for (auto partisipant : m.getParticipantList()) { os << partisipant << "\n"; }

    return os;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting& other) const {
    std::vector<std::shared_ptr<Person>> drivers;


    if ((this->location == other.getLocation()) && (this->day == other.getDay())) {
        if ((abs(other.getStartTime() - this->startTime) <= 100) && (abs(other.getEndTime() - this->endTime) <= 100)) {

            for (const auto participant : other.participants) {
                if (participant->hasAvailableSeats()) {
                        drivers.emplace_back(participant);
                }
            }

        }
    }

    return drivers;
} 