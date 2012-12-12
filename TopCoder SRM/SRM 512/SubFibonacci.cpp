/**
 * @file SubFibonacci.cpp
 * @Synopsis DP+枚举，利用状态转移，从O(N^5)优化到O(N^4)
 * @author Yuanmng Erik Yu
 * @version 1.0
 * @date 2011-07-20
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

#define REP(i, n) for (int i(0), _n(n); i!=_n; ++i)
#define CL(v, x) memset(v, x, sizeof(v))
#define SZ(v) (int)(v).size()

typedef long long ll;

vector<int> S;
int F[60][60];
ll A[60], B[60];

int func(ll a, ll b, int i, int j) {
	ll c = a + b;
	int ret = 0;
	while (i <= j) {
		if (c == S[i]) ++ret;
		if (c < S[i]) {
			a = b;
			b = c;
			c = a + b;
		}
		else ++i;
	}
	return ret;
}

int dp(int i, int j) {
	if (j-i+1<=2) return j-i+1;
	
	int &ret = F[i][j];
	if (ret != -1) return ret;
	ret = 2;
	
	ret = max(ret, dp(i+1, j));
	ret = max(ret, dp(i, j-1));
	
	for (int k=1; k<60; ++k) if (S[j] >= A[k]){
		ll delta = S[j] - A[k] * S[i];
		if (delta < 0) break;
		
		if (delta % B[k] == 0) {
			ll x = delta / B[k];
			
			int tmp;
			if (x - S[i] > 0) tmp = func(x - S[i], S[i], i+1, j-1) + 2;
			else tmp = func(S[i], x, i+1, j-1) + 2;
			
			if (tmp > ret) ret = tmp;
		}
	}
	
	return ret;
}

class SubFibonacci {
public:
	int maxElements(vector <int> _S) {
		S = _S;
		sort(S.begin(), S.end());
		int N = SZ(S);
		CL(A, 0), CL(B, 0);
		A[0] = 1, B[1] = 1;
		for (int i=2; i<60; ++i) {
			A[i] = A[i-1] + A[i-2];
			B[i] = B[i-1] + B[i-2];
		}
		
		CL(F, -1);
		int ret = dp(0, N-1);
		for (int k=0; k<N-1; ++k) {
			int tmp = dp(0, k);
			tmp += dp(k+1, N-1);
			if (tmp > ret) ret = tmp;
		}
		
		return ret;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	SubFibonacci *obj;
	int answer;
	obj = new SubFibonacci();
	clock_t startTime = clock();
	answer = obj->maxElements(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {8,1,20,3,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {19,47,50,58,77,99};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {512};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {3,5,7,10,13,15,20,90};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,2,3,5,8,13,21,34,55,89};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {10, 14, 20, 100, 101, 201};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!