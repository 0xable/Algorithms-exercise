// https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
	// 24 ms
	// 7.8 MB
	int nthUglyNumber(int n) {
		vector<int> table(n + 1);
		table[1] = 1;

		int f2 = 1;
		int f3 = 1;
		int f5 = 1;
		for (int i = 2; i <= n; ++i) {
			table[i] = std::min({table[f2] * 2, table[f3] * 3, table[f5] * 5});

			if (table[i] == table[f2] * 2) ++f2;
			if (table[i] == table[f3] * 3) ++f3;
			if (table[i] == table[f5] * 5) ++f5;
		}
		return table[n];
	}
	
	// 992 ms
	// 32.2 MB
	int nthUglyNumber_(int n) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		set<int> check;
		pq.push(1);
		
		--n;
		while (n--) {
			long long curr = pq.top();
			pq.pop();

			if (!check.count(curr * 2)) {
				pq.push(curr * 2);
				check.insert(curr * 2);
			}
			if (!check.count(curr * 3)) {
				pq.push(curr * 3);
				check.insert(curr * 3);
			}
			if (!check.count(curr * 5)) {
				pq.push(curr * 5);
				check.insert(curr * 5);
			}
		}
		
		return pq.top();
	}
};