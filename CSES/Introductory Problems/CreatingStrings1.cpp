// https://cses.fi/problemset/task/1622

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
class _Permutation {
private:
    vector<char> characters;
    vector<bool> checkSelected;
    vector<string> result;
    set<string> duplicateCheck;
 
    int numResult;
    int length;
public:
    _Permutation() {
        string input;
        cin >> input;
 
        for (auto ch : input) {
            characters.push_back(ch);
        }
        
        std::sort(characters.begin(), characters.end());
        length = input.size();
        checkSelected.assign(length, false);
    }
 
    void search(int n, vector<char>& it) {
        if (n == length) {
            string test(it.begin(), it.end());
            if (duplicateCheck.find(test) == duplicateCheck.end()) {
                duplicateCheck.insert(test);
                result.push_back(test);
            }
            return;
        }
        
        for (int i = 0; i < length; ++i) {
            if (!checkSelected[i]) {
                checkSelected[i] = true;
                it.push_back(characters[i]);
                search(n + 1, it);
                it.pop_back();
                checkSelected[i] = false;
            }
        }
    }
 
    void print() {
        cout << duplicateCheck.size() << endl;
        for (auto s : result) {
            cout << s << endl;
        }
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    _Permutation a;
    vector<char> k;
    a.search(0, k);
    a.print();
    return 0;
}