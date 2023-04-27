#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // cout << "OK";
  // if (node==NULL) {
  //   cout << "OK1";
  //   struct node temp;
  //   temp.key = key;
  //   temp.left = NULL;
  //   temp.right = NULL;
  //   node = &temp;
  // } else if (node->key > key)  {
  //   insertNode(node->left, key);
  // } else if (node->key < key) {
  //   insertNode(node->right, key);
  // }
  // return node;
  if (node == NULL) {
        struct node *temp = new struct node();
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }

    return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            struct node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        } else {
            struct node *successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->key = successor->key;
            root->right = deleteNode(root->right, successor->key);
        }
    }

    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}