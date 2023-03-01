#pragma once
#include <string>
#include <ctime>
#include <fstream>

std::tm createHumanBornDate(int y, int m, int d);

class Human
{
protected:
    std::string name, surname;
    std::tm born_at;
public:
    Human() {}
    Human(const std::string& name, const std::string& surname, std::tm born_at);

    std::string getName()const;
    std::string getSurname()const;
    std::tm getBornDate()const;

    int getAge()const;

    void virtual save(std::ostream& stream)const;
    void virtual load(std::istream& stream);
};

