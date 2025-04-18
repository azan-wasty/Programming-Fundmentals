//#include <iostream>
//#include <string.h>  
//using namespace std;
//
//bool findword(char s1[], char word[]) {
//    int len_s1 = strlen(s1);
//    int len_word = strlen(word);
//
//    for (int i = 0; i <= len_s1 - len_word; i++) {
//        int f = 1;  
//        for (int j = 0; j < len_word && f == 1; j++) {
//            if (s1[i + j] != word[j]) {
//                f = 0;  
//            }
//        }
//        if (f == 1) return f;  
//    }
//    return 0;  
//}
//
//int main() {
//    const int a = 100;
//    char para[a];
//    char word[a];
//
//    cout << "Enter the word you want to find: ";
//    cin >> word;
//    cin.ignore();
//
//    cout << "Enter the passage: ";
//    cin.getline(para, a);
//
//    int result = findword(para, word);
//    cout << result;
//
//    return 0;
//}
