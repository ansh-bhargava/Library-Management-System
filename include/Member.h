#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <vector>
class Member {
public:
    int memberId;
    std::string name;
    Member(int id, std::string name);
    void display() const;
};
#endif
