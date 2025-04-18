//#include <iostream>
//using namespace std;
//
//int main() {
//    int N; 
//    int grade;
//    int vC = 0; 
//    int total = 0; 
//
//    
//    cout << "Enter the number of students: ";
//    cin >> N;
//
//    
//    while (N <= 0) {
//        cout << "Please enter a valid number of students (greater than 0): ";
//        cin >> N;
//    }
//
//    
//    for (int i = 0; i < N; i++) {
//        cout << "Enter the grade for student " << (i + 1) << ": ";
//        cin >> grade;
//
//        
//        while (grade < 0 || grade > 100) {
//            cout << "Invalid grade. Please enter a grade between 0 and 100: ";
//            cin >> grade;
//        }
//
//        total += grade; 
//        vC++; 
//    }
//
//    
//    float average = 0;
//    if (vC > 0) {
//        average = total / vC; 
//    }
//
//    
//    cout << "Number of valid grades entered: " << vC << endl;
//    cout << "Average grade: " << average << endl;
//
//    return 0;
//}
