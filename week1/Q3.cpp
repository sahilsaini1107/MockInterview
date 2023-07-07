https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // vector<int> s;
        // for (int i=0;i<n;i++){
        //     for (int j=i+1;j<n;j++){
        //         if((target - nums[i]) == nums[j]){
        //             s.push_back(i);
        //             s.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return s;

        vector<int> ans;
        unordered_map<int,int> mp;
        int size=nums.size();
        for(int i=0 ;i< size;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};