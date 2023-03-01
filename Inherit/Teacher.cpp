#include "Teacher.h"
#include "TxtFileHandler.h"

Teacher::Teacher(const std::string& name, const std::string& surname, std::tm born_at, const std::string& speciality, unsigned int expirience) : Human(name, surname, born_at)
{
    this->speciality = speciality;
    this->expirience = expirience;
}

std::string Teacher::getSpeciality()const
{
    return this->speciality;
}

unsigned int Teacher::getExpirience()const
{
    return this->expirience;
}

void Teacher::save(std::ostream& stream)const
{
    Human::save(stream);
    
    const TxtFileHandler handler;

    handler.writeField(stream, this->expirience);
    handler.writeField(stream, this->speciality);
}

void Teacher::load(std::istream& stream)
{
    Human::load(stream);

    const TxtFileHandler handler;

    this->expirience = handler.readField(stream)[0] - 48;
    this->speciality = handler.readField(stream);
}