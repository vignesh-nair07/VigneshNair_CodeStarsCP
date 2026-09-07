/*3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:
0 <= s.length <= 105
s consists of English letters, digits, symbols and spaces
*/

//SOLUTION:
class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int n=a.size();
        int l=0,r=0;

        int ans=0;
        unordered_set<char> st;
        while(r<n){
            if(!st.count(a[r])){
                st.insert(a[r]);
                int len=r-l+1;
                ans=max(ans,len);
                r++;
            }
            else{
                while(st.count(a[r])){
                    st.erase(a[l]);
                    l++;
                }
                st.insert(a[r]);
                r++;
            }
        }
        return ans;
    }
};
