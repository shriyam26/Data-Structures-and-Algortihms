/* Find absolute minimume difference pairs in the same array */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int diff = INT_MAX;
        vector<vector<int> > res;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++){
            diff = min(diff, abs(arr[i] - arr[i+1]));
        }
        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i+1]) == diff){
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};

/* Find absolute minimume difference pairs in two unsorted arrays */
class Solution {
public:
    int minimumAbsDifference(vector<int>& arr1, vector<int>& arr2) {
        int diff = INT_MAX;
        vector<vector<int> > res;
        sort(arr1.begin(), arr1.end());
		sort(arr2.begin(), arr2.end());
        while(i < arr1.size() && j < arr2.size()){
			diff = min(diff, abs(arr1[i] - arr2[j]));
			if(arr1[i] < arr2[j]) i++;
			else j++;
		}
        return diff;
    }
};