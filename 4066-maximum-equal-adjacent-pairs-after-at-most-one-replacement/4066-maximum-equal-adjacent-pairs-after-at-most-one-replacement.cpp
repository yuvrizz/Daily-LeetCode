class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        int ans = 0;
        int bestpair = 0;

        map<pair<int,int>,int> mp;

        for(int i=1; i<nums.size(); i++){

            int a = nums[i-1];
            int b = nums[i];

            if(a == b){
                ans++;
            }
            else{
                if(a>b){
                    swap(a,b);
                }
                mp[{a,b}]++;

                bestpair = max(bestpair,mp[{a,b}]);
            }
        }

        return ans + bestpair;
    }
};