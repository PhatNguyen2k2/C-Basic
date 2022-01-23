#include <iostream>
using namespace std;

typedef int Item;
struct Node {
	Item data;
	Node* left;
	Node* right;	
};
class BST {
public:	
	// methods
	BST();
	BST(Item v);
	Node* createNode(Item v);
	bool isEmpty();	
	// void preOrder(Node* root);
	void inOrder(Node* root);
	void decrease(Node* root);
	void deleteTree(Node* &root);
	Node* search(Node* p, Item v);
	void insert(Node* &root, Item v);
	Node* minValueNode(Node* p);
	Node* maxValueNode(Node* p);
	void sumValue(Node* root);
    // Item leftMostValue(Node* root);
	// Node* remove(Node* &root, int v);
	// variable
	Node* root;	
};
BST::BST() {
	root = NULL;
}
BST::BST(Item v) {
	root = createNode(v);
}
bool BST::isEmpty() {
	return (root == NULL);
}
void BST::inOrder (Node* root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
void BST::decrease(Node* root){
	if (root != NULL){
        decrease(root->right);
        cout << root->data <<" ";
        decrease(root->left);
    }
}
// void BST::preOrder(Node* root) {
// 	if (root != NULL) {
// 		cout << root->data << "\t";
// 		preOrder(root->left);
// 		preOrder(root->right);
// 	}
// }
Node* BST::createNode(Item v) {	
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

void BST::insert(Node* &root, Item v) {
    if (root == NULL){
        root = createNode(v);
    }
    else {
        if (v < root->data)
            insert(root->left,v);
        else if (v > root->data)
            insert(root->right,v);
    }
}
Node* BST::minValueNode(Node* p) { 
    if(p->left == NULL){
        return p;
    }
    return minValueNode(p->left);
} 
Node* BST::maxValueNode(Node* p){
	if(p->right == NULL){
		return p;
	}
	return maxValueNode(p->right);
}
// Item BST::leftMostValue(Node* root){
//     while(root->left != NULL)
//         root = root->left;
//     return root->data;
// }
// Node* BST::remove(Node* &root, int v)
// {
//     if (root == NULL)
//         return root;
//     if (v < root->data)
//         root->left = remove(root->left, v);
//     else if (v > root->data)
//         root->right = remove(root->right, v);
//     else{
//         if(root->left == NULL){
//             Node* newRoot=root->right;
//             delete root;
//             return newRoot;
//         }
//         if(root->right == NULL){
//             Node* newRoot = root->left;
//             delete root;
//             return newRoot;
//         }
//         root->data = leftMostValue(root->right);
//         root->right = remove(root->right, root->data);
//     }
//     return root;
// }
Node* BST::search(Node* root,Item v){
    if (root == NULL){
        return NULL;
    }
    if(root->data == v){
        return root;
    }
    else if(v < root->data)
        search(root->left,v);
    else if(v > root->data)
        search(root->right,v);
    return root;
}
int sum = 0;
void BST::sumValue(Node* root){
	if (root != NULL){
		sum += root->data;
		sumValue(root->left);
		sumValue(root->right);
	}
}
BST createFromArray(Item a[], int length) {
    BST b;
    for(int i = 0; i<length; i++){
        b.insert(b.root, a[i]);
    }
    return b;
}

int main() {
	int a[] = {6, 2, 1, 4, 3, 9, 8, 7, 13, 11, 18};
	BST bst = createFromArray(a, sizeof(a)/sizeof(int));	
	cout<<"Increase: ";
	bst.inOrder(bst.root);
	cout<<endl;
	cout<<"Decrease: ";
	bst.decrease(bst.root);
	cout<<endl;
	cout<<"Max value: "<<bst.maxValueNode(bst.root)->data<<endl;
	cout<<"Min value: "<<bst.minValueNode(bst.root)->data<<endl;
	bst.sumValue(bst.root);
	cout<<"Sum value in tree: "<<sum<<endl;
	return 0;
}
