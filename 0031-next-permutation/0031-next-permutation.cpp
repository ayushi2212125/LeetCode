class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int gola_index= -1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                gola_index = i;
                break;
            }
        }
        if(gola_index != -1){
           

            for(int j=n-1; j>gola_index;j--){
                if(nums[j]>nums[gola_index]){
                    swap(nums[gola_index],nums[j]);
                    break;
                }
            }
          
        }
            reverse(nums.begin()+gola_index+1,nums.end());
        
    }
};