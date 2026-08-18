class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        
        int curr = 0;
        int ans = 0; 

        for(int i=0; i<requests.size(); i++){
            ans += abs(curr-requests[i]);
            curr = requests[i];
        }

        return ans;
    }
};