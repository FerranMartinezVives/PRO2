#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> m;
  char codi;
  while (cin >> codi) {
    string s;
    cin >> s;
    if (codi == 'a') {
      map<string, int>::iterator it = m.find(s);
      if (it == m.end()) {
        pair<string, int> p;
        p.first = s;
        p.second = 1;
        m.insert(p);
      }
      else ++(*it).second;
    }
    else if (codi == 'e') {
      map<string, int>::iterator it = m.find(s);
      if (it != m.end() and (*it).second != 0) --(*it).second;
    }
    else {
      map<string, int>::iterator it = m.find(s);
      if (it == m.end()) cout << 0 << endl;
      else cout << (*it).second << endl;
    }
  }
}
