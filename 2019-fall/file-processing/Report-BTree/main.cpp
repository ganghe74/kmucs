#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

enum FLAG {LEFT, RIGHT, MERGE};

class BTreeNode {
public:
    BTreeNode(int key) {
        keys.push_back(key);
        childs.assign(2, nullptr);
        n = 1;
    }
    BTreeNode(const BTreeNode *node) : n(node->n), keys(node->keys), childs(node->childs) {}
    ~BTreeNode() {
        for (auto child : childs) delete child;
    }
    void insertKey(int newKey, BTreeNode *newChild=nullptr, int newChildPos=RIGHT) {
        keys.push_back(newKey);
        childs.push_back(newChild);
        int i = ++n - 1;
        while (i > 0 && keys[i] < keys[i-1]) {
            swap(keys[i], keys[i-1]);
            swap(childs[i], childs[i+1]);
            i--;
        }
        if (newChildPos == LEFT) swap(childs[i], childs[i+1]);
    }

    bool deleteKey(int oldKey, int oldChildPos=RIGHT) {
        int i = 0;
        while (i < n && oldKey > keys[i]) i++;
        if (keys[i] != oldKey) return false;
        keys.erase(keys.begin() + i);
        if (oldChildPos == RIGHT) i++;
        childs.erase(childs.begin() + i);
        n--;
        return true;
    }

    int n = 0;
    vector<int> keys;
    vector<BTreeNode*> childs;
    static int M;
};

int BTreeNode::M = 3;

bool insertBT(BTreeNode *&T, int newKey) {
    if (T == nullptr) {
        T = new BTreeNode(newKey);
        return true;
    }
    stack<BTreeNode*> st;
    BTreeNode *x = T;
    while (x != nullptr) {
        int i = 0;
        while (i < x->n && newKey > x->keys[i]) i++;
        if (i < x->n && newKey == x->keys[i]) return false;
        st.push(x);
        x = x->childs[i];
    }

    BTreeNode *newChild = nullptr;
    while (true) {
        x = st.top(); st.pop();
        x->insertKey(newKey, newChild);
        if (x->n < BTreeNode::M) break;
        newKey = x->keys[x->n/2];
        newChild = new BTreeNode(x);
        x->keys.resize(x->n/2);
        x->childs.resize(x->n/2+1);
        x->n /= 2;
        newChild->keys.erase(newChild->keys.begin(), newChild->keys.begin() + newChild->n/2+1);
        newChild->childs.erase(newChild->childs.begin(), newChild->childs.begin() + newChild->n/2+1);
        newChild->n -= newChild->n / 2 + 1;
        if (st.empty()) {
            T = new BTreeNode(newKey);
            T->childs[0] = x;
            T->childs[1] = newChild;
            break;
        }
    }

    return true;
}

