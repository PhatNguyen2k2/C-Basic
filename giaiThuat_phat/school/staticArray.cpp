#include <iostream>
using namespace std;
 
class ArrayList {
public:
	static const int MAX_SIZE = 100; 
	ArrayList(); 			// initialize an empty list 
	bool isEmpty() const; 	// check if the list is empty
	int length() const; 	// get the number of elements in a list
	void insert(const int x, int i); 	// insert x at the position i
	void append(const int x); 	// insert x at the end of the list
	void remove(int i); 		// remove the ith element
	int retrieve(int i) const; // return the value to the ith element
	void print() const; 	// print all element values
	int getlast() const;  // print index value at the end of the list

private:
	int element[MAX_SIZE];	// array to store all list elements
	int last;	// index of the last item
};
// Definition of all ArrayList methods
ArrayList::ArrayList(){
	last = -1;
}
bool ArrayList::isEmpty() const {
	return (last == -1);
}	
int ArrayList :: length() const {
	return (last + 1);
}
void ArrayList::insert(const int x, int i){
	if(last == MAX_SIZE-1){
		cout<<"cannot insert into list";
		exit(0);
	}
	for(int j=last;j>i;j--){
		element[j+1]=element[j];
	}
	element[i]=x;
	++last;
}
void ArrayList :: append(const int x){
	if(last == MAX_SIZE){
		cout<<"cannot insert into list";
		exit(0);
	}
	else{
		element[last+1]=x;
		++last;
	}
}
void ArrayList :: remove(int i){
	for(int j=i;j<last;j++){
			element[j]=element[j+1];
	}
	last--;
}
int ArrayList :: retrieve(int i) const{
	return element[i];
}
void ArrayList :: print() const{
	for( int i=0 ;i <= last; i++){
		cout<<element[i]<<" ";
	}
}
int ArrayList::getlast() const{
	return last;
} 
// Main function
int main() {
	ArrayList list;
	if (list.isEmpty())
		cout << "Empty list"<<endl;
	else cout<< "Not empty list"<<endl;

	cout<<"Insert at the end of the list :"<<endl;
	list.append(3);
	list.print();
	cout << endl;

	list.append(7);
	list.print();
	cout << endl;

 	list.append(1);
	list.print();
	cout << endl;
 
	cout<<"Insert x = 5 at the position i = 1:"<<endl;
	list.insert(5,1);
	list.print();
	cout<<endl;
	cout<<"Index last of the list:\t"<<list.getlast()<<endl;
 
	cout<<"All value of the list :";
	list.print();
	cout<<endl;
	cout<<"Length of the list :"<<list.length()<<endl;
	
	list.remove(1);
	list.print();
	cout<<"the value to the ith element: "<<list.retrieve(1)<<endl;
	return 0;
}