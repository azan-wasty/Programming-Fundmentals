//#include <iostream>
//using namespace std;
//
//int counter(int d[], int size, int key) {
//    int count = 0;
//    for (int i = 0; i < size; i++) {
//        if (d[i] == key) {
//            count += 1;
//        }
//    }
//    return count;
//}
//
//int main() {
//    const int s = 100;
//    int k, size;
//    int data[s];
//
//    do {
//        cout << "What is the size of the array: ";
//        cin >> size;
//        if (size > s || size < 0) {
//            cout << "Enter a valid size.\n";
//        }
//    } while (size > s || size < 0);
//
//    cout << "What is the key: ";
//    cin >> k;
//
//    for (int j = 0; j < size; j++) {
//        cout << "Enter the element at index " << j << ": ";
//        cin >> data[j];
//    }
//
//    int result = counter(data, size, k);
//    if (result == 0) {
//        cout << "Key found 0 times\n";
//    }
//    else {
//        cout << "Key found " << result << " times\n";
//    }
//
//    return 0;
//}
