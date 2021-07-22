
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)
            return dividend;
        if(dividend == INT_MIN && abs(divisor) == 1)
            return INT_MAX;
        long long quotient = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long dd = abs((long long)dividend);
        long long ds = abs((long long)divisor);
        long long a, m;
        while(dd >= ds){
            a = ds; // a is equivalent to sum in below solution.
            m = 1;  // m is equivalen to multiple in below solution.
            while((a << 1) < dd){ //We are calculating what is the maximum value can we take away from dividend and in how many iterations it will be obtained.
                a = a << 1;
                m = m << 1;
            }
            quotient += m; 
            dd -= a; //Then subtract that maximum value from dividend and again check for same value.
        }
        return sign*quotient;
    }
};

Time complexity = O(logN^2);
/*
class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        if (dividend < divisor)
            return 0;
        
        long long sum = divisor;
        long long multiple = 1; // 1 2 4 8 16 32 64...
        while ((sum + sum) <= dividend) {
            sum += sum;
            multiple += multiple;
        }
        
        return multiple + divide(dividend - sum, divisor);
    }
}
*/


Multiply without using * operator

unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0; // initialize result
 
    // While second number doesn't become 1
    while (b > 0)
    {
        // If second number becomes odd, add the first number to result
        if (b & 1)
            res = res + a;
 
        // Double the first number and halve the second number
        a = a << 1;
        b = b >> 1;
		
    }
    return res;
}

The value of a*b is same as (a*2)*(b/2) if b is even, otherwise the value is same as ((a*2)*(b/2) + a). 
In the while loop, we keep multiplying ‘a’ with 2 and keep dividing ‘b’ by 2. 
If ‘b’ becomes odd in loop, we add ‘a’ to ‘res’. 
When value of ‘b’ becomes 1, the value of ‘res’ + ‘a’, gives us the result. 


Sum without using + operator

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        
        return sum;
    }
};


