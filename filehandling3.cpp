#include <iostream>
using namespace std;
int main() {
	int arr[5] = { 7,2,4,9,4 };
	int size = 5;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < size; i++) {
	int max_index = i;
		for (int j = 0; j < size-1; j++) {
			if (arr[j] < arr[j+1]) {
				
				swap(arr[j+1], arr[j]);
			}
			
		}
		
	}
	for (int k = 0; k < size; k++)
		cout << arr[k] << " ";
	cout << endl;
	return 0;
}