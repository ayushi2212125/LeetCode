class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;

        for(int num: arr){
            freq[num]++;
        }
        unordered_set<int>uniqueFreq;
        for(auto &entry:freq){
            uniqueFreq.insert(entry.second);
        }
        return freq.size() == uniqueFreq.size();
    }
};