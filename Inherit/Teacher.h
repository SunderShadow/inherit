#pragma once
#include "Human.h"

class Teacher: public Human
{
protected:
    std::string speciality;
    unsigned int expirience;
public:
    Teacher() {}
    Teacher(const std::string& name, const std::string& surname, std::tm born_at, const std::string& speciality, unsigned int expirience);
    std::string getSpeciality()const;
    unsigned int getExpirience()const;

    void virtual save(std::ostream& stream)const override;
    void virtual load(std::istream& stream)override;
};

