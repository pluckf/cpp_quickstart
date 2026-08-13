#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct vectors{
    public:
        char* Buffer;
        unsigned int BufferSize;
    public:
        vectors(const char *buffer)
        {
            BufferSize=strlen(buffer);
            Buffer=new char[BufferSize+1];
            memcpy(Buffer, buffer, BufferSize);
            Buffer[BufferSize]='\0';
        }
        
        ~vectors(){delete[] Buffer;}
        //深拷贝函数
        vectors(const vectors& other) {
            BufferSize = other.BufferSize;
            Buffer = new char[BufferSize + 1];
            memcpy(Buffer, other.Buffer, BufferSize);
            Buffer[BufferSize] = '\0';
            cout<< "Deep copy constructor called" << endl;
        }
        //默认拷贝函数
        // vectors(const vectors& other){
        //     BufferSize=other.BufferSize;
        //     Buffer=other.Buffer;//浅拷贝，指针指向同一块内存
        // }
        
    
};     

ostream& operator<<(ostream& stream,const vectors& a)
{   
   stream<< a.Buffer<<","<<a.BufferSize;
   return stream;
};

int main(){
    vectors v1("Hello, World!");
    vectors v2=v1;//这是浅copy，生成v2.buffer与v1.buffer指向同一块内存，
    //v1析构时,内存被释放，v2.buffer就变成了悬空指针，访问v2.buffer就会出现段错误

    cout << "v1 = " << v1 << std::endl;
    cout << "v2 = " << v2 << std::endl;
    



    // vector<vectors> vecs;
    // vecs.push_back(vectors("Hello, World!"));
    // cout << "vecs[0] = " << vecs[0] << std::endl;
    return 0;
}


//下面历程讲述了数组声明以及赋值
// int main() {
//     #ifdef _WIN32
//     SetConsoleOutputCP(CP_UTF8);
//     #endif
//     vectors* p=new vectors[5];//声明数组
//     *p=vectors(1,2);//指针dereference后当然是第一个元素啦，原理都是一样的
//     p[1].x=10;
//     for (int i = 0; i < 5; i++) {
//     std::cout << "p[" << i << "] = (" << p[i].x << ", " << p[i].y << ")" << std::endl;
// }
//     delete[] p;
//     return 0;
// }