bool deleteBT(BTreeNode *&T, int oldKey) {
    stack<BTreeNode*> st;
    BTreeNode *x = T;
    while (x != nullptr) {
        int i = 0;
        while (i < x->n && oldKey > x->keys[i]) i++;
        if (i < x->n && oldKey == x->keys[i]) break;
        st.push(x);
        x = x->childs[i];
    }
    if (x == nullptr) return false; // Search Fail
    if (x->childs[0] != nullptr) { // if x is Internal Node
        BTreeNode *internalNode = x;
        st.push(x);
        x = x->childs[find(x->keys.begin(), x->keys.end(), oldKey) - x->keys.begin()+1];
        while (x != nullptr) {
            st.push(x);
            x = x->childs[0];
        }
        x = st.top(); st.pop();
        *find(internalNode->keys.begin(), internalNode->keys.end(), oldKey) = x->keys[0];
        x->keys[0] = oldKey;
    }
    x->deleteKey(oldKey);
    BTreeNode *y, *leftSibling, *rightSibling;
    while (x->n < (BTreeNode::M+1)/2-1 && !st.empty()) { // While Underflow
        y = st.top(); st.pop();
        int idx = find(y->childs.begin(), y->childs.end(), x) - y->childs.begin();
        if (x == y->childs[0]) leftSibling = nullptr;
        else leftSibling = y->childs[idx-1];
        if (x == y->childs.back()) rightSibling = nullptr;
        else rightSibling = y->childs[idx+1];
        int flag;
        if (leftSibling == nullptr || rightSibling == nullptr) {
            if (leftSibling == nullptr) {
                if (rightSibling->n > (BTreeNode::M-1)/2) flag = RIGHT;
                else flag = MERGE;
            }
            else {
                if (leftSibling->n > (BTreeNode::M-1)/2) flag = LEFT;
                else flag = MERGE;
            }
        }
        else {
            if (leftSibling->n >= rightSibling->n && leftSibling->n > (BTreeNode::M-1)/2) flag = LEFT;
            else if (rightSibling->n > leftSibling->n) flag = RIGHT;
            else flag = MERGE;
        }
        if (flag == LEFT) { // Get key from left sibling
            x->insertKey(y->keys[idx-1], leftSibling->childs.back(), LEFT);
            y->keys[idx-1] = leftSibling->keys.back();
            leftSibling->deleteKey(leftSibling->keys.back());
        }
        else if (flag == RIGHT) { // Get key from right sibling
            x->insertKey(y->keys[idx], rightSibling->childs[0], RIGHT);
            y->keys[idx] = rightSibling->keys[0];
            rightSibling->deleteKey(rightSibling->keys[0], LEFT);
        }
        else { // Merge
            if (leftSibling == nullptr) {
                idx++;
                leftSibling = x;
                x = rightSibling;
            }
            leftSibling->keys.push_back(y->keys[idx-1]);
            leftSibling->n++;
            y->deleteKey(y->keys[idx-1], RIGHT);
            leftSibling->keys.insert(leftSibling->keys.end(), x->keys.begin(), x->keys.end());
            leftSibling->childs.insert(leftSibling->childs.end(), x->childs.begin(), x->childs.end());
            leftSibling->n += x->n;
            x->childs.clear();
            delete x;
        }
        x = y;
    }
    if (T->n == 0) {
        y = T;
        T = T->childs[0];
        y->childs.clear();
        delete y;
    }

    return true;
}

void inorderBT(BTreeNode *T) {
    if (T == nullptr) return;
    for (int i=0;i<T->n;++i) {
        inorderBT(T->childs[i]);
        cout << T->keys[i] << ' ';
    }
    inorderBT(T->childs[T->n]);
}

int main() {
    cout << " File Processing  " << endl;
    cout << "      B-Tree" << endl;
    cout << "==================" << endl;

    int insertKeys[] = {
        40, 11, 77, 33, 20, 90, 99, 70, 88, 80,
        66, 10, 22, 30, 44, 55, 50, 60, 100, 28,
        18, 9, 5, 17, 6, 3, 1, 4, 2, 7,
        8, 73, 12, 13, 14, 16, 15, 25, 24, 28,
        45, 49, 42, 43, 41, 47, 48, 46, 63, 68,
        61, 62, 64, 69, 67, 65, 54, 59, 58, 51,
        53, 57, 52, 56, 83, 81, 82, 84, 75, 89
    };

    int deleteKeys[] = {
        66, 10, 22, 30, 44, 55, 50, 60, 100, 28,
        18, 9, 5, 17, 6, 3, 1, 4, 2, 7,
        8, 73, 12, 13, 14, 16, 15, 25, 24, 28,
        40, 11, 77, 33, 20, 90, 99, 70, 88, 80,
        45, 49, 42, 43, 41, 47, 48, 46, 63, 68,
        53, 57, 52, 56, 83, 81, 82, 84, 75, 89,
        61, 62, 64, 69, 67, 65, 54, 59, 58, 51
    };

    BTreeNode *root = nullptr;

    BTreeNode::M = 3;
    cout << "M = 3" << endl;
    for (int key : insertKeys) insertBT(root, key);

    for (int key : deleteKeys) {
        cout << "Delete " << key << '\t';
        deleteBT(root, key);
        inorderBT(root);
        cout << endl;
    }

    delete root;
    root = nullptr;

    cout << "==================" << endl;
    BTreeNode::M = 4;
    cout << "M = 4" << endl;
    for (int key : insertKeys) insertBT(root, key);

    for (int key : deleteKeys) {
        cout << "Delete " << key << '\t';
        deleteBT(root, key);
        inorderBT(root);
        cout << endl;
    }

    delete root;

    return 0;
}