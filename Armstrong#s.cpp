//#include <iostream>
//using namespace std;
//
//int main() {
//    int N;
//
//   
//    cout << "Enter the upper limit: ";
//    cin >> N;
//
//    cout << "Armstrong numbers between 100 and " << N << " are: ";
//
//    
//    for (int num = 101; num <= N; ++num) {
//        int s = 0;           
//        int t = num;        
//        int numD = 0;     
//
//        int tempC = num;
//        while (tempC > 0) {
//            tempC /= 10;
//            numD++;
//        }
//
//        
//        t = num;
//        while (t > 0) {
//            int digit;
//            digit= t % 10;
//
//            
//            int power = 1;
//            for (int i = 0; i < numD; i++) {
//                power *= digit;  
//            }
//
//            s += power;  
//            t /= 10;    
//        }
//        if (s == num) {
//            cout << num << " ";  
//        }
//    }
//
//    cout << endl;
//    return 0;
//}
