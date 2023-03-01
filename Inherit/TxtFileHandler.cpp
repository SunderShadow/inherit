#include "TxtFileHandler.h"

void TxtFileHandler::writeField(std::ostream& stream, std::string value)const
{
    stream << value << this->DELIMETER;
}

void TxtFileHandler::writeField(std::ostream& stream, int value)const
{
    stream << value << this->DELIMETER;
}

std::string TxtFileHandler::readField(std::istream& stream)const
{
    std::string buffer;

    char chr = 0;
    while (!stream.eof())
    {
        chr = stream.get();
        if (chr == this->DELIMETER || chr == EOF) break;

        buffer += chr;
    } 

    return buffer;
}