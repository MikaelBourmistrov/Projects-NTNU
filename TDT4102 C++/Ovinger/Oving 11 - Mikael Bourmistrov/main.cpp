#include "iteratorer.h"
#include "Person.h"
#include "LinkedList.h"
#include "templates.h"

int main() {
    ///////////////////////////////// oppgave a-c /////////////////////////////////
    std::vector<std::string> vektor{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    
    for (auto it = vektor.begin(); it != vektor.end(); it++) {    // auto = std::vector<std::string>::iterator 
        std::cout << *it << ((it != (vektor.end() - 1))?", ":".\n");
    }

    for (auto  it = vektor.rbegin(); it != vektor.rend(); it++) {    // auto = std::vector<std::string>::reverse_iterator 
        std::cout << *it << ((it != (vektor.rend() - 1))?", ":".\n");
    }

    std::vector<std::string> vReplace{"Lorem", "Ipsum", "Dolor", "Lorem"};

    replace(vReplace, "Lorem", "Latin");
    //replace_direct(vReplace, "Lorem", "Latin");

    for (auto it = vReplace.begin(); it != vReplace.end(); it++) {    // auto = std::vector<std::string>::iterator 
        std::cout << *it << ((it != (vReplace.end() - 1))?", ":".\n\n");
    }

    ///////////////////////////////// Oppgave d /////////////////////////////////
    std::set<std::string> set{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};

    for (auto it = set.begin(); it != set.end(); it++) {    // auto = std::set<std::string>::iterator 
        std::cout << *it << ", ";
    }

    std::cout << "\n";

    for (auto  it = set.rbegin(); it != set.rend(); it++) {    // auto = std::set<std::string>::reverse_iterator 
        std::cout << *it << ", ";
    }

    std::cout << "\n";

    std::vector<std::string> setReplace{"Lorem", "Ipsum", "Dolor", "Lorem"};

    replace(setReplace, "Lorem", "Latin");
    //replace_direct(setReplace, "Lorem", "Latin");

    for (auto it = setReplace.begin(); it != setReplace.end(); it++) {    // auto = std::set<std::string>::iterator 
        std::cout << *it << ", ";
    }

    std::cout << "\n\n";

    ///////////////////////////////// Oppgave 2 /////////////////////////////////
    std::list<Person> pList;

    Person ole("Ole", "Mann");
    Person per("Per", "Hermann");
    Person olav("Olav", "Berg");
    Person ada("Ada", "Dal");
    Person ada2("Ada", "Berg");

    insertOrdered(pList, ole);
    insertOrdered(pList, per);
    insertOrdered(pList, olav);
    insertOrdered(pList, ada);
    insertOrdered(pList, ada2);

    for (auto p : pList) std::cout << p << "\n";

    ///////////////////////////////// Oppgave 3 /////////////////////////////////
    LinkedList::LinkedList newList;

    // LinkedList::Node* firstElem = newList.insert(newList.end(), "LMAO THIS IS A NEW ELEMENT; SOM ER FØRST BTW");
    // LinkedList::Node* secondElem = newList.insert(firstElem, "SECOND ELEMENT CUS YAY, BUT BEHIND FIRST");
    // LinkedList::Node* lastElem = newList.insert(newList.end(), "LAST ELEMENT; WHICH IS ALSO LAST IN THE LIST");

    // std::cout << newList; 

    ///////////////////////////////// Oppgave 4 /////////////////////////////////
    int a = 1;
    int b = 2;
    int c = maximum(a, b);
    // c er nå 2.
    double d = 2.4;
    double e = 3.2;
    double f = maximum(d,e);

    std::cout << "c: " << c << "\nf: " << f << "\n";

    //////////////////
    std::vector<int> g{1, 2, 3, 4, 5, 6, 7};
    shuffle(g); // Resultat, rekkefølgen i a er endret.
    for (auto it = g.begin(); it != g.end(); it++) {    // auto = std::vector<std::string>::iterator 
        std::cout << *it << ((it != (g.end() - 1))?", ":".\n");
    }

    std::vector<double> h{1.2, 2.2, 3.2, 4.2};
    shuffle(h); // Resultat, rekkefølgen i b er endret.
    for (auto it = h.begin(); it != h.end(); it++) {    // auto = std::vector<std::string>::iterator 
        std::cout << *it << ((it != (h.end() - 1))?", ":".\n");
    }

    std::vector<std::string> i{"one", "two", "three", "four"};
    shuffle(i); // Resultat, rekkefølgen i c er endret.
    for (auto it = i.begin(); it != i.end(); it++) {    // auto = std::vector<std::string>::iterator 
        std::cout << *it << ((it != (i.end() - 1))?", ":".\n");
    }

    return 0;
}
