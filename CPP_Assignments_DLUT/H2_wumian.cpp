#include <iostream>
#include <string.h>
#define  N 10
using namespace std;

int i = 0;

class NMng
{
int Int[N];
public:
int mNum[N];
NMng();
void input();
void disp();
int max(int *num);
int find();
}; 

//定义缺省构造函数 
NMng::NMng()
{
	memset(Int, 0, sizeof(int)*N);
	cout<<"constructor!\n";
}

//定义成员函数input,用于为数组元素输入数据 
void NMng::input()
{
	cout<<"请输入"<<N<<"元整型数组："<<"\n";
	for(i = 0; i < N; i++)
	{
		cin >> Int[i];
	}
	cout<<"数组初始化完毕！\n";
	disp(); 
}

//定义成员函数disp，用于显示数组的每个元素值 
void NMng::disp()
{
	cout<<"Int["<<N<<"]: ";
	for(i = 0; i < N; i++)
	{
		cout<<Int[i]<<" "; 
	}
	cout<<"\n";
}

//定义成员函数max，用于找出数组元素的最大值及其个数，其中最大值由函数值返回，个数由参数带回 
int NMng::max(int *num)
{
	int j = 0;
	int m = Int[j];
	num[j] = 1;
	for(i = 1; i < N; i++)
	{
		num[i] = 0;
		if(Int[i] > m)
		{
	 		j = i;
			m = Int[i];
	 		num[j]++;
		}
		else if(Int[i] == m)
		{
			num[j]++;
		}	
	}
num[0] = num[j];
return m; //用m返回最大值 
}         //用num[0]保留最大值个数 

//定义成员函数find，用于找出数组中重复次数最多的数及其个数（可能存在多个），并显示出来 
int NMng::find()
{
	int j;
	struct label
	{
	int c;
	int l;
	} x[N];
	
	for(i = 0; i < N; i++) //对结构体初始化 
	{
		x[i].c = 1;
		x[i].l = 0;
	}
	
	int countMax = 1;
	for(i = 0; i < N; i++)
	{
		if(x[i].l == 0)
		{
			for(j = i + 1; j < N; j++)
			{
				if (Int[j] == Int[i])
				{
					x[i].c += 1;
					x[j].l = 1;
				}			
			}
			if (x[i].c > countMax)
			{
				countMax = x[i].c;
			}
		}
	}
	cout<<"重复次数最多的数是: ";
	for(i = 0; i < N; i++)
	{
		if (x[i].l == 0 && x[i].c == countMax)
		{
			cout<<Int[i]<<", ";
		}
		
	}
	cout<<"重复次数为："<<countMax<<"\n";
	return countMax;
}

int main()
{
	int IntMax;
	NMng d1;
	d1.input();
	IntMax = d1.max(d1.mNum);
	cout<<"数组元素的最大值是："<<IntMax<<","<<"其个数为："<<d1.mNum[0]<<"\n";
	d1.find();
	cout<<"测试完毕！";
} 
