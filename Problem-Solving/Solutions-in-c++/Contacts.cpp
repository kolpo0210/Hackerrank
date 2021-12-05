#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct node {
    node * children[26] = {NULL};
    int count = 0;
};

void addnode (node* root, string name, int cur) {
    root -> count += 1;
    if (cur == name.size()) return;
    if (!root -> children[name[cur] - 'a']) root -> children[name[cur] - 'a'] = new node();
    addnode(root -> children[name[cur]- 'a'], name, cur + 1);
}

int findnode(node * root, string name, int cur) {
    if (cur == name.size()) {
        return root -> count;
    }
    else if (!root -> children[name[cur] - 'a']) {
        return 0;
    }
    else {
        return findnode(root -> children[name[cur] - 'a'], name, cur + 1);
    }
}

int main() {
    int n;
    cin >> n;
    string a, b;
    unordered_set<string> s;
    node * root = new node();
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == "add") {
            if (s.find(b) == s.end()) {
                s.insert(b);
                addnode(root, b, 0);
            }
        }
        else if (a == "find") {
            cout << findnode(root, b, 0) << endl;
        }
    }
    return 0;
}
