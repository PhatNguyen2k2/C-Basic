//https://scontent.fhan5-1.fna.fbcdn.net/v/t1.15752-9/215128182_183289400516492_5025101709529396126_n.png?_nc_cat=110&ccb=1-3&_nc_sid=ae9488&_nc_ohc=zyO82dwmSk8AX_NmtHZ&_nc_ht=scontent.fhan5-1.fna&oh=943ae386fa83ed62a49ddc93a3db4869&oe=6125F4E8
#include <bits/stdc++.h>
using namespace std;
int differentSubstringsTrie(string inputString){
    set<string> answer;
    for (int i = 0; i <= inputString.size(); ++i)
        for (int j = 1; j <= inputString.size() - i; ++j)
        {
            answer.insert(inputString.substr(i, j));
        }
    return answer.size();
}
int main(){
    string s;
	cin>>s;
    cout << differentSubstringsTrie(s)<<endl;
}