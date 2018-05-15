#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, max, min, num, i, x=1;
	while ((scanf("%d",&n)) != EOF) {
		cin >> max;
		min = max;
		for (i=1; i<n; i++) {
			cin >> num;
			if (num > max)
				max = num;
			if (num < min)
				min = num;
		}
		cout << "Case " << x << ": " << min << " " << max << " " << max-min << endl;
		x += 1;
	}
	return 0;
}
