#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map<string, set<int> > &m, string &str) {//引用时标识符可以修改 
    if(m.find(str) != m.end()) {//该键对应键值对是否存在 
        for(auto it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkey) {//逐个处理一行中各个无空白字符串的方法 
            key[tkey].insert(id);
            char c = getchar();//获取无空白字符串后面的空白字符 
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);//之前读过的"%d: "就不会再读了 
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub, temp);
        else if(num == 5) query(year, temp);
    }
    return 0;
}

//query 查询 
