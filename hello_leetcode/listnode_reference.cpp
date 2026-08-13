#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int NodeLen(ListNode* l1){
    int lens=0;
    ListNode* now=l1;
    while(now!=nullptr){
        now=now->next;
        lens++;
    }
    return lens;
 }
 int main(){
    ListNode* l1=new ListNode(1);
    ListNode* l2=new ListNode(2);
    ListNode* l3=new ListNode(3);
    l1->next=l2;
    l2->next=l3;
    int lens=NodeLen(l1);
    cout<<"lens="<<lens<<endl;
    return 0;
    }