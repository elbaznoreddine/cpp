#include "Serializer.hpp"

int main()
{
    Data* d = new Data(); 
    
    d->i = 15;
    d->name = "ok";

    uintptr_t raw = Serializer::serialize(d);
    
    Data* processed = Serializer::deserialize(raw);

    std::cout << "Original address:    " << d << std::endl;
    std::cout << "Deserialized addr:  " << processed << std::endl;
    
    if (d == processed)
    {
        std::cout << "Pointers match" << std::endl;
        std::cout << "Data: " << processed->i << " " << processed->name << std::endl;
    }
    delete d;
    return 0;
}