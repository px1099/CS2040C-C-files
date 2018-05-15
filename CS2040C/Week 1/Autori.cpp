// Autori
#include <bits/stdc++.h>

int main() {
	char c;
	scanf("%c",&c);
	printf("%c",c);
	while((scanf("%c",&c)) != EOF) {
		if (c == '-') {
			scanf("%c",&c);
			printf("%c",c);
		}
	}
	printf("\n");
	return 0;
}