/*设计一个类，用于对字符串进行管理。要求：

（1）在定义对象时，能够确定字符串的最大长度并清空字符串。

（2）定义成员函数input, 用于从键盘为字符串输入数据。

（3）定义运算符重载函数，用于判断两个对象中的字符串是否相同。

（4）定义成员函数exchange，用于互换字符串中ASCII码最大和最小的字符（需考虑字符串中存在多个最大和最小字符的情况）。

（5）定义成员函数disp，用于显示字符串。

（6）定义main函数，合理地调用上述每个函数。*/

#include <string.h>
#include <iostream>
using namespace std;

int i = 0;
class cString
{
	char *str;//保存字符串 
	int num;//记录字符串的长度 
public:
	cString(int N);
	void input();
	bool operator == (const cString &s);
	int exchange();
	void disp();	
};//定义类cString
cString::cString(int N)//定义变换构造函数 
{
	num = N > 0 ? N : 0;
	str = new char[num + 1];
	memset(str, 0, sizeof(str));
}
void cString::input()//input函数的外部定义 
{
	cout<<"请输入最大长度为"<<num<<"的字符串（以回车结束）："; 
	for (i = 0; i < num; i++)
	{
		cin>>str[i];	
	}
	str[i] = '\0';
}
bool cString::operator == (const cString &s)//定义重载运算符== 
{
	if(strcmp(str, s.str) == 0)
		return true;
	else
		return false;
}
int cString::exchange()//定义函数exchange
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
		cout<<"该字符串所有字符相同，无最大或最小字符"<<endl;
		return 0;
	}
	else if (cMax < cMin)
		return 	1;
	else if (cMax > cMin)
	{
		cout<<"交换"<<cMin<<"和"<<cMax<<":"; 
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
void cString::disp()//定义函数disp
{
	for(i = 0; i < num; i++)
	{
		cout<<str[i];
	}
}
int main()//定义主函数main 
{
	int cmp, N;
	cout<<"请输入一个字符串的长度：";cin>>N;
	cString dt1(N);
	dt1.input();
	cout<<"str1:";
	dt1.disp();cout<<endl;
	cout<<"请输入另一个字符串的长度：";cin>>N;
	cString dt2(N);
	dt2.input();
	cout<<"str2:";
	dt2.disp();cout<<endl;//输入两个字符串并显示 
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
		cout<<"第一个字符串";dt1.exchange();dt1.disp(); cout<<endl;
		cout<<"第二个字符串";dt2.exchange();dt2.disp();
	}//比较两个字符串是否相同并给出结果，输出交换最大和最小符号之后的字符串 
	cout<<"\n"<<"Test Complete!"<<endl; //测试完成 
	return 0;	
}
