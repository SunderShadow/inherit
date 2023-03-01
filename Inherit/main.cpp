#include <iostream>

#include "Teacher.h"
#include "Student.h"
#include "TxtFileHandler.h"

#define STORAGE_FILE "Storage.txt"

void testSave()
{
    Human* group[3] = {
        new Human("John", "Vatson", createHumanBornDate(1950, 3, 1)),
        new Teacher("Sherlock", "Holmes", createHumanBornDate(1950, 3, 1), "investigator-consultant", 3),
        new Student("Mooley", "Hooper", createHumanBornDate(1950, 3, 1), "chemistry")
    };

    std::ofstream stream;
    stream.open(STORAGE_FILE);

    for (auto& member : group)
    {
        member->save(stream);
        stream << '\n';
    }

    stream.close();
}

void testLoad()
{
    Human* group[3];

    std::ifstream stream;
    stream.open(STORAGE_FILE);

    TxtFileHandler handler;

    for (auto &member : group)
    {
        std::string type = handler.readField(stream);

        if (type == typeid(Teacher).name()) {
            member = new Teacher();
        }

        if (type == typeid(Human).name()) {
            member = new Human();
        }

        if (type == typeid(Student).name()) {
            member = new Student();
        }

        member->load(stream);

        stream.get(); // <- \n

        std::cout << member->getName() << ' ' << member->getSurname() << std::endl;
    }

    stream.close();
}

int main()
{
    testSave();
    testLoad();

    return 0;
}