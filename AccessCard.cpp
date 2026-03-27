#include "AccessCard.h"
#include <iostream>
using namespace std;

AccessCard::AccessCard(string cardID, int accessLevel) {
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}

string AccessCard::getCardID() {
    return cardID;
}

int AccessCard::getAccessLevel() {
    return accessLevel;
}

void AccessCard::displayCardInfo() {
    cout << "Card ID: " << cardID << ", Access Level: " << accessLevel << endl;
}