/*基于链表的学生信息管理系统
要求：
    （1）插入节点：输入学生信息后，生成节点并插入链表中；
    （2）删除节点：根据给定的学生姓名或学号删除该学生节点；
    （3）查找节点：根据给定的学生姓名或学号查找学生信息，并显示出来；
    （4）查找并显示总成绩最高和最低的学生信息；
    （5）统计链表中的学生人数；
    （6）（时间允许时选做）对链表节点按总成绩从高到低排序。
注：
   （1）每个学生信息包括：姓名、学号、性别、出生年月日和3门课的成绩；
   （2）系统运行后，首先显示一个简易的菜单，基于菜单操作来完成上述功能；
   （3）链表的功能需要编程实现。*/
#include<iostream>
#include <string> 
using namespace std;
class Date
{
	unsigned short int year;
	unsigned short int month;
	unsigned short int day;
public:
	Date(void);
	Date &operator=(const Date &dt);
	bool check_date(int y, int m, int d);
	friend istream &operator>>(istream &is, Date &dt);  //cin是类istream的对象 
	friend ostream &operator<<(ostream &os, Date &dt);
};
Date::Date(void)
{
	year = 2000;
	month = 1;
	day = 1;
}
Date &Date::operator=(const Date &dt)
{
	year = dt.year;
	month = dt.month;
	day = dt.day;
	return *this;
}
bool Date::check_date(int y, int m, int d) 
{
	int n;//最大天数
	if (m<1 || m>12) return false;
	if (d<1) return false;
	n = 31;
	switch (m)
	{
	case 2:
		if (y % 4 == 0 && y % 100 || y % 400 == 0)//判断是否是闰年
			n = 29;
		else
			n = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		n = 30;
		break;
	}
	if (d > n) return false;
	return true;
} 
istream &operator>>(istream &is, Date &dt)
{
	is>>dt.year>>dt.month>>dt.day;
	while(dt.check_date(dt.year, dt.month, dt.day) != 1)
	{
		cout<<"生日输入有误，请重新输入（年、月、日）：";
		is>>dt.year>>dt.month>>dt.day;
	}
	return is;
}
ostream &operator<<(ostream &os, Date &dt)
{
	os<<dt.year<<"年"<<dt.month<<"月"<<dt.day<<"日";
	return os;
}
class student
{
	friend class stu_list;	  //友元函数 
	//char name[name_num];  //   若使用中文名，每两个位置存一个汉字，在修改内容时需要考虑；输出时候不需要考虑； 
	string name;
	string number;
	char gender;
	Date date;
	float score1, score2, score3;
	float sum;
public:
	student *next;    //不同于一般类 
	student(void);
	~student(void);
	student &operator=(const student &stu);  //检查格式？？
	void input();
	void disp();
} ;
student::student()
{
	next = nullptr;
}
student::~student(){}
student &student::operator=(const student &stu)
{
	name = stu.name;
	number = stu.number;
	gender = stu.gender;
	date = stu.date;
	score1 = stu.score1;
	score2 = stu.score2;
	score3 = stu.score3;
	sum = stu.sum;
	return *this;
}
void student::input()
{
	char gend;
	cout<<"请依次输入姓名、学号、性别：M(男)/F(女)、出生年|月|日、三门课分数："<<"\n"; 
	cin>>name>>number>>gend;
	while(gend != 'F' && gend != 'M' && gend != 'f' && gend != 'm')
	{
		cout<<"性别输入错误，请重新输入：";
		cin>>gend;
	}
	if (gend == 'f' || gend == 'F') gender = 'F';
	else if (gend == 'm' || gend == 'M') gender = 'M';
	cin>>date>>score1>>score2>>score3;
	sum = score1 + score2 + score3;	
}
void student::disp()
{
	cout << "|*------------------------------------------------------*|" << endl;
	cout << "姓名：" << name << '\t' << "学号：" << number << endl;
	cout << "性别：" << gender << '\t' << '\t' << "出生年月日：" << date << endl;
	cout << "三门课程成绩：" << score1 << '\t' << score2 << '\t' << score3 << endl;
	cout << "总分：" << sum << endl;
	cout << "|*------------------------------------------------------*|" << endl;
}
class stu_list
{
	student *head;
	student *last;
	static int count;
public:
	stu_list(void)
	{
		head = new student;  // new student();
		last = new student;
		head->next = last;
		
	}
	~stu_list();
	stu_list &Append(const student &stu);
	stu_list & Delete(void);        //根据姓名或学号查找节点，并删除
	void find(void);         //根据姓名或者学号查找节点，并显示学生信息
	void find_extreme(void); //找到总成绩最高和最低的学生，显示其信息； 
	student* Max(student *ptr);
	void sort_sum(void);  //对链表节点按总成绩从高到低排序； 
	void stu_count(void);  //统计总人数； 
};
int stu_list::count = 0;  //因为不属于对象，所以没有哪一个对象可以生成它的空间，只能通过单独定义，生成空间，实现初始化，是private没错，所以这里通过类名访问了，就可以修改了 
stu_list &stu_list::Append(const student &stu)
{
	student *ptr = last;
	*ptr = stu;
	last = new student;
	ptr->next = last;
	count++;
	cout<<"插入节点！"<<endl;
	return *this;	
}
stu_list::~stu_list()
{
	delete head;
}
stu_list &stu_list::Delete()
{
	char flag = 'N';
	string item;
	cout<<"请输入要删除的学生的姓名或者学号：";
	cin>>item;
	student *temp = head;
	while (temp->next != last) {
		if (temp->next->name == item || temp->next->number == item) {
			temp->next->disp();
			cout << "是否删除该学生信息？（Y/N）：";
			cin >> flag;
			while (flag != 'Y' && flag != 'y' && flag != 'N' && flag != 'n') {
				cout << "请输入正确指令：";
				cin >> flag;
			}
			if (flag == 'Y' ||flag == 'y') {
				cout << "删除节点！" << endl;
				student *del = temp->next;
				temp->next = temp->next->next;
				del->~student();
				stu_list::count--;
			}
			if (flag == 'N' || flag == 'n'){
				temp = temp->next;
			}
		}
		else {
			temp = temp->next;
		}
	}
}
void stu_list::find()
{
	string item;
	cout<<"请输入要查找的学生的姓名或者学号：";
	cin>>item;
	int flag = 0;
	student *temp;
	temp = head;
	while(temp != last)
	{
		if (temp->next->name == item || temp->next->number == item)
			{
				temp->next->disp();
				flag++;
			}
		temp = temp->next;	
	}
	if (flag == 0)  cout<<"查无此人！"<<endl;
}
void stu_list::find_extreme(void)
{
	cout << "查找并显示总成绩最高和最低的学生信息：" << endl;
	float temp_max, temp_min;
	student *temp = head->next;
	if(temp != last )  //非空表 
	{
		temp_max = temp_min = temp->sum;
		if(temp->next == last) //一名学生 
		{
			cout<<"列表中只有一名学生，没有总成绩最高和最低的学生，其信息如下"<<endl;
			temp->disp(); 
		} 
		//两名学生或以上 
		while (temp->next != last)  //先找出最高最低分的分值 
		{
			if (temp->next->sum > temp_max)
			temp_max = temp->next->sum;
			else if (temp->next->sum < temp_min)
			temp_min = temp->next->sum;
			temp = temp->next;
		}
		if (temp_min == temp_max && count != 1)  //最高最低分相同的情况 
		{
			char flag = 'N';
			cout<<"表中所有学生总成绩相同，是否需要显示他们的信息（Y/N）：";
			cin>>flag;
			while (flag != 'N' && flag != 'n' && flag != 'Y' && flag != 'y')
			{
				cout<<"输入错误，请重新输入：";
				cin>>flag; 
			}
			if (flag == 'Y' || flag == 'y')
			{
				temp = head->next;
				while(temp->next != last)
				{
					temp->disp();
					temp = temp->next;
				}
			}
		}
		else if(temp_min < temp_max)  //有最高最低分 
		{
			//先输出最高分情况：
			cout<<"总成绩最高的学生：" <<endl;
			temp = head->next;
			while (temp != last)
			{
				if (temp->sum == temp_max)
				temp->disp();
				temp = temp->next;
			}
			//后输出最低分情况：
			cout<<"总成绩最低的学生："<<endl;
			temp = head->next;
			while (temp != last)
			{
				if (temp->sum == temp_min)
				temp->disp();
				temp = temp->next;				
			}
		}
	}
	else
	cout<<"列表为空！"<<endl; 
}
student* stu_list::Max(student *ptr)
{
	student *p = ptr;
	student *pmax = p;
	while (p != last) {
		if (p->sum > pmax->sum) {
			pmax = p;
		}
		p = p->next;  
	}
	return pmax;   //之所以可以返回是因为，其指向的空间是函数体外定义的，return的pmax这个地址是已经有的地址，而不是在函数体内部new出来的（这样就是随机的了，返回就找不到了） 
}
void stu_list::sort_sum()
{
	void list_disp();
	student *p = head->next;
	student *r;
	while (p != last) {
		r = Max(p);
		student stu = *p;
		*p = *r;
		*r = stu;
		p = p->next;
	}
	cout << "排序后链表：" << endl;
	p = head->next;
	while (p != last) {
		p->disp();
		p = p->next;
	}
}
void stu_list::stu_count()
{
	cout<<"链表中学生总人数为："<<stu_list::count<<endl;
}
int main(){
	stu_list slist;
	int order = 0;
	student stu;
	while (order != 6) 
	{
		cout << "|*------------------学生信息管理系统--------------------*|" << endl;
		cout << "|                    输入0：插入节点                     |" << endl;
		cout << "|                    输入1：删除节点                     |" << endl;
		cout << "|                    输入2：查找节点                     |" << endl;
		cout << "|       输入3：查找并显示总成绩最高和最低的学生信息      |" << endl;
		cout << "|              输入4：统计链表中的学生人数               |" << endl;
		cout << "|          输入5：对链表节点按总成绩从高到低排序         |" << endl;
		cout << "|                    输入6：退出系统                     |" << endl;
		cout << "|*------------------------------------------------------*|" << endl;
		cin >> order;
		switch (order) 
		{
		case 0:
			stu.input();
			slist.Append(stu);
			break;
		case 1:
			slist.Delete();
			break;
		case 2:
			slist.find();
			break;
		case 3:
			slist.find_extreme();
			break;
		case 4:
			slist.stu_count();
			break;
		case 5:
			slist.sort_sum();
			break;
		case 6:
			cout << "退出系统！" << endl;
			break;
		default:
			cout << "输入错误信息！请重新输入。" << endl;
			cin >> order;
			break;
		}
	}
	return 0;
}


