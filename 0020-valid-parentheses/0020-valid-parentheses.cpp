class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            // If opening bracket, push to stack
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else {
                // If closing bracket but stack empty → invalid
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check correct matching pair
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')){
                    return false;
                }
            }
        }
        // Valid only if stack empty at the end
        return st.empty();
    }
};
