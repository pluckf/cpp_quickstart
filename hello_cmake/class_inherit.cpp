#include <iostream>
#include "classes.cpp"


class Base : public CppBasic
{
    public :
        using CppBasic::CppBasic; // Inherit the constructor from CppBasic
        float base_num=10.0f;
        
};
int main() {
    Base base_obj(CppBasic::medium);
    base_obj.setNum(10);
    base_obj.setPtr(20,"Twenty");
    std::cout << "Base number: " << base_obj.base_num << std::endl;
    return 0;
}