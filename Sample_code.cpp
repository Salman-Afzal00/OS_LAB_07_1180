#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a binary tree from an array
Node* createTreeFromArray(const int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < size) {
        Node* current = q.front();
        q.pop();

        // Add left child
        if (i < size) {
            current->left = new Node(arr[i]);
            q.push(current->left);
            i++;
        }

        // Add right child
        if (i < size) {
            current->right = new Node(arr[i]);
            q.push(current->right);
            i++;
        }
    }

    return root;
}

// Pre-order Traversal: Root -> Left -> Right
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order Traversal: Left -> Root -> Right
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order Traversal: Left -> Right -> Root
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    // Array to create the binary tree
    int arr[] = {30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the binary tree from the array
    Node* root = createTreeFromArray(arr, size);

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
