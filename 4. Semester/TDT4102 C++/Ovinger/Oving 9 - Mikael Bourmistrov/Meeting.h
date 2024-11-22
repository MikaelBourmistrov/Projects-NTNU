#pragma once

#include "Person.h"

enum class Campus
{
	Trondheim,
	Ålesund,
	Gjøvik
};

class Meeting {
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;
    
    public:     // konstruktorer
        Meeting(int d, int sT, int eT, Campus loc, std::string sub, const std::shared_ptr<Person> lead);

    public:     // get funksjoner
        int getDay() const;
        int getStartTime() const;
        int getEndTime() const;
        Campus getLocation() const;
        std::string getSubject() const;
        const std::shared_ptr<Person> getLeader() const;

        std::vector<std::string> getParticipantList() const;

    public:
        void addParticipant(const std::shared_ptr<Person> person);

        std::vector<std::shared_ptr<Person>> findPotentialCoDriving(const Meeting& m2) const;
};

std::ostream& operator << (std::ostream& os, const Campus& campus);

std::ostream& operator << (std::ostream& os, const Meeting& m);

