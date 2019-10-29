#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    	auto const n = nums.size();
    	size_t res = 0, i = 0;
    	while(i < n-1){
    		if(i+nums[i]>= n-1){
    			res++;
    			break;
			}
			
    		auto max = nums[i+1]+i+1;
			auto max_i = i+1;
    		for(auto j = i+1; j <= i+nums[i]&&j<nums.size(); j++){
    			if((nums[j]+j) > max){
    				max = nums[j]+j;
    				max_i = j;
				}
			}
			i = max_i;
    		res++;
		}
		return res;
        
    }
};

int main(){
	vector<int> nums = {2,1};
	Solution solution;
	auto result = solution.jump(nums);
	cout<<result<<endl;
	return 0;
}

