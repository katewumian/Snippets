/*���һ���࣬���ڶ��ַ������й���Ҫ��

��1���ڶ������ʱ���ܹ�ȷ���ַ�������󳤶Ȳ�����ַ�����

��2�������Ա����input, ���ڴӼ���Ϊ�ַ����������ݡ�

��3��������������غ����������ж����������е��ַ����Ƿ���ͬ��

��4�������Ա����exchange�����ڻ����ַ�����ASCII��������С���ַ����迼���ַ����д��ڶ��������С�ַ����������

��5�������Ա����disp��������ʾ�ַ�����

��6������main����������ص�������ÿ��������*/

#include <string.h>
#include <iostream>
using namespace std;

int i = 0;
class cString
{
	char *str;//�����ַ��� 
	int num;//��¼�ַ����ĳ��� 
public:
	cString(int N);
	void input();
	bool operator == (const cString &s);
	int exchange();
	void disp();	
};//������cString
cString::cString(int N)//����任���캯�� 
{
	num = N > 0 ? N : 0;
	str = new char[num + 1];
	memset(str, 0, sizeof(str));
}
void cString::input()//input�������ⲿ���� 
{
	cout<<"��������󳤶�Ϊ"<<num<<"���ַ������Իس���������"; 
	for (i = 0; i < num; i++)
	{
		cin>>str[i];	
	}
	str[i] = '\0';
}
bool cString::operator == (const cString &s)//�������������== 
{
	if(strcmp(str, s.str) == 0)
		return true;
	else
		return false;
}
int cString::exchange()//���庯��exchange
{
	char cMax = str[0], cMin = str[0];
	for(i = 1; i < num; i++)
	{
		if (str[i] > cMax)
		{
			cMax = str[i];
		}
		else if (str[i] < cMin)
		{
			cMin = str[i];
		}
	}
	if (cMax == cMin)
	{
		cout<<"���ַ��������ַ���ͬ����������С�ַ�"<<endl;
		return 0;
	}
	else if (cMax < cMin)
		return 	1;
	else if (cMax > cMin)
	{
		cout<<"����"<<cMin<<"��"<<cMax<<":"; 
		for (i = 0; i < num; i++)
		{
			if (str[i] == cMax)
			str[i] = cMin;
			else if (str[i] == cMin)
			str[i] = cMax;
		}
		return 0;
	}
}
void cString::disp()//���庯��disp
{
	for(i = 0; i < num; i++)
	{
		cout<<str[i];
	}
}
int main()//����������main 
{
	int cmp, N;
	cout<<"������һ���ַ����ĳ��ȣ�";cin>>N;
	cString dt1(N);
	dt1.input();
	cout<<"str1:";
	dt1.disp();cout<<endl;
	cout<<"��������һ���ַ����ĳ��ȣ�";cin>>N;
	cString dt2(N);
	dt2.input();
	cout<<"str2:";
	dt2.disp();cout<<endl;//���������ַ�������ʾ 
	cout<<"str1 == str2 ?"; 
	if (dt1 == dt2)
	{
		cout<<"True"<<endl;
		cout<<"exchange:";
		dt1.exchange();dt1.disp(); 
	}
	else
	{
		cout<<"False"<<endl;
		cout<<"��һ���ַ���";dt1.exchange();dt1.disp(); cout<<endl;
		cout<<"�ڶ����ַ���";dt2.exchange();dt2.disp();
	}//�Ƚ������ַ����Ƿ���ͬ������������������������С����֮����ַ��� 
	cout<<"\n"<<"Test Complete!"<<endl; //������� 
	return 0;	
}
