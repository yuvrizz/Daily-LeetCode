class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        unordered_set <string> st;
        int count = 0;

        for(int i=0; i<words.size(); i++){

            if(st.count(words[i])){
                count++;
            }

            string rev = words[i];
            reverse(rev.begin(), rev.end());
            st.insert(rev);
        }

        return count;
    }
};