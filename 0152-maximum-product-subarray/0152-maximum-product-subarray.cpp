class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // initialize with the first element: a subarray must contain at least one element
        int ans = nums[0];        // global best product found so far
        int currMax = nums[0];    // max product of a subarray that ends at the previous index
        int currMin = nums[0];    // min product of a subarray that ends at the previous index

        for (int i = 1; i < n; i++) {
            // If current number is negative, multiplying flips signs:
            // the previous max becomes candidate for new min, and previous min becomes candidate for new max.
            if (nums[i] < 0) swap(currMax, currMin);

            // Either start fresh at nums[i] or extend previous subarray by multiplying
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            // Update global answer
            ans = max(ans, currMax);
        }

        return ans;
    }
};
