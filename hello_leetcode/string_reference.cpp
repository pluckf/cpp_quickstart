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

    
//2026.8.14每日一题https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14
//这个不用hash表，用ascii码实现思路来源：https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/solutions/2704776/on-hua-dong-chuang-kou-pythonjavacgo-by-hl44d
int maximumLengthSubstring(string s) {
         int ans = 0, left = 0, cnt[26]{};
        for (int i = 0; i < s.length(); i++) {
            int b = s[i] - 'a';
            cnt[b]++;
            while (cnt[b] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
int main() {
    string str1 = "Hello, LeetCode!";
    string str2 =" Welcome to C++ programming.";
    cout << lengthOfLongestSubstring(str1) << endl;
    cout << lengthOfLongestSubstring(str2) << endl;
    return 0;
}