// PS1D
#include <iostream>
using namespace std;

int main() {
	int TC, n, val, index, two, left, right, ans = 0;
	int a[3] = {0};
	scanf("%d %d", &TC, &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &val);
		++(a[val-1]);
		index = i/2;
		two = a[0] + a[1];
		if (index < a[0])
			left = 1;
		else if (index < two)
			left = 2;
		else
			left = 3;
		++index;
		if (index < a[0])
			right = 1;
		else if (index < two)
			right = 2;
		else
			right = 3;
		if (i%2 == 0)
			ans += left;
		else
			ans += (left + right)/2;
	}
	printf("%d\n", ans);
	printf("By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n");
	return 0;
}	
