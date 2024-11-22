#include "LinkedList.h"

std::ostream & operator<<(std::ostream & os, const LinkedList::Node & node) { return os << node.getValue(); }  //videre har jeg ikke brukt funksjonene men direkete aksesert privatvariablene

LinkedList::Node* LinkedList::LinkedList::insert(Node *pos, const std::string& value) {   
        Node* newNode = new Node(value, std::unique_ptr<Node>(pos), nullptr);  // Next node pekere skal være unique, denne skal head bruke som man kan se på som en "unique ptr"
        
        if (isEmpty()) {                                                        // Om head->next er nullptr betyr det at den er tom. Dermed må vår nye insert legges inn som første element
            head->next = std::unique_ptr<Node>(newNode);                        // trenger ikke å gjøre noe annet pga måten jeg definere newNode.
        }
        else {                                                                  // for tilfellene da linked listen ikke er tom
            if (pos->prev == nullptr) {                                         // om prev til neste node er nullptr betyr det at den var først, 
                head->next = std::unique_ptr<Node>(newNode);                    // dermed må head nå pointe til elemente vi skal sette
            }
            
            newNode->prev = pos->prev;                                          // Vi setter den nye noden sin prev lik prev til den forran (om ikke klart lag en skisse)
            pos->prev = newNode;                                                // og setter den neste sin prev lik newNode
        }
        return newNode;   // her vil jeg få en exception, vi prøver å skrive ut en kopi av unique_ptr sin ptr (uten at den er unique)
    }

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos) {
        if (isEmpty()) {
            std::cout<<"Error: operasjon ikke definert for en tom liste";
            return nullptr;
        }
        else {
            Node* returnNode = pos->getNext();   //kommer forbi error, men fortsatt samme problem lol   // hvorfor skal returtypen til funskonne ikke være uniqueptr, den returnerer jo peker til neste element.

            if (pos->prev == nullptr) { head->next = std::move(pos->next); } // om prev til noden vi skal slette er nullptr, betyr det at head må flyttes      
            
            (pos->next)->prev = pos->prev;                                              // Neste element sin prev må være pos sin prev. Skisse om uklart, husk å bruk funk når kommer på cpp fil
            (pos->prev)->next = std::move(pos->next);                                   // Og her settes den forrige sin next til pos sin next, skisse. 

            return returnNode; // her vil jeg få en exception, vi prøver å skrive ut en kopi av unique_ptr sin ptr (uten at den er unique)
        }
    }

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value) {
        if (isEmpty()) {
            std::cout<<"Error: operasjon ikke definert for en tom liste";
            return nullptr;
        }
        else {
            Node* curr = begin();                   // samme problem som nevnt over.

            while(curr != nullptr) {
                if (curr->getValue() == value) { return curr; }
                else { curr = curr->getNext(); }
            }

            std::cout<<"Error: Ingen samsvar funnet";       // Om vi kom oss ut av while løkken, betyr det det ikke var funnet noe
            return nullptr;
        }
    }

void LinkedList::LinkedList::remove(const std::string& value) {
        if (find(value) == nullptr) { return; }
        else { remove(find(value)); }
    }

std::ostream& operator<<(std::ostream& os, const LinkedList::LinkedList& list) {
    LinkedList::Node* curr = list.begin(); 
    while (curr != nullptr) { os << curr << "\n"; }
    return os;
}