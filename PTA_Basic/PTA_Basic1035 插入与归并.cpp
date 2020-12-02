#include <iostream>
#include <algorithm>
using namespace std;

void print(int* a, int N)
{
	int i = 0;
	for (; i < N-1; ++i)
		cout << a[i] << " ";
	cout << a[i];
}
int main()
{
	int N, i = 0, j = 0, k;
	cin >> N;
	int* A = (int*)calloc(N, sizeof(int));
	int* B = (int*)calloc(N, sizeof(int));
	if (nullptr == A || nullptr == B)
		return 0;
	while (i < N)
		cin >> A[i++];
	i = 0;
	while (i < N)
		cin >> B[i++];
	for (k = 0; k < N && B[k] <= B[k + 1]; ++k);
	for (j = k + 1; j < N && A[j] == B[j]; ++j);
	if (j == N)
	{
		cout << "Insertion Sort" << endl;
		sort(B, B + k + 2);
		print(B, N);
	}
	else
	{
		cout << "Merge Sort" << endl;
		int flag = 1, t = 1;
		while (flag)
		{
			flag = 0;
			for (i = 0; i < N; ++i)
				if (A[i] != B[i])
					flag = 1;
			t *= 2;
			for (j = 0; j < N / t; ++j)
				sort(A + j * t, A + (j + 1) * t);
			sort(A + N / t * t, A + N);
		}
		print(A, N);
	}
	return 0;
}