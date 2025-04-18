#include <iostream>
using namespace std;

int main(){
    int x;
    int y;
    cout << "What is the speed of the car\n";
    cin >> x;
    cout << "Enter 1 if it's your birthday and 0 otherwise ?\n";
    cin >> y;
    if ((x<=60 && y==0)||(x<=65 && y==1)){
        cout << "0";
}
    else if((x>=61&& x<=80 && y==0)||(x>=66 && x<=85 && y==1)){
        cout << "1";
}
    else if((x>=81 && y==0)||(x>=86 && y==1)){
        cout<< "2";
}
    return 0;
}