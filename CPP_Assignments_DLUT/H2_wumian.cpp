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

//����ȱʡ���캯�� 
NMng::NMng()
{
	memset(Int, 0, sizeof(int)*N);
	cout<<"constructor!\n";
}

//�����Ա����input,����Ϊ����Ԫ���������� 
void NMng::input()
{
	cout<<"������"<<N<<"Ԫ�������飺"<<"\n";
	for(i = 0; i < N; i++)
	{
		cin >> Int[i];
	}
	cout<<"�����ʼ����ϣ�\n";
	disp(); 
}

//�����Ա����disp��������ʾ�����ÿ��Ԫ��ֵ 
void NMng::disp()
{
	cout<<"Int["<<N<<"]: ";
	for(i = 0; i < N; i++)
	{
		cout<<Int[i]<<" "; 
	}
	cout<<"\n";
}

//�����Ա����max�������ҳ�����Ԫ�ص����ֵ����������������ֵ�ɺ���ֵ���أ������ɲ������� 
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
return m; //��m�������ֵ 
}         //��num[0]�������ֵ���� 

//�����Ա����find�������ҳ��������ظ�����������������������ܴ��ڶ����������ʾ���� 
int NMng::find()
{
	int j;
	struct label
	{
	int c;
	int l;
	} x[N];
	
	for(i = 0; i < N; i++) //�Խṹ���ʼ�� 
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
	cout<<"�ظ�������������: ";
	for(i = 0; i < N; i++)
	{
		if (x[i].l == 0 && x[i].c == countMax)
		{
			cout<<Int[i]<<", ";
		}
		
	}
	cout<<"�ظ�����Ϊ��"<<countMax<<"\n";
	return countMax;
}

int main()
{
	int IntMax;
	NMng d1;
	d1.input();
	IntMax = d1.max(d1.mNum);
	cout<<"����Ԫ�ص����ֵ�ǣ�"<<IntMax<<","<<"�����Ϊ��"<<d1.mNum[0]<<"\n";
	d1.find();
	cout<<"������ϣ�";
} 
