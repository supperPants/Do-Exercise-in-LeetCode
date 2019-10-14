#include<iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
    	if(n == 0) return 1;
    	auto res = track_back(x, n);
    	if(n < 0)
    		return 1/res;
    	return res;
    }
private:
    double track_back(double x, int n){
    	if(n == 0) return 1;
    	
    	auto half_res = track_back(x, n/2);
    	if(n % 2 == 0){
    		return half_res * half_res;
		}
		else return half_res * half_res * x;
	}
};

int main(){
	Solution solution;
	double x = 2.000;
	int n = -2;
	auto result = solution.myPow(x, n);
	cout<<result<<endl;
	return 0;
}

