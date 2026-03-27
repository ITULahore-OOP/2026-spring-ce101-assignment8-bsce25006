#include "Department.h"

Department::Department(string departmentName) {
    this->departmentName = departmentName;
    memberCount = 0;
}

void Department::addMember(UniversityMember* member) {
    members[memberCount++] = member;
}

void Department::displayAllRoles() {
    for (int i = 0; i < memberCount; i++) {
        members[i]->displayRole();
    }
}