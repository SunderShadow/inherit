#include "Human.h"
#include "TxtFileHandler.h"

std::tm createHumanBornDate(int y, int m, int d)
{
    std::tm time;

    time.tm_year = y - 1900;
    time.tm_mon = m - 1;
    time.tm_mday = d;

    return time;
}

Human::Human(const std::string& name, const std::string& surname, std::tm born_at)
{
    this->name    = name;
    this->surname = surname;
    this->born_at = born_at;
}

std::string Human::getName()const
{
    return this->name;
}

std::string Human::getSurname()const
{
    return this->surname;
}

std::tm Human::getBornDate()const
{
    return this->born_at;
}

int Human::getAge()const
{
    std::time_t current_time = time(0);
    std::tm now;

    localtime_s(&now, &current_time);

    int age = now.tm_year - this->born_at.tm_year;

    age -= this->born_at.tm_mon >  now.tm_mon;
    age -= this->born_at.tm_mon == now.tm_mon && this->born_at.tm_mday > now.tm_mday;

    return age;
}

void Human::save(std::ostream& stream)const
{
    TxtFileHandler handler;

    handler.writeField(stream, typeid(*this).name());
    handler.writeField(stream, this->name);
    handler.writeField(stream, this->surname);

    // Честно, очень лень писать парсер даты. Прям честно-честно.
}

void Human::load(std::istream& stream)
{
    TxtFileHandler handler;

    this->name = handler.readField(stream);
    this->surname = handler.readField(stream);
}