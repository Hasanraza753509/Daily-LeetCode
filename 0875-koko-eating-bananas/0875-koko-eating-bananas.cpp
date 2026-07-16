class Solution {
public:
    long long getdivisor(vector<int>& nums,int d){
        long long sum=0;
        for(int i:nums){
            sum=sum+(1LL*i+d-1)/d;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mid;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long target=getdivisor(piles,mid);
            
            if(target<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }

};