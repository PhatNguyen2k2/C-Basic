// Ho ten: Nguyen Hoang Phat
// MSSV: 6151071082
// Ngay sinh: 12/1/2002
// Email: 6151071082@st.utc2.edu.vn
// Viết chương trình tính giá trị của biểu thức hậu tố.
#include <iostream>
#include <math.h>
using namespace std;

typedef double Item;

struct Node{
	Item data;
	Node *next;
};

struct stack{
	Node *top;
	long size;
	
	stack();
	void traverse() const;	
	Node* CreateNode(Item v);		
	void push(Item v);
	Item pop();
	Item peek();	
};
stack::stack() {
	top = NULL;
	size = 0;
}
void stack::traverse() const {
	Node *p = top;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
	delete p;
}
Node* stack::CreateNode(Item v) {
	Node* p = new Node;
	p->data = v;	
	p->next = NULL;	
	return p; 
}	
void stack::push(Item v) {
	Node* p = CreateNode(v);
	p->next = top;
	top = p;	
	size++;
}
Item stack::pop() {	
	Node *t = top;
	Item data = top->data;
	top = top->next;
	delete t;
	size--;	
	return data;
}
Item stack::peek() {
	return top->data;
}
// kiem tra la so
bool isOperand(char ch) {
    return (ch>='0' && ch<='9');
}
// tinh hau to
double evalute(string postfix) {
    stack s;
    for(int i = 0; i<postfix.size(); i++){
        if(isOperand(postfix[i])){
            s.push(postfix[i]-'0');
        }else{
            double a = s.pop();
            double b = s.pop();
            switch (postfix[i])
            {
                case '+': // cong
                          s.push(b + a);
                          break;
                case '-': // tru
                          s.push(b - a);
                          break;
                case '*': // nhan
                          s.push(b * a);
                          break;
                case '/': // chia
                          s.push(b / a);
                          break;
                case '^': // mu
                          s.push(pow(b,a));
                          break;
            }
        }
    }
    return s.pop();
}
int main() {
	string e1 = "82/7*";	//28
	string e2 = "623+-382/+*2^3+";	//52
	string e3 = "72*93/+";	//17
	string e4 = "2578*+*9-";	//113
	string e5 = "753-/9*2+";	//33.5
	
	cout << e1 << " = " << evalute(e1) << endl;
	cout << e2 << " = " << evalute(e2) << endl;
	cout << e3 << " = " << evalute(e3) << endl;
	cout << e4 << " = " << evalute(e4) << endl;
	cout << e5 << " = " << evalute(e5) << endl;
	
	return 0;
}