/*定义一个类，用于对10个字符串进行管理。要求：

（1）在定义对象时，能够为字符串清空；

（2）定义变换构造函数，能够为字符串赋以给定的字符串；

（3）定义复制构造函数；

（4）定义成员函数，能够为字符串输入数据；

（5）定义成员函数，能够将字符串显示出来；

（6）定义成员函数，用于找出每个字符串中的最小值（ASCII码最小的字符）及其个数，最小值由函数值返回，个数由参数带回；

（7）定义成员函数，用于为字符串按从小到大顺序排序。

（8）定义main函数，合理地调用上述每个函数。*/
#include <iostream>
#include <string>
#define NUM 10
using namespace std;

class cString
{
private:
	string str[NUM];
public:
	cString();                          //默认构造函数 
	cString(string ss[NUM]);             //变换构造函数 
	cString(const cString &another);    //复制构造函数 
	void cInput();                      //输入数据 
	void disp();                        //显示数据 
	char* cMin(int num[]);              //找ASCII码最小的字符 ,这里num[]中括号内可以不加数字，在主函数里定义时写即可 
	void cSort();	                    //从小到大排序 
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
	for(i = 0; i < NUM; i++)          //统一用NUM而不用１０ 
	{
		str[i] = another.str[i];
	}	
}
void cString::cInput()
{
	cout<<"请输入"<<NUM<<"个字符串："<<endl;  //统一用NUM而不用１０
	for(i = 0; i < NUM; i++)              //统一用NUM而不用１０; 注意非法中文空格！！ 
	{
		cin>>str[i];
	}		
}
void cString::disp()
{
	cout<<"字符串组如下:"<<endl;
	for(i = 0; i < NUM - 1; i++)
	{
		cout<<str[i]<<',';
	}	
	cout<<str[i]<<endl;
}
char str_min[NUM];        //在cMin()函数中使用了str_min【10】，在次之前就必须要定义，返回可以返回一个指针，而主函数中使用时为一个指针，故必须定义一个指针而不是数组！！！ 
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
	cout<<"1.缺省构造函数初始化x,y:"<<endl; 
	cString x,y;
	x.disp();
	cout<<endl;
	
	cout<<"2.变换构造函数初始化z:"<<endl;
	string ss[NUM] = {"I","love","dut","!"};    //先把字符串放入一个string类型的数组 
	cString z(ss); 
	z.disp();
	cout<<endl;
	
	cout<<"3.调用cInput()函数给y输入字符串组:"<<endl;
	y.cInput();
	y.disp();
	cout<<endl;
	
	cout<<"4.调用复制构造函数将y赋给x："<<endl;
	x = y;
	x.disp();
	cout<<endl;
	
	cout<<"5.找出x中每个字符串的最小字符，并给出最小字符的数目："<<endl;
	int min_num[NUM];
	char* str_min = x.cMin(min_num);                //虽然前面声明的时候可以不加NUM，调用时也可以不加，因为定义的时候加了。 而且此处必须定义一个指针而不是数组！！！因为函数返回值是，前面先定义数组，而后使用，最后返回地址，也没问题 
	for(i = 0; i < NUM; i++)
	{
		cout<<str_min[i]<<": "<<min_num[i]<<endl;		
	}
	cout<<endl;
	
	cout<<"6.将x中的字符串从小到大排序："<<endl;
	x.cSort();
	x.disp();
	cout<<endl;	
	
	return 0;
}
