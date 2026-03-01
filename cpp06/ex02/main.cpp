#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int i = rand() % 3;
    switch (i)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" <<std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" <<std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" <<std::endl;

}

void identify(Base& p)
{
   try
   {
        dynamic_cast<A&>(p);
        std::cout << "A" <<std::endl;
        return;
   }
   catch(const std::exception& e){}
   try
   {
        dynamic_cast<B&>(p);
        std::cout << "B" <<std::endl;
        return;
   }
   catch(const std::exception& e){}
   try
   {
        dynamic_cast<C&>(p);
        std::cout << "C" <<std::endl;
        return;
   }
   catch(const std::exception& e){}
}
int main()
{
    std::srand(std::time(NULL));
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr; 

    return 0;
}