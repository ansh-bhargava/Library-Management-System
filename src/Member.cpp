#include "Member.h"
#include <iostream>
Member::Member(int id, std::string n) : memberId(id), name(std::move(n)) {}
void Member::display() const {
    std::cout << "Member ID: " << memberId << ", Name: " << name << std::endl;
}
