#include<iostream>
using namespace std;

struct Node{
    string key, value;
    Node *left, *right;

    Node() : left(NULL), right(NULL) {}
    Node(string k, string v) : key(k), value(v), left(NULL), right(NULL) {}
};

class BinaryTree{
    Node *root;

public:
    BinaryTree() : root(NULL) {}

    void insert(string key, string value){
        Node *nn = new Node(key, value);
        if(root == NULL){
            root = nn;
            return;
        }

        Node *temp = root;
        while(temp){
            if(key < temp->key){
                if(temp->left == NULL){
                    temp->left = nn;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->right == NULL){
                    temp->right = nn;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }

    void inorderTraversal(Node *root){
        if(root){
            inorderTraversal(root->left);
            cout << root->key << " : " << root->value << endl;
            inorderTraversal(root->right);
        }
    }

    void inorderTraversal(){
        inorderTraversal(root);
    }

    void preorderTraversal(Node *root){
        if(root){
            cout << root->key << " : " << root->value << endl;
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void preorderTraversal(){
        preorderTraversal(root);
    }

    void postorderTraversal(Node *root){
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->key << " : " << root->value << endl;
        }
    }

    void postorderTraversal(){
        postorderTraversal(root);
    }

    string search(Node* root, string key){
        if(root == NULL) return "Key not found";
        if(root->key == key) return root->value;
        if(key < root->key) return search(root->left, key);
        return search(root->right, key);
    }

    string search(string key){
        return search(root, key);
    }

    int height(Node *root) {
        if (root == NULL) return 0;
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        return max(lHeight, rHeight) + 1;
    }

    int height() {
        return height(root);
    }

    Node* clone(Node* root){
        if(root == NULL) return NULL;
        Node* newNode = new Node(root->key, root->value);
        newNode->left = clone(root->left);
        newNode->right = clone(root->right);
        return newNode;
    }

    BinaryTree* cloneTree(){
        BinaryTree* newTree = new BinaryTree();
        newTree->root = clone(root);
        return newTree;
    }

    void mirror(Node* root){
        if(root){
            swap(root->left, root->right);
            mirror(root->left);
            mirror(root->right);
        }
    }

    void mirrorTree(){
        mirror(root);
    }

     


    Node* deleteNode(Node* root, string key){
        if(root == NULL) return root;
        if(key < root->key) root->left = deleteNode(root->left, key);
        else if(key > root->key) root->right = deleteNode(root->right, key);
        else {
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node){
        Node* current = node;
        while(current && current->left != NULL)
            current = current->left;
        return current;
    }

    void deleteKey(string key){
        root = deleteNode(root, key);
    }
};

int main(){
    BinaryTree tree;
    int choice;
    string key, value;

    do{
        cout << "\nMenu: \n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        
        cout << "6. Search\n";
        cout << "7. Clone Tree\n";
        cout << "8. Mirror Tree\n";
        cout << "9. Delete Node\n";
        cout << "10. Height of Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                tree.insert(key, value);
                break;
            case 2:
                cout << "Inorder Traversal:\n";
                tree.inorderTraversal();
                break;
            case 3:
                cout << "Preorder Traversal:\n";
                tree.preorderTraversal();
                break;
            case 4:
                cout << "Postorder Traversal:\n";
                tree.postorderTraversal();
                break;
            
            case 6:
                cout << "Enter key to search: ";
                cin >> key;
                cout << "Value: " << tree.search(key) << endl;
                break;
            case 7: {
                BinaryTree* clonedTree = tree.cloneTree();
                cout << "Cloned Tree Inorder Traversal:\n";
                clonedTree->inorderTraversal();
                delete clonedTree;
                break;
            }
            case 8:
                tree.mirrorTree();
                cout << "Tree mirrored. Inorder Traversal after mirroring:\n";
                tree.inorderTraversal();
                break;
            case 9:
                cout << "Enter key to delete: ";
                cin >> key;
                tree.deleteKey(key);
                cout << "Inorder Traversal after deletion:\n";
                tree.inorderTraversal();
                break;
            case 10:
                cout << "Height of Tree: " << tree.height() << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 0);

    return 0;
}

