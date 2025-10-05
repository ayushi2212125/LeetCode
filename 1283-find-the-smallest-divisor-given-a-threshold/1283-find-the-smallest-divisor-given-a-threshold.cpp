class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;   // smallest possible divisor
        int end = *max_element(nums.begin(), nums.end()); // largest number in array
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;  // possible divisor
            int sum = 0;

            // calculate sum of ceil(nums[i] / mid)
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // trick to do ceil division
            }

            if (sum <= threshold) {
                ans = mid;        // mid works, try smaller divisor
                end = mid - 1;
            } else {
                start = mid + 1;  // mid too small, sum too big
            }
        }

        return ans;
    }
};
