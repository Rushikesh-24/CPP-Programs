#include<iostream>
#include <queue>
using namespace std;
class Node{
    int data;
    Node* lchild;
    Node* rchild;
    public:
    Node(int value){
        data = value;
        lchild = NULL;
        rchild = NULL;
    }
    friend class BinaryTree;
};
class BinaryTree{
    Node* root;
     Node* insertNode(Node* root ,int value){
        if(root == NULL){
            return new Node(value);
        }
        if(value < root->data){
            root->lchild = insertNode(root->lchild, value);
        }else if(value > root->data){
            root->rchild = insertNode(root->rchild, value);
        }
        return root;
    }
    void preorderTraversalArray(Node* root, int arr[], int& index) {
        if (root != nullptr) {
            arr[index++] = root->data;
            preorderTraversalArray(root->lchild, arr, index);
            preorderTraversalArray(root->rchild, arr, index);
        }
    }
    public:
    BinaryTree(){
        root = NULL;
    }
    BinaryTree(Node *roots){
        root = roots;
    }
    void insert(int value){
        root = insertNode(root, value);
    }
    int* preorderArray(int num) {
        int* arr = new int[num];
        int index = 0;
        preorderTraversalArray(root, arr, index);
        return arr;
    }
    BinaryTree operator=(BinaryTree copy) {
        if (root != copy.root) {
            root = copyTree(copy.root);
        }
        BinaryTree Temp(root);
        return Temp;
    }
    Node* copyTree(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* newNode = new Node(node->data);
        newNode->lchild = copyTree(node->lchild);
        newNode->rchild = copyTree(node->rchild);
        return newNode;
    }
};
int main(){
    BinaryTree tree;
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int value;
        cout << "Enter a value for node " << i+1 << ": ";
        cin >> value;
        tree.insert(value);
    }
    BinaryTree newTree = tree;
    int *a = tree.preorderArray(numNodes);
    int *b = newTree.preorderArray(numNodes);
    cout<<"Preorder of Original tree :";
    for(int i = 0; i < numNodes; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Preorder of Copied tree :";
    for(int i = 0; i < numNodes; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int numNodes2;
    cout << "Enter the number of nodes for the second tree: ";
    cin>>numNodes2;
    BinaryTree tree2;
    for(int i = 0; i < numNodes2; i++){
        int value;
        cout << "Enter a value for node " << i+1 << ": ";
        cin >> value;
        tree2.insert(value);
    }
    int *c = tree2.preorderArray(numNodes);
    if(numNodes2 != numNodes){
        cout<<"The trees do not have the same number of nodes"<<endl;
        return 0;
    }
    bool equalTrees = true;
    for(int i = 0; i < numNodes; i++){
        if(a[i] != c[i]){
            equalTrees = false;
            break;
        }
    }
    if(equalTrees){
        cout<<"The trees are equal"<<endl;
    }else{
        cout<<"The trees are not equal"<<endl;
    }
    return 0;
}