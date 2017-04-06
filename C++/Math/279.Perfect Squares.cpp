/*
给一个数，返回它最少是几个数的平方和
例如：12=4+4+4，返回3,13=4+9返回2
*/
/*
思路：四平方和定理：任意一个正整数均可表示为4个以内整数的平方和。
 */
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
public:
	int numSquares(int n) {
		if(is_square(n)) 
        {
            return 1;  
        }
		
		// The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
            n >>= 2;  
        if ((n & 7) == 7) // n%8 == 7
            return 4;
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;
    }
};
int main()
{
	Solution s;
	cout<<s.numSquares(180)<<endl;
}

