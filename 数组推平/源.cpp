#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long>pre(n + 1, 0);
	vector<long long>sorted(a);
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < n; i++) {         //¼ÆËãÇ°×ººÍ
		pre[i + 1] = pre[i] + sorted[i];
	}

	vector<long long>result(n);
	for (int i = 0; i < n; i++) {
		long long left = (i * sorted[i]) - pre[i];
		long long right = (pre[n] - pre[i + 1]) - ((n - 1 - i) * sorted[i]);
		result[i] = left + right;
	}
	for (auto s : a) {
		int pos = lower_bound(sorted.begin(), sorted.end(), s) - sorted.begin();
		cout << result[pos] << "\n";
	}

	return 0;
}