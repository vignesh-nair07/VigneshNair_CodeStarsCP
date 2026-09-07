/*1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/
//SOLUTION:
class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int l=0,r=0;
        int ans=0;

        int ct0=0;
        while(r<n){
            if(a[r]==0){
                ct0++;
            }

            while(ct0>k){
                if(a[l]==0){
                    ct0--;
                }
                l++;
            }
            int len=r-l+1;
            ans=max(ans,len);
            r++;
        }
        return ans;
    }
};
//TC: O(n)
//SC: O(1)
