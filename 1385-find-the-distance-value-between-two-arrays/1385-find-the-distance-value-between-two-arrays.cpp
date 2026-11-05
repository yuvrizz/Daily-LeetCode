// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
//         int count = 0;

//         for(int i=0; i<arr1.size(); i++){
//             for(int j=0; j<arr2.size(); j++){
//                 if(abs(arr1[i]-arr2[j]) <= d){
//                     count++;
//                     break;
//                 }
//             }
//         }

//         return arr1.size()-count;
//     }
// };


// O(nlogn)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int ans = 0; 
        sort(arr2.begin(),arr2.end());

        for(int i=0; i<arr1.size(); i++){
            
            int low = 0;
            int high = arr2.size() - 1;

            bool found = false; 

            while(low <= high){
                int mid = low + (high-low) / 2;

                if(arr2[mid] >= arr1[i]-d && arr2[mid] <= arr1[i]+d){
                    found = true;
                    break;
                }
                else if(arr2[mid] < arr1[i] - d){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            if(!found){
                ans++;
            }
        }

        return ans;
    }
};