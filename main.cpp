#include <iostream>
using namespace std;

// Struktur Node untuk Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Alokasi memori gagal!" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Fungsi untuk mencetak tree secara inorder
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Fungsi untuk mencetak menu
void printMenu() {
    cout << "=== Menu ===" << endl;
    cout << "1. Tambahkan node ke dalam tree" << endl;
    cout << "2. Cetak tree secara inorder" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data node: ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Tree secara inorder: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
