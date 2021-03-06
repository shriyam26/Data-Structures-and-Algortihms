#include<bits/stdc++.h>

using namespace std;

int median(int arr[], int n){
    if(n%2 == 0){
        return (arr[n/2] + arr[n/2 - 1])/2;
    }
    return arr[n/2];
}

int getMedian(int arr1[],
              int arr2[], int n){
    if(n <= 0) return -1;
    if(n == 1) return (arr1[0] + arr2[0])/2;
    if(n == 2) return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
    int m1 = median(arr1, n);
    int m2 = median(arr2, n);
    if(m1 == m2) return m1;
    else if(m1 < m2){
        if(n%2 == 0) return getMedian(arr1 + n/2 - 1, arr2, n-n/2 + 1);
        return getMedian(arr1 + n/2, arr2, n - n/2);
    }
    else{
        if(n%2 == 0) return getMedian(arr1, arr2 + n/2 -1, n-n/2 + 1);
        return getMedian(arr1, arr2 + n/2, n - n/2);
    }
}
 
// Driver Code
int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1) ;
    else
        cout << "Doesn't work for arrays"
             << " of unequal size" ;
    getchar();
    return 0;
}
 
// This code is contributed
// by Shivi_Aggarwal