Approach: The idea is to traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element.

int maxWater(int arr[], int n) 
{
    
    // To store the maximum water 
    // that can be stored
    int res = 0;
    
    // For every element of the array
    for (int i = 1; i < n-1; i++) {
        
        // Find the maximum element on its left
        int left = arr[i];
        for (int j=0; j<i; j++)
           left = max(left, arr[j]);
        
        // Find the maximum element on its right   
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]); 
       
       // Update the maximum water    
       res = res + (min(left, right) - arr[i]);   
    }
}

/*
Time complexity : O(n^2)
Space complexity : O(1)
*/

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];

    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];

    // Initialize result
    int water = 0;

    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

int trappingWater(int arr[], int n){
        int l = 0, h = n-1;
        int lmax = 0, rmax = 0, result = 0;
        while(l <= h){
            if(arr[l] < arr[h]){
                if(arr[l] > lmax) lmax = arr[l];
                else result += lmax - arr[l];
                l++;
            }
            else{
                if(arr[h] > rmax) rmax = arr[h];
                else result += rmax - arr[h];
                h--;
            }
        }
        return result;
    }
}

/*
Time complexity : O(n)
Space complexity : O(1)
*/