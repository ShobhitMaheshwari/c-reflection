#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "Reflection.cpp"

using namespace rapidjson;

struct Person
{
    Person(const char *name, int age)
            :
            name(name),
            age(age)
    {
    }
private:
    REFLECTABLE
    (
    (const char *) name,
    (int) age
    )
};

struct print_visitor
{
    template<class FieldData>
    void operator()(FieldData f)
    {
        std::cout << f.name() << "=" << f.get() << std::endl;
    }
};

template<class T>
void print_fields(T & x)
{
    visit_each(x, print_visitor());
}

int main()
{
    Person p("Tom", 82);
    print_fields(p);
    return 0;
}