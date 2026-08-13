#pragma once
#include <iostream>
using namespace std;

class CppBasic{
    public:
        int num;
        int* ptr;
        enum level_rank {low=0, medium, high};
        int level;
    public:
        CppBasic(level_rank rank) : num(0), ptr(nullptr)//初始化变量
        {   //构造函数，在对象创建时被调用
            level=rank;  
            cout<<"CppBasic object created with level: " << level << std::endl;
        }    
        ~CppBasic() {
            //析构函数，在对象销毁时被调用
            std::cout << "CppBasic object destroyed" << std::endl;
        }
        void setNum(int n) {
            num = n;
            std::cout<<"Num is set to: " << num << std::endl;
        }

        void setPtr(int n,const char* name) {
            ptr=&n;
            std::cout<< name << " addres is recorded in ptr: " << ptr << std::endl;
        }
    private:
       
};
