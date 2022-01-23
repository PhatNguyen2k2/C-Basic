#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};
class linkedList{
	public:
	Node *head;
		linkedList(){
			head = NULL;
		}
		void push(int value){
			Node *node = new Node(value);
			if(head==NULL){
				head = node;
				head->next = NULL;
			}
			else{
				Node *temp = head;
				head = node;
				head->next = temp;
			}
		}
		void sortedInsert(int x){
			Node *pNode = new Node(x);   
			Node *pPre = NULL;
			Node *pIns= head;
				while(pIns!=NULL && x>pIns->data){ 
					pPre=pIns;
					pIns=pIns->next;
				}
				pNode->next = pIns;
				if(pPre==NULL){
					head = pNode;
				}else{
					pPre->next = pNode;
				}
		}
		Node* reverse(Node *head){
			if (head == NULL || head->next == NULL) 
				return head; 
			Node* rest = reverse(head->next); 
			head->next->next = head; 
			head->next = NULL; 
			return rest;
		}
		void print(){
			Node *pTmp = head;
			if(pTmp==NULL){
				cout<<"The list is empty!";
				return;
			}
			while(pTmp!= NULL){
				cout<< pTmp->data<<" ";
				pTmp=pTmp->next;
			}
			cout<<endl;
		}
};
int main(){
	linkedList list;
	int a;
	while(cin>>a){
		list.push(a);
	}
	list.sortedInsert(1);
	list.print();
	list.head=list.reverse(list.head);
	list.print();
}