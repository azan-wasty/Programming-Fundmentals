//#include <iostream>
//using namespace std;
//
//int main() {
//    int bal = 0, with, dep, res = 0;
//
//    while (res != -1) {
//
//        cout << "Welcome to the menu. Enter an option:\n";
//        cout << "1 to Deposit\n2 to Withdraw\n-1 to Exit with a message: ";
//        cin >> res;
//
//
//        if (res == 1) {
//            cout << "Enter the amount you want to deposit:\n";
//            cin >> dep;
//            bal += dep;
//            cout << "Your new balance is " << bal << endl;
//        }
//
//        else if (res == 2) {
//            cout << "Enter the amount you want to withdraw:\n";
//            cin >> with;
//            if (bal >= with) {
//                bal -= with;
//                cout << "Your new balance is " << bal << endl;
//            }
//            else {
//                cout << "Insufficient balance. Press -1 to exit or 1 to deposit funds.\n";
//                cin >> res;
//
//                if (res == 1) {
//                    cout << "Enter the amount you want to deposit:\n";
//                    cin >> dep;
//                    bal += dep;
//                    cout << "Your new balance is " << bal << endl;
//                }
//            }
//        }
//
//
//
//        else if (res == -1) {
//            cout << "Exiting the program. Thank you!\n";
//        }
//        else {
//            cout << "Invalid option. Please try again.\n";
//        }
//    }
//
//    return 0;
//}
