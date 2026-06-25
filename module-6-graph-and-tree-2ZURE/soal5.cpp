#include <iostream>
#include <string>
#include <vector>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node->isNil) return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node->isNil) return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node->isNil) return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printResult(const string& label, const vector<int>& result) {
    cout << label << " :";
    for (int x : result) {
        cout << " " << x;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    RedBlackTree rbt;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        // Abaikan duplikat
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q;
    cin >> Q;

    vector<string> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    for (const string& query : queries) {
        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        if (query == "PREORDER") {
            vector<int> res;
            preorder(rbt.root(), rbt.nil(), res);
            printResult("[Preorder]", res);
        } else if (query == "INORDER") {
            vector<int> res;
            inorder(rbt.root(), rbt.nil(), res);
            printResult("[Inorder]", res);
        } else if (query == "POSTORDER") {
            vector<int> res;
            postorder(rbt.root(), rbt.nil(), res);
            printResult("[Postorder]", res);
        } else if (query == "ALL") {
            vector<int> pre, in, post;
            preorder(rbt.root(), rbt.nil(), pre);
            inorder(rbt.root(), rbt.nil(), in);
            postorder(rbt.root(), rbt.nil(), post);
            printResult("[Preorder]", pre);
            printResult("[Inorder]", in);
            printResult("[Postorder]", post);
        }
    }

    return 0;
}