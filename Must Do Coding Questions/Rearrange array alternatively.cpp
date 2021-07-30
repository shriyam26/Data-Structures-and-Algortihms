Rearrange max and min values alternatively.
/*
In this to do this in O(1) space, we need to store 2 values at each index, the min/max val plus the value originally at that index.
like in array 1 3 4 5 8 9
we want to store 9 at 0th index in output but here there is 1 at that positon. we can't just replace 1 by 9 as then 1 will bemlost, so to store both values at 0th index, we'll take use of maximum value which we'll assume as arr[n-1] + 1 (10 in this case). Also we'll handle two indexes min and max, min pointing to start of array and max pointing to last of array.
Since we need to store maximum elements at ecen indexes so we'll decrease max index when i%2 = 0, and increment min index when index is odd.
So our array will become something like this 91 13 84 35 58 49
We can see that if we operate each value by modulus of max element (10 in this case) we'll get our original array back 1 3 4 5 8 9
But if we divide each value by max element (10 in this case) we'll get our output array 9 1 8 3 5 4

*/

class Solution{
    public:
    void rearrange(long long *arr, int n) 
    {
        int max_ind = n-1, min_ind = 0;
        int maxVal = arr[n-1] + 1;
        for(int i = 0; i < n ; i++){
            if(i % 2 == 0){
                arr[i] = arr[i] + (arr[max_ind] % maxVal)*maxVal;
                max_ind--;
            }
            else{
                arr[i] = arr[i] + (arr[min_ind] % maxVal)*maxVal;
                min_ind++;
            }
        }
        for(int i = 0; i < n ; i++){
            arr[i] = arr[i]/maxVal;
        }
    }
};