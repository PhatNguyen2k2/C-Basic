#include <iostream>
#include <stdlib.h>
using namespace std;	

class DList {
public:
	DList(); 			// initialize an empty list 
	DList(int m);	// initialize a list to store m elements
	~DList();	// free memory
	bool isEmpty() const; 	// check if the list is empty
	int length() const; 	// get the number of elements in a list		
	void insert(const int x, int i); 	// insert x at the position i
	void append(const int x); 	// insert x at the end of the list
	void remove(int i); 		// remove the ith element
	int retrieve(int i) const; // return the value the ith element
	void print() const; 	// print all element values
	int getLast() const;
	int getSize() const;
private:
	int *element;  
	int size;	// capacity of the list
	int last;	// index of the last item
};
// initialize an empty list
DList::DList() {
	element = NULL;
	size = 0;
	last = -1;
}
// initialize a list that can store m elements	
DList::DList(int m) {
	element = new int[m];
	size = m;
	last = -1;
}
// free memory
DList::~DList() {
	delete[] element;
}
// get the value of last
int DList::getLast() const {
	return last;
}
// get the value of size
int DList::getSize() const {
	return size;
}
// return the value the ith element
int DList::retrieve(int i) const {
	return *(element+i);
}
// insert x at the end of the list	
void DList::insert(const int x, int i) {
	// in case list is not full
	if(last+1<size){
		for(int j=last+1;j>i;j--){
			element[j+1]=element[j];
		}
		element[i]=x;
		++last;
	}
	// in case list is full
	else{
		int *t = new int[size];
		for(int i=0; i<=last; i++){
			t[i]=element[i];
		}
		size = size*2;
		element = new int[size];
		for(int k=0; k<=i-1; k++){
			element[k]=t[k];
		}
		element[i]=x;
		for(int k=i; k<=last; k++){
			element[k+1]=t[k];
		}
		++last;
		delete[] t;
	}
}
int main() {
	int n = 5;
	DList list(n);
	
	list.insert(3, 0);
	list.insert(4, 0);
	list.insert(8, 0);	
	list.insert(2, 0);	
	list.insert(7, 0);	

	for (int i = 0; i <= list.getLast(); i++)
		cout << list.retrieve(i) << "  ";
	cout << endl;
	cout << list.getLast() << endl;
	cout << list.getSize() << endl;
	
	list.insert(15, 3);
	for (int i = 0; i <= list.getLast(); i++)
		cout << list.retrieve(i) << "  ";
	cout << endl;
	cout << list.getLast() << endl;
	cout << list.getSize() << endl;
	
	list.insert(15, list.getLast());
	for (int i = 0; i <= list.getLast(); i++)
		cout << list.retrieve(i) << "  ";
	cout << endl;
	cout << list.getLast() << endl;
	cout << list.getSize() << endl;
	
	list.insert(15, list.getLast()+1);
	for (int i = 0; i <= list.getLast(); i++)
		cout << list.retrieve(i) << "  ";
	cout << endl;
	cout << list.getLast() << endl;
	cout << list.getSize() << endl;

	return 0;
}