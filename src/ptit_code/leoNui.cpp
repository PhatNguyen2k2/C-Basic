/*Có N (1<=N<=25,000) người leo lên và leo xuống trên 1 ngọn núi. 
Người i mất U(i) thời gian leo lên và D(i) thời gian để leo xuống. 
Trong một thời điểm chỉ có tối đa người 1 người có thể lên và tối đa 1 người 
có thể xuống (có thể 1 ng lên, 1 ng xuống). Những người khác có thể đứng chờ ở đỉnh 
ngọn núi. Thứ tự đi xuống có thể khác thứ tự đi lên. Bạn hãy xác định xem thời gian tối 
thiểu để cho N người lên và xuống ngọn núi là bao nhiêu.
-->Dòng 1: Số nguyên N  
   N dòng tiếp chứa 2 số U(i) và D(i) (1 <= U(i) , D(i) <= 50,000).
Output: Thời gian tối thiểu có thể.*/
#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int MinUp=50005;
	int MinDown=50005;
	int SumU=0;
	int SumD=0;
	while(n--){
		int a, b;
		cin>>a>>b;
		SumU+=a;
		SumD+=b;
		if (a<MinUp) MinUp=a;
		if (b<MinDown) MinDown=b;
	}
	SumU+=MinDown;
	SumD+=MinUp;
	if (SumU<SumD) cout<<SumD;
	else cout<<SumU;
	return 0;
}