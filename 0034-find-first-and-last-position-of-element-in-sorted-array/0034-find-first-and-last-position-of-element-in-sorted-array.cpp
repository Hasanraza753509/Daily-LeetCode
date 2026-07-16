class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int mid;
        int high=nums.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                int lower=mid;
                int higher=mid;
                while(higher<=nums.size()-1 && nums[higher]==target){
                    higher++;
                }
                while(lower>=0 && nums[lower]==target){
                    lower--;
                }
                return {lower+1,higher-1};
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};