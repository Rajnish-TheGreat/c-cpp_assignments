// A C++ program to print union and intersection
/// of two unsorted arrays
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);

// Prints union of arr1[0..m-1] and arr2[0..n-1]
void printUnion(int arr1[], int arr2[], int m, int n)
{
	// Before finding union, make sure arr1[0..m-1]
	// is smaller
	if (m > n)
	{
		int *tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	// Now arr1[] is smaller

	// Sort the first array and print its elements (these two
	// steps can be swapped as order in output is not important)
	sort(arr1, arr1 + m);
	for (int i=0; i<m; i++)
		cout << arr1[i] << " ";

	// Search every element of bigger array in smaller array
	// and print the element if not found
	for (int i=0; i<n; i++)
		if (binarySearch(arr1, 0, m-1, arr2[i]) == -1)
			cout << arr2[i] << " ";
}

// Prints intersection of arr1[0..m-1] and arr2[0..n-1]
void printIntersection(int arr1[], int arr2[], int m, int n)
{
	// Before finding intersection, make sure arr1[0..m-1]
	// is smaller
	if (m > n)
	{
		int *tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	// Now arr1[] is smaller

	// Sort smaller array arr1[0..m-1]
	sort(arr1, arr1 + m);

	// Search every element of bigger array in smaller
	// array and print the element if found
	for (int i=0; i<n; i++)
		if (binarySearch(arr1, 0, m-1, arr2[i]) != -1)
			cout << arr2[i] << " ";
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l)/2;

		// If the element is present at the middle itself
		if (arr[mid] == x) return mid;

		// If element is smaller than mid, then it can only
		// be presen in left subarray
		if (arr[mid] > x)
		return binarySearch(arr, l, mid-1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid+1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

/* Driver program to test above function */
int main()
{
	int arr1[] = {7, 1, 5, 2, 3, 6};
	int arr2[] = {3, 8, 6, 20, 7};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	cout << "Union of two arrays is n";
	printUnion(arr1, arr2, m, n);
	cout << "nIntersection of two arrays is n";
	printIntersection(arr1, arr2, m, n);
	return 0;
}
