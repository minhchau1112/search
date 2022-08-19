#include<iostream>
using namespace std;

int LinearSearch(int a[], int n, int key);
int BinarySearch(int a[], int n, int key);
int Recursive_BinarySearching(int a[], int l, int r, int key);

int LinearSearch(int a[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key)return i;
	}
	return -1;
}

//sử dụng với mảng đã được sắp xếp
int BinarySearch(int a[], int n, int key) {
	int l = 0, r = n - 1, mid;
	do {
		mid = (l + r) / 2;
		if (a[mid] == key)return mid;
		else if (a[mid] > key)r = mid - 1;
		else l = mid + 1;
	} while (l <= r);
	return -1;
}

int Recursive_BinarySearching(int a[], int l, int r, int key) {
	if (l > r)return -1;
	int mid = (l + r) / 2;
	if (a[mid] == key)return mid;
	else if (a[mid] > key)return Recursive_BinarySearching(a, l, mid - 1, key);
	else return Recursive_BinarySearching(a, mid + 1, r, key);
}

int main() {
	int a[20] = { 23,45,101,68,95,74,54,12,8,1,33,121,145,88,132,99,19,188,200,64 };
	int b[20] = { 2,4,6,7,11,13,15,16,18,21,22,24,33,45,48,54,55,67,69,81 };
	int x;
	cout << "Enter x : ";
	cin >> x;
	if (LinearSearch(a, 20, x) != -1) {
		cout << x << " is found!" << endl;
	}
	else {
		cout << x << " isn't found!" << endl;
	}
	cout << "Enter x : ";
	cin >> x;
	if (BinarySearch(a, 20, x) != -1) {
		cout << x << " is found!" << endl;
	}
	else {
		cout << x << " isn't found!" << endl;
	}
	cout << "Enter x : ";
	cin >> x;
	if (Recursive_BinarySearching(a,0, 19, x) != -1) {
		cout << x << " is found!" << endl;
	}
	else {
		cout << x << " isn't found!" << endl;
	}
	return 0;
}