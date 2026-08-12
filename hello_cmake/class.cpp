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


int main() {
    CppBasic* cpp=new CppBasic(CppBasic::medium);
    cpp->setNum(10);
    cpp->setPtr(20,"Twenty");
    delete cpp;
    //执行销毁示例命令后自动调用析构函数，当然，这只是一种条件触发方式，
    //就算没有类这个概念，也可以实现这个效果，本质就是满足条件调用函数。
    return 0;
}