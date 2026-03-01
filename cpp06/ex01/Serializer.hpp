#pragma once 

#include <iostream>
#include <stdint.h>

struct Data
{
    int i;
    std::string name;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& s);
        Serializer& operator=(const Serializer& s);
        ~Serializer();
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};