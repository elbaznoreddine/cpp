#include <iostream>

class test
{
  protected:
    std::string  name;
    int id;

  public:
    test(std::string name, int id);
    void print();
    ~test();
};

test::test(std::string name , int id)
{
  this->name = name;
  this->id =id;
}
void test::print()
{
  std::cout << "name : " << name << ", id : " << id << std::endl;
}
test::~test(void){}


class test1 : public test
{
  public:
    test1(std::string name, int id);
    ~test1();
};

test1::test1(std::string name , int id) : test(name, id)
{
  this->name = name;
  this->id =id;
}

test1::~test1(){}
int main()
{
  test t("noreddine", 0);
  test1 t1("ahmed", 1);


  t.print();
  t1.print();

}