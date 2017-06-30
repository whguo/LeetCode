/*
二进制手表。用4个二进制灯表示0-11小时，6个灯表示0-59分钟。
给出正整数n表示当前亮的灯的个数。返回所有可能的时间。
例如，给出1，返回["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/
/*
思路：1.把亮灯个数对应的数全都列举出来。
	  2.遍历所有时间点，判断小时和分钟的二进制位加起来是否为给出的数。
	  3.回溯法。
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		//二进制位有0个1的是0，有1个1的是1,2,4,8...
        vector<vector<string>> hour{{"0"},{"1","2","4","8"},{"3","5","6","9","10"},{"7","11"}};
        vector<vector<string>> minute{{"00"},{"01","02","04","08","16","32"},
    								  {"03","05","06","09","10","12","17","18","20","24","33","34","36","40","48"},
    								  {"07","11","13","14","19","21","22","25","26","28","35","37","38","41","42","44","49","50","52","56"},
    								  {"15","23","27","29","30","39","43","45","46","51","53","54","57","58"},
    								  {"31", "47", "55", "59"}};
  		vector<string> result;
  		for(int i=0; i < 4 && i <= num; ++i)
  		{
  			if(num-i <=5)
  			{
  				for(string h:hour[i])
  					for(string m:minute[num-i])
  						result.push_back(h+":"+m);
  			}
  		}
  		return result;
    }
};
int main()
{
	Solution s;
	vector<string> out = s.readBinaryWatch(1);
	for(string s:out)
		cout<<s<<endl;
}

