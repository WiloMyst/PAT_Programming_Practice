#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool flag[256] = {false};
    for(int i = 0; i < s2.length(); i++)
        flag[s2[i]] = true;
    for(int i = 0; i < s1.length(); i++) {
        if(!flag[s1[i]])
            printf("%c", s1[i]);
    }
    return 0;
}

//#include <iostream>
//#include <string>
//#include <string.h>
//using namespace std;
//char s1[100000], s2[100000];
//int main() {
//    cin.getline(s1, 100000);
//    cin.getline(s2, 100000);
//    int lens1 = strlen(s1), lens2 = strlen(s2);
//    bool flag[256] = {false};
//    for(int i = 0; i < lens2; i++)
//        flag[s2[i]] = true;
//    for(int i = 0; i < lens1; i++) {
//        if(!flag[s1[i]])
//            printf("%c", s1[i]);
//    }
//    return 0;
//}
