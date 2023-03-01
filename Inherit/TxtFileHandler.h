#pragma once
#include <string>
#include <fstream>

class TxtFileHandler
{
protected:
    const static char DELIMETER = '|';

public:
    void writeField(std::ostream& stream, std::string value) const;
    void writeField(std::ostream& stream, int value)const;

    std::string readField(std::istream& stream) const;
};

