/**
 * @file MysteriousRestaurant.cpp
 * @Synopsis  枚举天数，然后模拟. 看理解和代码熟练程度
 * @author Yuanming Yu
 * @version 1.0
 * @date 2011-07-14
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i(0), _n(n); i<_n; ++i)
#define CL(A, x) memset(A, x, sizeof(A))
#define SZ(A) ((int) A.size())
#define DB(x) cout << #x << " = " << x << endl;

class MysteriousRestaurant {
public:
	int func(char ch) {
		if (('0' <= ch) && (ch <= '9')) return ch - '0';
		if (('A' <= ch) && (ch <= 'Z')) return ch - 'A' + 10;
		return ch - 'a' + 36;
	}

    int maxDays( vector <string> prices, int budget ) {
		int good[200];

		for (int day = SZ(prices); day >= 1; --day) {
			int sum = 0;

			for (int cur=0; (cur<7) && (cur + 1 <= day); ++cur) {
				CL(good, 0);

				REP(i, day) if (i%7 == cur) {
					REP(j, SZ(prices[i])) good[j] += func(prices[i][j]);
				}

				int min_cost = good[0];
				REP(j, SZ(prices[0])) min_cost = min(min_cost, good[j]);
				sum += min_cost;
			}
			
			if (sum <= budget) return day;
		}
		return 0;
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
			int budget                = 13;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
			int budget                = 20;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string prices[]           = {"SRM", "512"};
			int budget                = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
			int budget                = 256;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
