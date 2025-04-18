//#include <iostream>
//using namespace std;
//
//int main() {
//    float ed;
//    int sr, cr, al;
//
//    do {
//        cout << "Enter 0 if customer has no criminal record and 1 if he does have a criminal record: ";
//        cin >> cr;
//    } while (cr != 0 && cr != 1);
//
//    if (cr == 1) {
//        cout << "Customer ineligible for loan.\n";
//    }
//    else if (cr == 0) {
//        cout << "What is the customer's salary: ";
//        cin >> sr;
//
//        if (sr > 100000) {
//            cout << "Customer eligible for loan.\n";
//        }
//        else if (sr >= 70000 && sr <= 100000) {
//            do {
//                cout << "Enter the customer's employment duration (in years): ";
//                cin >> ed;
//                if (ed < 0) {
//                    cout << "Enter valid employment duration.\n";
//                }
//            } while (ed < 0);
//
//            if (ed > 1) {
//                cout << "Customer eligible for loan.\n";
//            }
//            else {
//                cout << "Customer ineligible for loan.\n";
//            }
//        }
//        else if (sr >= 50000 && sr < 70000) {
//            do {
//                cout << "Enter the customer's employment duration (in years): ";
//                cin >> ed;
//                if (ed < 0) {
//                    cout << "Enter valid employment duration.\n";
//                }
//            } while (ed < 0);
//
//            if (ed > 3) {
//                cout << "Customer eligible for loan.\n";
//            }
//            else {
//                cout << "Customer ineligible for loan.\n";
//            }
//        }
//        else if (sr >= 20000 && sr < 50000) {
//            do {
//                cout << "Enter the customer's employment duration (in years): ";
//                cin >> ed;
//                if (ed < 0) {
//                    cout << "Enter valid employment duration.\n";
//                }
//                cout << "Enter the customer's age: ";
//                cin >> al;
//                if (al < 0) {
//                    cout << "Enter valid age.\n";
//                }
//            } while (ed < 0 || al < 0);
//
//            if (ed > 5 && al < 30) {
//                cout << "Customer eligible for loan.\n";
//            }
//            else {
//                cout << "Customer ineligible for loan.\n";
//            }
//        }
//        else if (sr < 20000) {
//            cout << "Customer ineligible for loan.\n";
//        }
//    }
//
//    return 0;
//}
