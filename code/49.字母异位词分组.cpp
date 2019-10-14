#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	map<string, vector<string>> yiweici;
    	for(const auto& element : strs){
    		auto _str(element);
    		sort(_str.begin(), _str.end());
    		yiweici[_str].push_back(element);
		}
		vector<vector<string>> res;
		for(const auto& element : yiweici){
			res.push_back(element.second);
		}
		
		return res;
    }
};

int main(){
	Solution solution;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	auto result = solution.groupAnagrams(strs);
	for(const auto& element : result){
		for(const auto& ele : element){
			cout<<ele<<",";
		}
		cout<<endl;
	}
	return 0;
}

