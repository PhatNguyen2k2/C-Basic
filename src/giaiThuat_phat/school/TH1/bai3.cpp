#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *pNext;
};
struct singleList{
	Node *pHead;
	Node *pTail;
};
void Initialize(singleList &list){
	list.pHead = list.pTail = NULL;
}
Node *CreateNode(int d){
	Node *pNode = new Node;
	if(pNode != NULL){
		pNode->data=d;
		pNode->pNext=NULL;
	}
	else{
		cout<<"Memory allocation failure";
	}
	return pNode;	
}
void PrintList(singleList list){
	Node *pTmp=list.pHead;
	if(pTmp==NULL){
		cout<<"This list is empty!";
		return;
	}
	while(pTmp!= NULL){
		cout<<pTmp->data<<" ";
		pTmp=pTmp->pNext;
	}
}
void InsertLast(singleList &list, int d){
	Node *pNode=CreateNode(d);
	if(list.pHead == NULL){
		list.pHead = list.pTail = pNode;
	}
	else {
		Node *pTmp=list.pHead;
		while (pTmp->pNext!= NULL){
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
	}
}
void swap (int &a, int &b){
    int temp = a;
        a = b;
        b = temp;
}
Node *linearSearch(singleList list, int f){
	Node *pTmp = list.pHead;
	while (pTmp != NULL){
		if(pTmp->data== f) break;
		pTmp= pTmp->pNext;
	}
	return pTmp;
}
Node* middle(Node* start, Node* last){
    if (start == NULL)	return NULL;
    Node* slow = start;
    Node* fast = start->pNext;
    while (fast != last){
        fast = fast->pNext;
        if (fast != last){
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }
    return slow;
}
Node* binarySearch(singleList list, int value)
{
    Node* start = list.pHead;
    Node* last = NULL;
    do{
        Node* mid = middle(start, last);
        if (mid == NULL)	return NULL;
        if (mid -> data == value)	return mid;
        else if (mid->data < value)	start = mid->pNext;
        else	last = mid;
    } while (last == NULL || last != start);
    return NULL;
}
void bubbleSort(singleList &list)
{
    int swapped, i;
    Node *lptr = NULL;
    if (list.pHead == NULL)
        return;
    do{
        swapped = 0;
        Node* ptr1 = list.pHead;
        while (ptr1->pNext!= lptr){
            if (ptr1->data > ptr1->pNext->data){ 
                swap(ptr1->data, ptr1->pNext->data);
                swapped = 1;
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void insertionSort(singleList &list){
    Node *p = list.pHead;
    Node *cur = list.pHead->pNext;
    Node *prev = list.pHead;
    if (p == NULL || p->pNext == NULL){
        return;
    }
    while (cur != NULL){
        if(prev->data <= cur->data){
            cur = cur->pNext;
            prev = prev->pNext;
        }
        else{
            if (list.pHead->data > cur->data){
                prev->pNext = cur->pNext;
                cur->pNext = list.pHead;
                list.pHead = cur;
            }else{
                p = list.pHead;
                while (p->pNext != NULL && p->pNext->data < cur->data) {
                    p = p->pNext;
                }
                prev->pNext = cur->pNext;
                cur->pNext = p->pNext;
                p->pNext = cur;
            }
        }
        cur = prev->pNext;
    }
}
void selectionSort(singleList &list){
	Node* temp = list.pHead;
    while (temp != NULL){
        Node* min = temp;
        Node* k = temp->pNext;
        while (k != NULL){
            if (min->data > k->data)
                min = k;
 
            k = k->pNext;
        }
        swap(temp->data, min->data);
        temp = temp->pNext;
    }
}
Node* getTail(Node* cur){
    while (cur != NULL && cur->pNext != NULL)
        cur = cur->pNext;
    return cur;
}
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd){
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->pNext;
        }
        else{
            if (prev != NULL)	prev->pNext = cur->pNext;
            Node* tmp = cur->pNext;
            cur->pNext = NULL;
            tail->pNext = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)	(*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}
Node* quickSortRecur(Node* head, Node* end){
    if (!head || head == end)
        return head;
    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->pNext != pivot)	tmp = tmp->pNext;
        tmp->pNext = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->pNext = pivot;
    }
    pivot->pNext = quickSortRecur(pivot->pNext, newEnd);
    return newHead;
}
void quickSort(singleList &list){
	Node **headRef = &list.pHead;
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
// huy danh sach lien ket
void FreeMemory(singleList &list){
	while (list.pHead != NULL){
		Node *pTmp=list.pHead;
		list.pHead=pTmp->pNext;
		pTmp->pNext=NULL;
		delete pTmp;
		pTmp = NULL;
	}
}
int main(){
	singleList list;
	Initialize(list);
	InsertLast(list,10);
	InsertLast(list,5);
	InsertLast(list,7);
	InsertLast(list,3);
	InsertLast(list,8);
	PrintList(list);
	int d;
	cout<<endl<<"Enter data need to find: ";
	cin>>d; 
	Node *pSearch=linearSearch(list,d);
	if(pSearch!=NULL){
		cout<<"linear search found "<<d;
	}
	else{
		cout<<"linear search not found "<< d;
	}
	cout <<endl<<"After sort: ";
	quickSort(list);
    bubbleSort(list);
    insertionSort(list);
    selectionSort(list);
	PrintList(list);
	FreeMemory(list);
    return 0; 
}