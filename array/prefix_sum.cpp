#include<iostream>
#include<vector>
#include<math.h>
#include<climits>

using namespace std;

int prefixSum(vector<int>& v) {
	int n = v.size();
	vector<int> vSum;
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += v[i];
		vSum.push_back(sum);
	}
	int maxSum = INT_MIN;

	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			int subArraySum = vSum[j] - vSum[i-1];
			maxSum = max(maxSum, subArraySum);
		}
	}
	return maxSum;
}


int main() {
	vector<int> v = {-2,3,4,-1,5,-12,6,1,3};
	cout << prefixSum(v);
	return 0;
}
