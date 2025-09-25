class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_index = -1;

        // 1. Find the pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                gola_index = i;
                break;
            }
        }

        if (gola_index != -1) {
            // 2. Find the smallest number > nums[gola_index] from the end
            for (int j = n - 1; j > gola_index; j--) {
                if (nums[j] > nums[gola_index]) {
                    swap(nums[gola_index], nums[j]);
                    break;
                }
            }
        }

        // 3. Reverse the suffix
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};
