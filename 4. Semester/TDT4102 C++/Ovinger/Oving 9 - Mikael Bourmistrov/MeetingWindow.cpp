#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string& title): AnimationWindow(x, y, w, h, title),
                                                                               quitBtn({w - pad - btnW, h - pad - btnH}, btnW, btnH, "Quit"),
                                                                               personNewBtn({fieldPad, 3*pad + 2*fieldH}, btnW, btnH, "Add prsn"),
                                                                               personName({fieldPad, pad}, fieldW, fieldH, "Name"),
                                                                               personEmail({fieldPad, 2*pad + fieldH}, fieldW, fieldH, "Email")
{
    add(quitBtn);
    add(personNewBtn);

    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    personNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_person, this));

    add(personName);
    add(personEmail);
}

void MeetingWindow::cb_quit() {
    close();
}

void MeetingWindow::newPerson() {
    if ((personName.getText() != "") && (personEmail.getText() != "")) {
        people.emplace_back(new Person(personName.getText(), personEmail.getText()));
        personName.setText(""); 
        personEmail.setText("");
    }
}

void MeetingWindow::cb_new_person() {
    newPerson();
}

void MeetingWindow::printPeople() const {
    cout << "People added:" << "\n";
    for (auto person : people) { cout << *person << "\n"; }
}

