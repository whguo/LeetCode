/*
HappyNumber，给一个多位数，循环做每位数平方相加，能得到结果1，则是happynumber。
*/
/*
思路：需要升级一下函数参数到64位，否则某些边缘数无法正确求解。
用map记录被除数，出现重复则加括号。
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int64_t numerator, int64_t denominator) {
		if(numerator==0)	return 0;
		string result="";
		if(numerator<0 ^ denominator<0)	result+="-";
		numerator = fabs(numerator),denominator = fabs(denominator);
        
        result += to_string(numerator/denominator);
        if(numerator%denominator==0)	return result;
		result += ".";

		numerator = numerator%denominator;
        unordered_map<int,int>	mymap;
        while(numerator!=0)
        {
        	if(mymap.count(numerator)>0)
        	{
        		//用Map记录的是被除数，不要记录得数是否循环。
        		result.insert(mymap[numerator],1,'(');
        		result += ")";
        		break;
        	}
        	mymap[numerator] = result.size();
        	numerator *= 10;
        	result += to_string(numerator/denominator);
        	numerator %= denominator;
        }

        return result;
    }
};

int main()
{
	Solution s;
	cout<<s.fractionToDecimal(-10,333)<<endl;
}

