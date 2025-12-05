class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        auto getContribution = [&](bool isMin) {
            long long ans = 0;
            stack<int> st;
            
            for (int i = 0; i <= n; i++) {
                while (!st.empty() && 
                      (i == n || 
                      (isMin ? nums[st.top()] > nums[i] 
                             : nums[st.top()] < nums[i]))) {
                    
                    int mid = st.top(); 
                    st.pop();
                    
                    int left = st.empty() ? mid + 1 : mid - st.top();
                    int right = i - mid;
                    
                    ans += 1LL * nums[mid] * left * right;
                }
                st.push(i);
            }
            return ans;
        };

        long long sumMin = getContribution(true);
        long long sumMax = getContribution(false);

        return sumMax - sumMin;
    }
};
