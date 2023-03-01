#include "Student.h"
#include "TxtFileHandler.h"

Student::Student(const std::string& name, const std::string& surname, std::tm born_at, const std::string& speciality) : Human(name, surname, born_at)
{
    this->speciality = speciality;
}

void Student::save(std::ostream& stream)const
{
    Human::save(stream);

    const TxtFileHandler handler;
    handler.writeField(stream, this->speciality);
}

void Student::load(std::istream& stream)
{
    Human::load(stream);
 
    const TxtFileHandler handler;
    this->speciality = handler.readField(stream);
}