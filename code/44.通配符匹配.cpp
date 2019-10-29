#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
    	const auto m = s.size();
    	const auto n = p.size();
    	
    	vector<vector<bool>> f(m+1);
    	for_each(f.begin(), f.end(), [n](vector<bool>& ele){
    		ele = vector<bool>(n+1);
		});
		
		f[0][0] = true;
		for(size_t i = 1; i <=n; i++){
			f[0][i] = f[0][i-1] && p[i-1]=='*';
		}
		
		for(size_t i = 1; i<=m;i++){
			for(size_t j = 1; j<=n; j++){
				if(s[i-1] == p[j-1] || p[j-1]=='?') f[i][j] = f[i-1][j-1];
				if(p[j-1]=='*') f[i][j] = f[i][j-1] || f[i-1][j];
			}
		}
		return f[m][n];
        
    }
};

int main(){
	string s = "adceb", p = "*a*b";
	Solution solution;
	auto result = solution.isMatch(s, p);
	cout<<result<<endl;
	return 0;
}

