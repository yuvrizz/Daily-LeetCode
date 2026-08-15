class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.size(); 
        int ptr = 0; 
        int result = 0;
        unordered_map<char,int> freq;

        for(int i=0; i<n; i++){
            freq[s[i]]++;

            while(freq[s[i]] > 2){
                freq[s[ptr]]--;
                ptr++;
            }

            result = max(result, i-ptr+1);
        }

        return result;
    }
};