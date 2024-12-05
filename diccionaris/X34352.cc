#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> m;
  char codi;
  while(cin >> codi) {
    string s;
    cin >> s;
    if (codi == 'a') {
      m.insert(make_pair(s, 0));
      ++m[s];
    }
    else {
      map<string, int>::iterator it = m.find(s);
      if (it == m.end()) cout << 0 << endl;
      else cout << (*it).second << endl;
    }
  }
}
