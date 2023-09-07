class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }
        s.clear();

        while (!st.empty()){
            char c = st.top();
            st.pop();
            s.push_back(c);
        }
    }
};