//Nguyen Hoang Phat - 6151071082
#include <iostream>
using namespace std;

class SV{
    protected: 
        string Class;
        string name;
    public:
        SV(){
            name = " ";
            Class = " ";
        }
        ~SV(){}
        void Enter(){
            fflush(stdin);
            cout << "Name: ";
            getline(cin,name);
            cout << "Grade: ";
            cin >> Class;
        }
        void Print(){
            cout << "Name: "<<name<<endl;
            cout << "Grade: "<<Class<<endl;
        }
};

class SVSP : public SV{
    protected: 
        float average;
        float scholarship;
    public:
        SVSP(){
            average = 0;
            scholarship = 0;
        }
        void Enter(){
            fflush(stdin);
            SV::Enter();
            cout << "Score: ";
            cin >> average;
            cout << "Scholarship: ";
            cin >> scholarship;
        }
        void Print(){
            SV::Print();
            cout << "Total Score: "<<average<<endl;
            cout << "Scholarship: "<<scholarship<<endl;
        }
};

class SVCN : public SVSP{
    protected:
        float tuition;
    public:
        SVCN(){
            tuition = 0;
        }
        void Enter(){
            fflush(stdin);
            SVSP *sp = new SVCN;
            sp->Enter();
            cout <<"Tuition: ";
            cin >> tuition;
        }
        void Print(){
            SVSP *sp;
            sp->Print();
            cout <<"Tuition: "<<tuition<<endl;
        }
};

int main(){
    SVCN *sn = new SVCN[3];
    for (int i = 0; i < 3; i++){
        sn[i].Enter();
    }
    for (int i = 0; i < 3; i++){
        sn[i].Print();
    }
}