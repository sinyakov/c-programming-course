#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    
    node(int value) : data(value), left(nullptr), right(nullptr) {};
};

void print(node* tree) {
    std::cout << tree->data << std::endl;

    if (tree->left != nullptr) {
        print(tree->left);
    }
    if (tree->right != nullptr) {
        print(tree->right);
    }
}

void dfs(node *tree) {
    stack<node*> nodes;
    nodes.push(tree);
    while(!nodes.empty()) {
        node* top = nodes.top();
        nodes.pop();
        cout << top->data << endl;
        if (top->right != nullptr) {
            nodes.push(top->right);
        }
        if (top->left != nullptr) {
            nodes.push(top->left);
        }
    }
}

void bfs(node *tree) {
    queue<node*> nodes;
    nodes.push(tree);
    while(!nodes.empty()) {
        node* top = nodes.front();
        nodes.pop();
        cout << top->data << endl;
        if (top->left != nullptr) {
            nodes.push(top->left);
        }
        if (top->right != nullptr) {
            nodes.push(top->right);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    node *tree = new node(1);
    tree->left = new node(2);
    tree->left->left = new node(4);
    tree->left->right = new node(5);
    tree->right = new node(3);
    tree->right->left = new node(6);
    tree->right->right = new node(7);

    bfs(tree);
    return 0;
}
