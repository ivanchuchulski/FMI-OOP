/* Matrix representation
	a00		a01		a02		a03		a04
	a10		a11		a12		a13		a14
	a20		a21		a22		a23		a24
	a30		a31		a32		a33		a34
	a40		a41		a42		a43		a44
											5x5

*/

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void printMatrix(int *pArr, int n) 
{
	cout << "Your matrix: \n";

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << setw(4) << pArr[i * n + j];
		}

		cout << '\n';
	}
	cout << endl;
}

void primaryDiagonal(int *pArr, int n) 
{
	cout << "Elements on the primary diagonal : " << endl;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (i == j)
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

void underPrimaryDiagonal(int *pArr, int n)
{
	cout << "Elements under the primary diagonal : \n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

void overPrimaryDiagonal(int *pArr, int n)
{
	cout << "Elements over the primary diagonal : \n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

void secondaryDiagonal (int *pArr, int n) 
{
	cout << "Elements on the secondary diagonal : \n";

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if ((i + j) == (n - 1))
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

void underSecondaryDiagonal(int *pArr, int n) 
{
	cout << "Elements under the secondary diagonal : \n";

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j > n -1)
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

void overSecondaryDiagonal(int *pArr, int n)
{
	cout << "Elements over the secondary diagonal : \n";

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (i + j < n - 1) 
				cout << "a[" << i << "][" << j << "]=" << pArr[i * n + j] << endl;
		}
	}
	cout << endl;
}

int main() {

	int a[5][5] = {	{1, 2, 3, 4, 5},
					{6, 7, 8, 9, 10},
					{11, 12, 13, 14, 15},
					{16, 17, 18, 19, 20},
					{21, 22, 23, 24, 25} };
	int sizeA = (sizeof(a[0]) / sizeof(int));

	int b[3][3] = { {1, 2, 3},
					{4, 5, 6},
					{7, 8, 9} };
	const size_t sizeB = 3;

	//printMatrix((int*)a, sizeA);

	//primaryDiagonal((int*)a, sizeA);

	//secondaryDiagonal((int*)a, sizeA);

	//underSecondaryDiagonal((int*)a, sizeA);

	//overSecondaryDiagonal((int*)a, sizeA);

	printMatrix((int*)b, sizeB);

	primaryDiagonal((int*)b, sizeB);

	secondaryDiagonal((int*)b, sizeB);

	underPrimaryDiagonal((int*)b, sizeB);

	overPrimaryDiagonal((int*)b, sizeB);

	underSecondaryDiagonal((int*)b, sizeB);

	overSecondaryDiagonal((int*)b, sizeB);


	system("pause");
	return 0;
}