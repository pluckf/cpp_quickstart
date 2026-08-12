#include <iostream>
#include <cstring>

using namespace std;
void add_one(float* ptr) {
    (*ptr)++;
}
int main() {
    float a=10;
    add_one(&a);
    cout << a << endl;
    /**
     * appicate the memory in heap
    char* str = new char[20];
    memset(str, 0, 20); 
    cin.getline(str, 20);
    cout<<"You entered: " << str << endl;
    delete[] str;
     */
    
    return 0;
}