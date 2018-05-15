// Tutorial 2

// Note
// Counting sort and radix sort depend on the range of values (0 => m)
// Counting sort: O(N+m)
// Radix sort: O(N*log(m))

// Q1
// Searching for a specific value v in array A
int binarySearch(int a[], int n, int v) {
	return biSearch(a, 0, n-1, v);
}

int biSearch(int a[], int first, int last, int v) {
	int mid = (first + last)/2;
	if (first > last)
		return -1;
	else if (a[mid] < v)
		return biSearch(a, mid+1, last, v);
	else if (a[mid] > v)
		return biSearch(a, first, mid-1, v);
	else 
		return mid;
}

// Finding the min/max/k-th smallest/largest value in (static) array A: a[k-1]
// Counting how many time a specific value v appear in array A
int firstEleSearch(int a[], int n, int v) {
	return fiSearch(a, 0, n-1, v);
}

int fiSearch(int a[], int first, int last, int v) {
	int mid = (first + last)/2;
	if (first > last)
		return -1;
	else if (a[mid]==v && (mid==0 || a[mid-1]<v))
		return mid;
	else if (a[mid] < v)
		return fiSearch(a, mid+1, last, v);
	else 
		return fiSearch(a, first, mid-1, v);
}

int lastEleSearch(int a[], int n, int v) {
	return laSearch(a, 0, n-1, v);
}

int laSearch(int a[], int first, int last, int v) {
	int mid = (first + last)/2;
	if (first > last)
		return -1;
	else if (a[mid]==v && (mid==n-1 || a[mid+1]>v))
		return mid;
	else if (a[mid] > v)
		return laSearch(a, first, mid-1, v);
	else 
		return laSearch(a, mid+1, last, v);
}

int countEle(int a[], int n, int v){
	int first = firstEleSearch(a, n, v);
	int last = lastEleSearch(a, n, v);
	if (first == -1)
		return -1;
	else
		return last - first + 1;
}

// Testing for uniqueness and deleting duplicates in array A
int delDuplicate(int a[], int n, int b[]) {
	int m = 0, i;
	if (n<=0)
		return -1;
	else {
		b[m++] = a[0];
		for (i=1;i<n;i++)
			if (a[i-1] < a[i])
				b[m++] = a[i];
	}
	return m;
}

// Set intersection/union between array A and another sorted array B
int intersect(int a[], int m, int b[], int n, int c[]) {
	int ar[m], br[n], mr, nr, i = 0, j = 0, k = 0;
	mr = delDuplicate(a, m, ar);
	nr = delDuplicate(b, n, br);
	while (i<mr && j<nr) {
		if (ar[i] < br[j]) 
			i++;
		else if (ar[i] > br[j])
			j++;
		else {
			c[k++] = ar[i];
			i++;
			j++;
		}
	}
	return k;
}

int uni(int a[], int m, int b[], int n, int c[]) {
	int ar[m], br[n], mr, nr, i = 0, j = 0, k = 0;
	mr = delDuplicate(a, m, ar);
	nr = delDuplicate(b, n, br);
	while (i<mr && j<nr) {
		if (ar[i] < br[j]) 
			c[k++] = ar[i++];
		else if (ar[i] > br[j])
			c[k++] = br[j++];
		else {
			c[k++] = ar[i];
			i++;
			j++;
		}
	}
	while (i<mr)
		c[k++] = ar[i++];
	while (j<nr)
		c[k++] = br[j++];
	return k;
}

// Finding a target pair x and y from A such that x+y=z: two pointer method
int countSumPair(int a[], int n, int z) {
	int ar[n], nr, i = 0, j = n-1, count = 0;
	nr = delDuplicate(a, n, ar);
	while (i<=j) {
		if (ar[i]+ar[j] < z)
			i++;
		else if (ar[i]+ar[j] > z)
			j--;
		else if (i=j && countEle(a, n, ar[i]) == 1)
			i++;
		else {
			count++;
			i++;
			j++;
		}
	}
}