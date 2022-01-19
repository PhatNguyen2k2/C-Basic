#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream infile("./exam/data_structure/submit/phat/giaiThuat_phat/school/GTs/input.txt");
bool euler(vector<vector<int> > edge);
bool fleury(vector<vector<int> > edge, vector<int> del);
vector<vector<int> >erase(vector<vector<int> > edge, vector<int> del);
bool empty(vector<vector<int> > edge);

int main(){    
    int n, i, j;
    //đọc ma trận từ file input.txt
    infile>>n;
    vector<vector<int> > edge; int val;
    for(i=0; i<n; i++){
        vector<int> row;
        for(j=0; j<n; j++)
        {
            infile>>val;
            row.push_back(val);
        }
        edge.push_back(row);
    }    
    if(euler(edge)){
        cout<<"Chu trinh Euler: "<<endl;
        vector<int> circuit; int current=0;
        circuit.push_back(current);
        cout<<current + 1<<" ";
        while(!empty(edge)){
            for(i=0; i<n; i++){
                int previous=current;
                if(edge[current][i]==1){
                    vector<int> del;
                    del.push_back(current);
                    del.push_back(i);
                    if(fleury(edge, del)){
                        edge=erase(edge,del);
                        current=i;
                        circuit.push_back(current);
                        cout<<current + 1<<" ";
                        break;
                    }
                }
            }
        }
        cout<<endl<<"Chu trinh Euler da duoc tim thay."<<endl;
    }else{
        cout<<"Khong tim duoc chu trinh Euler."<<endl;
    }
    return 0;
}

bool euler(vector<vector<int> > edge){
    for(int i=0; i<edge.size(); i++){
        int deg=0;
        for(int j=0; j<edge[0].size(); j++){
            deg+=edge[i][j];
        }
        if(deg%2!=0){ 
            return false;
        }
    }
    return true;
}

bool fleury(vector<vector<int> > edge, vector<int> del){
    int n, i, j, k;
    if(del[0]==del[1]){
        return false;
    }
    vector<vector<int> > edged=edge;
    edged[del[0]][del[1]]=0;
    edged[del[1]][del[0]]=0;
    n= edged[0].size();
    //Khởi tạo bảng
    const int infinity=1000000;
    vector<bool> known;
    for(i=0; i<n; i++){
        known.push_back(false);
    }
    vector<int> d;
    d.push_back(0);
    for(i=1; i<n; i++){
        d.push_back(infinity);
    }
    vector<int> p;
    for(i=0; i<n; i++){
        p.push_back(-1);
    }    
    for(k=0; k<n; k++)
    {
        //Tìm giá trị min của d cho đỉnh chưa biết
        int min=0;
        while(known[min]==true){
            min++;
        }
        for(i=0; i<n; i++){
            if(known[i]==false && d[i]<d[min]){
                min=i;
            }
        }
        //Cập nhật lại bảng
        known[min]=true;
        for(j=0; j<n; j++){
            if(edged[min][j]!=0 && d[j]>edged[min][j] && known[j]==false){
                d[j]=edged[min][j];
                p[j]=min;
            }
        }
    }
    bool ok=true;    
    for(i=1; i<n; i++){
        if(p[i]==-1){
            for (int j=0; j<n; j++){
                if(edged[i][j]!=0){
                    ok=false; break;
                }
            }
        }
    }
    return ok;
}

vector<vector<int> > erase(vector< vector<int> > edge, vector<int> del){
    vector< vector<int> > edged=edge;
    edged[del[0]][del[1]]=0;
    edged[del[1]][del[0]]=0;
    return edged;
}

bool empty(vector<vector<int> > edge){
    for(int i=0; i<edge.size(); i++){
        for(int j=0; j<edge[0].size(); j++){
            if(edge[i][j]==1){
                return false;
            }
        }
        return true;
    }
}