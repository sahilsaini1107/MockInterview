https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 
/*
binary search implementation where to go left and right we decide that by comparing mid with last element.
this is optinised
*/
/*
time complexity: O(logn);
space complexity: O(1);
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //using log n algo(binary search)

        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=nums[low]){// means left half is sorted
                ans=min(ans,nums[low]);  //storing the minimum 
                low=mid+1; //eleminating left half
            }
            else{ //else right half is sorted
                ans=min(ans,nums[mid]);// storing the minimum
                high=mid-1;
            }
        }
        return ans;
    }
};