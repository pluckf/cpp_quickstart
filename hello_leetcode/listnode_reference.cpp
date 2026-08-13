#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}
void deleteList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;  // 先保存下一个节点
        delete head;                  // 删除当前节点
        head = next;                 // 移动到下一个
    }
}
int NodeLen(ListNode* l1){
    int lens=0;
    ListNode* now=l1;
    while(now!=nullptr){
        cout<<"now->val="<<now->val<<"now->next="<<now->next<<endl;
        now=now->next;
        lens++;
    }
    return lens;
 }
//题目链接: https://leetcode.cn/problems/add-two-numbers/description/
//已完成代码
class Solution {
private:
    bool advance= false;
    int loc=true;
    ListNode* res=nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head =new ListNode(0);
        int l1_num,l2_num;
        while(l1||l2||advance){
            if (l1) l1_num=l1->val;else l1_num=0;
            if (l2) l2_num=l2->val;else l2_num=0;
            head->next =new ListNode((l1_num+l2_num+advance)%10);
            if(l1_num+l2_num+advance>=10) advance=true; else advance=false;
            if(loc){loc=false;res=head->next;}
            head=head->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        delete head;    
        return res;
    }
    ~Solution() {//释放链表内存
        deleteList(res);
    }
};

int main() {
    vector<int> arr1 = {9, 9, 9};
    vector<int> arr2 = {9, 9, 9,9,9};

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // 输出结果链表
    while (result) {
    cout << result->val << " ";
    result = result->next;
    }
    // 释放内存
    deleteList(l1);
    deleteList(l2);
    deleteList(result);
    return 0;
}

