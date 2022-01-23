#include <iostream>
using namespace std;

template <typename Item>
class CArrayQueue {
public:
	CArrayQueue(int size);	
	bool isEmpty();
	bool isFull();
	int getRead();
	int getWrite();
	int getLength();
	void enqueue(Item v);
	Item dequeue();
	void show();
private:
	Item *buf;	// circular buffer
	int read;	// read pointer
	int write;	// write pointer
	int length;	// buffer length
};
template <typename Item>
int CArrayQueue<Item>::getRead(){
	return read;
}
template <typename Item>
int CArrayQueue<Item>::getWrite(){
	return write;
}
template <typename Item>
int CArrayQueue<Item>::getLength(){
	return length;
}
template <typename Item>
bool CArrayQueue<Item>::isEmpty(){
	return read == write;
}
template <typename Item>
bool CArrayQueue<Item>::isFull(){
	return read == ( write + 1 ) % (length);
}
template <typename Item>
CArrayQueue<Item>::CArrayQueue(int size) {
	buf = new Item[size];
	read = 0;
	write = 0;
	length = size;
}
template <typename Item>
void CArrayQueue<Item>::enqueue(Item v) {
	// write your code here
	if(!isFull()){
    buf[write] = v;
	write = (write+1)%(length);
	}
}
template <typename Item>
Item CArrayQueue<Item>::dequeue() {
	// write your code here
	if(!isEmpty()){
    Item r = buf[read];
	read = (read+1)%(length);
    return r;
	}
}
template <typename Item>
void CArrayQueue<Item>::show() {
	if (read == write) {
		cout << "empty queue" << endl;
		return;
	}
	for (int i = read; i < write; i++)
		cout << buf[i] << "\t";
	cout << endl;
}
Item BinaryTree::deleteRight(Node* p){
	if(p == NULL){
		cout<<"Error"<<endl;
		return -1;
	}
	else if(p->right == NULL){
		cout<<"Error"<<endl;
		return -1;
	}
	else{
		Node* q = p->right;
		if(q->left != NULL || q->right != NULL){
			cout<<"Error"<<endl;
			return -1;
		}
		else{
			Item value = q->data;
			p->right = NULL;
			delete q;
			return value;
		}
	}
}