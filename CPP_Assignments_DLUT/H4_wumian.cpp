/*����һ���࣬���ڶ�10���ַ������й���Ҫ��

��1���ڶ������ʱ���ܹ�Ϊ�ַ�����գ�

��2������任���캯�����ܹ�Ϊ�ַ������Ը������ַ�����

��3�����帴�ƹ��캯����

��4�������Ա�������ܹ�Ϊ�ַ����������ݣ�

��5�������Ա�������ܹ����ַ�����ʾ������

��6�������Ա�����������ҳ�ÿ���ַ����е���Сֵ��ASCII����С���ַ��������������Сֵ�ɺ���ֵ���أ������ɲ������أ�

��7�������Ա����������Ϊ�ַ�������С����˳������

��8������main����������ص�������ÿ��������*/
#include <iostream>
#include <string>
#define NUM 10
using namespace std;

class cString
{
private:
	string str[NUM];
public:
	cString();                          //Ĭ�Ϲ��캯�� 
	cString(string ss[NUM]);             //�任���캯�� 
	cString(const cString &another);    //���ƹ��캯�� 
	void cInput();                      //�������� 
	void disp();                        //��ʾ���� 
	char* cMin(int num[]);              //��ASCII����С���ַ� ,����num[]�������ڿ��Բ������֣����������ﶨ��ʱд���� 
	void cSort();	                    //��С�������� 
} ;
int i;
cString::cString()
{
	for(i = 0; i < NUM; i++)
	{
		str[i] = "";
	}	
}
cString::cString(string ss[NUM])
{
	for(i = 0; i < NUM; i++)
	{
		str[i] = ss[i];
	}	
}
cString::cString(const cString &another)
{
	for(i = 0; i < NUM; i++)          //ͳһ��NUM�����ã��� 
	{
		str[i] = another.str[i];
	}	
}
void cString::cInput()
{
	cout<<"������"<<NUM<<"���ַ�����"<<endl;  //ͳһ��NUM�����ã���
	for(i = 0; i < NUM; i++)              //ͳһ��NUM�����ã���; ע��Ƿ����Ŀո񣡣� 
	{
		cin>>str[i];
	}		
}
void cString::disp()
{
	cout<<"�ַ���������:"<<endl;
	for(i = 0; i < NUM - 1; i++)
	{
		cout<<str[i]<<',';
	}	
	cout<<str[i]<<endl;
}
char str_min[NUM];        //��cMin()������ʹ����str_min��10�����ڴ�֮ǰ�ͱ���Ҫ���壬���ؿ��Է���һ��ָ�룬����������ʹ��ʱΪһ��ָ�룬�ʱ��붨��һ��ָ����������飡���� 
char* cString::cMin(int num[])
{
	int j;	
	for(i = 0; i < NUM; i++)
	{
		str_min[i] = str[i][0];
		num[i] = 1;
		for(j = 1;str[i][j] != '\0'; j++)
		{
			if(str[i][j] == str_min[i])
				num[i]++;
			if(str[i][j] < str_min[i])
			{
				str_min[i] = str[i][j];
				num[i] = 1;
			}
		}
		
	}	 
	return str_min;
}
void cString::cSort()
{
	string temp = "";
	int j = NUM - 1;
	for(; j > 0; j--)
	{
		for(i = 0; i < j; i++)
		{
			if(str[i] > str[i + 1])
			{
				temp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = temp;
			}
		}
	}
}
int main()
{
	cout<<"1.ȱʡ���캯����ʼ��x,y:"<<endl; 
	cString x,y;
	x.disp();
	cout<<endl;
	
	cout<<"2.�任���캯����ʼ��z:"<<endl;
	string ss[NUM] = {"I","love","dut","!"};    //�Ȱ��ַ�������һ��string���͵����� 
	cString z(ss); 
	z.disp();
	cout<<endl;
	
	cout<<"3.����cInput()������y�����ַ�����:"<<endl;
	y.cInput();
	y.disp();
	cout<<endl;
	
	cout<<"4.���ø��ƹ��캯����y����x��"<<endl;
	x = y;
	x.disp();
	cout<<endl;
	
	cout<<"5.�ҳ�x��ÿ���ַ�������С�ַ�����������С�ַ�����Ŀ��"<<endl;
	int min_num[NUM];
	char* str_min = x.cMin(min_num);                //��Ȼǰ��������ʱ����Բ���NUM������ʱҲ���Բ��ӣ���Ϊ�����ʱ����ˡ� ���Ҵ˴����붨��һ��ָ����������飡������Ϊ��������ֵ�ǣ�ǰ���ȶ������飬����ʹ�ã���󷵻ص�ַ��Ҳû���� 
	for(i = 0; i < NUM; i++)
	{
		cout<<str_min[i]<<": "<<min_num[i]<<endl;		
	}
	cout<<endl;
	
	cout<<"6.��x�е��ַ�����С��������"<<endl;
	x.cSort();
	x.disp();
	cout<<endl;	
	
	return 0;
}
