#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; //»À ˝n
	cin >> n;

	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());  //≈≈–Ú
	if (n == 2) {
		cout << a[1] - a[0] << endl;
		return;
	}
	if (n == 3) {
		cout << max(abs(a[2] - a[1]), abs(a[2] - a[0])) << endl;
		return;
	}
	priority_queue<int> q;
	for (int i = 2; i < n; i += 2) {
		q.push(a[i] - a[i - 2]);
	}
	for (int i = 1; i < n; i += 2) {
		q.push(a[i] - a[i - 2]);
	}
	cout << q.top() << endl;
	return 0;
}