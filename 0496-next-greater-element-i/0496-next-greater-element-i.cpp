#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        // Traverse nums2 left -> right
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        // Remaining elements have no next greater
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) ans.push_back(mp[x]);
        return ans;
    }
};
