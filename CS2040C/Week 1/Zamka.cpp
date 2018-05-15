#include <bits/stdc++.h>
using namespace std;

int sum_digits(int num) {
	int sum = 0;
	while(num) {
		sum += num%10;
		num /= 10;
	}
	return sum;
}

int main() {
	int L,D,X,M,N;
	cin >> L >> D >> X;
	for (N = L; N <= D; N++)
		if(sum_digits(N) == X) {
			cout << N << endl;
			break;
		}
	for (M = D; M >= L; M--)
		if(sum_digits(M) == X) {
			cout << M << endl;
			break;
		}
	return 0;
}