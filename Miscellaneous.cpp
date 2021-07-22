https://leetcode.com/discuss/interview-experience/1242231/Rejections-to-Multiple-Offers-Journey-or-Experience-or-Advice

Reverse a Stack
Vertical order traversal
Boundary Traversal of binary tree

Structure vs Union

1. Memory allocated is shared by every member of union, whereas in structure, each member has a different location.
2. In union memory is allocated according to the member whose memory requirement is highest, whereas in strcture each member has its own memory location.
3. In union only one member can be accessed at a time.


/* Sort 0s, 1s and 2s */

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0;
        while(mid <= high){
            switch(arr[mid]){
                case 0:
                    swap(arr[mid], arr[low]);
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[mid], arr[high]);
                    high--;
                    break;
            }
        }
    }
};

/*Check if Kth Bit is set or not*/

int n;
bool ret = (1 << (k-1)) & n


/* Power of 2 */

if( n <= 0) return false;
return (!n & (n-1));

/* Swap Bits */

unsigned int even_bits = x & 0xAAAAAAAA;
 
    // Get all odd bits of x
unsigned int odd_bits  = x & 0x55555555;
 
even_bits >>= 1;  // Right shift even bits
odd_bits <<= 1;   // Left shift odd bits
 
return (even_bits | odd_bits); // Combine even and odd bits


/* Reverse Bits */

unsigned int rev = 0;
     
    // traversing bits of 'n' from the right
    while (n > 0)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;
         
        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;
         
        // bitwise right shift
        // 'n' by 1
        n >>= 1;
             
    }
	
	
	
malloc dynamically allocates a single large block of memory with specified size. It returns a pointer of type void which can be cast in any type. Also pointer stores the inital address of memory. (int*)malloc(5*sizeof(int));
calloc also dynamically allocates memory but it allocates in a multiple blocks of specified size and default value of each block is set to 0.
It has 2 parameters (int*)calloc(5, sizeof(int));
realloc just reallocated dynamic memroy if memory was insufficient. ptr = realloc(ptr, new size);