// Recursive approach - TC (2^n), might TLE for bigger n.

// class Solution {
// public:
//     int climbStairs(int n) {
        
//         if(n == 0 || n == 1){
//             return 1;
//         }

//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// }; 


// optimized using Memoization
class Solution {
public:

    int helper(int n, vector<int> &vec){

        if( n == 0 || n == 1){
            return 1;
        }

        if(vec[n] != -1){
            return vec[n];
        }
        else{
            vec[n] = helper(n-1,vec) + helper(n-2,vec);
        }

        return vec[n];
    }

    int climbStairs(int n) {

        vector <int> vec(n+1,-1);

        return helper(n,vec);
    }
};