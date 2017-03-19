/*
TinyURL
*/
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
	vector<string> urls;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.push_back(longUrl);
        stringstream ss;
        ss<<(urls.size()-1);
        return "http://tinyurl.com/"+ string(ss.str());
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
    	int pos = shortUrl.find_last_of('/');
    	string sub = shortUrl.substr(pos+1);
        return urls[stoi(sub)];
    }
};
int main()
{
	Solution solution;
	string url = "https://leetcode.com/problems/design-tinyurl";
 	cout<<solution.decode(solution.encode(url))<<endl;
}

