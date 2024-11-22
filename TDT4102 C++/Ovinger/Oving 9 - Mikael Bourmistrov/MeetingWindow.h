#pragma once

#include "AnimationWindow.h"
#include "widgets/TextInput.h" 
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "Meeting.h"

class MeetingWindow : public AnimationWindow {
    private:
        static constexpr int pad = 50;
        static constexpr int fieldPad = 100;
        static constexpr int fieldH = 50;
        static constexpr int fieldW = 200;
        static constexpr int btnH = 50;
        static constexpr int btnW = 100;

        Button quitBtn;
        Button personNewBtn;

        TextInput personName; 
        TextInput personEmail;

        vector<shared_ptr<Person>> people;

    public:
        MeetingWindow(int x, int y, int w, int h, const string& title);

        void cb_quit();

        void newPerson();
        void cb_new_person();

        void printPeople() const;
};