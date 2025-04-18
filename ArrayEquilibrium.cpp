//#include <iostream>
//using namespace std;
//
//int findEquilibrium(int d[], int size) {
//    
//    for (int n = 1; n < size; n++) {
//        int sum1 = 0, sum2 = 0;
//
//        
//        for (int i = 0; i < n; i++) {
//            sum1 += d[i];
//        }
//
//        
//        for (int i = n + 1; i < size; i++) {
//            sum2 += d[i];
//        }
//
//        
//        if (sum1 == sum2) {
//            return n;
//        }
//    }
//
//    
//    return -1;
//}
//
//int main() {
//    const int s = 100; // Program will only work for arrays smaller than 100 size. 
//    int data[s]; 
//    int size;
//
//    cout << "What is the size of the array?" << endl;
//    cin >> size;
//
//    if (size <= 0 || size > s) {
//        cout << "Invalid size!" << endl;
//        return 1;
//    }
//
//    for (int j = 0; j < size; j++) {
//        cout << "Enter index " << j << ": ";
//        cin >> data[j];
//    }
//
//    int result = findEquilibrium(data, size);
//    if (result == -1) {
//        cout << "No equilibrium index found." << endl;
//    }
//    else {
//        cout << "Equilibrium index is: " << result << endl;
//    }
//
//    return 0;
//}
