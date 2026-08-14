#include <iostream>
#include <string>
using namespace std;
//题目链接: https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/        
int lengthOfLongestSubstring(string s) {
        int res=0;
        int head=0;
        int tail=0;
        while(tail<s.length()){
            for(int i=head;i<tail;i++){
                if(s[i]==s[tail]){
                    head=i+1;
                    break;
                }
            }
            res=max(res,tail-head+1);
            tail++;
        }
        return res;
}


int main() {
    string str1 = "Hello, LeetCode!";
    string str2 =" Welcome to C++ programming.";
    cout << lengthOfLongestSubstring(str1) << endl;
    cout << lengthOfLongestSubstring(str2) << endl;
    return 0;
}