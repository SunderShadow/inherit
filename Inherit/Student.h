#pragma once
#include "Human.h"

class Student : public Human
{
protected:
    std::string speciality;
public:
    Student(){}
    Student(const std::string& name, const std::string& surname, std::tm born_at, const std::string& speciality);

    void virtual save(std::ostream& stream)const override;
    void virtual load(std::istream& stream)override;
};

