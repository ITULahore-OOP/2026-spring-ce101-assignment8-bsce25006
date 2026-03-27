#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H

#include <string>
using namespace std;

class UniversityMember {
private:
    string name;
    int memberID;

public:
    UniversityMember(string name, int memberID);
    virtual ~UniversityMember();

    string getName();
    int getMemberID();

    virtual void displayRole() = 0;
};

#endif