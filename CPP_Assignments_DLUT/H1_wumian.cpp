#include <iostream>
using namespace std;
#define R 4
#define C 3
int judge(int *ptr, int n = C){
	int i = 0;
	int temp = *ptr;
	while (temp == *(ptr + i)) i++;
	if (i == n) return 1;
	else if(i < n) return 0;
}
int sub_max(int *ptr, int n = C){
	int *p = ptr;
	int m = *p;
	int sub_m;
	int i = 0, j = 1;
	for(i = 0; i < C; i++){
		if (*(p + i) > m){
			m = *(p + i);
		}
	}
	while (m == *(p + j)) j++ ;
	sub_m = *(p + j);
	for(i = j + 1; i < C; i++){
		if (*(p + i) > sub_m && *(p + i) != m){
			sub_m = *(p + i);
		}
	}
		return sub_m;
}
int main(){
	int (*p)[C];
	p = new int[R] [C];
	cout<<"������"<<R<<"��"<<C<<"�ж�ά�������飺"<<endl;
	int i,j;
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++){
			cin>>*(*(p + i) + j);
		}
	}
	for(i = 0; i < R; i++){
		if (judge(*(p + i)) == 1) cout<<"��"<< i + 1<<"��Ԫ��ֵ���,û�д����ֵ"<<endl;
		else if(judge(*(p + i)) == 0)  cout<<"��"<<i + 1<<"�д����ֵΪ��"<<sub_max(*(p + i))<<endl;
		}
	return 0 ;	
}

