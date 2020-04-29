/*���������ѧ����Ϣ����ϵͳ
Ҫ��
    ��1������ڵ㣺����ѧ����Ϣ�����ɽڵ㲢���������У�
    ��2��ɾ���ڵ㣺���ݸ�����ѧ��������ѧ��ɾ����ѧ���ڵ㣻
    ��3�����ҽڵ㣺���ݸ�����ѧ��������ѧ�Ų���ѧ����Ϣ������ʾ������
    ��4�����Ҳ���ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ��
    ��5��ͳ�������е�ѧ��������
    ��6����ʱ������ʱѡ����������ڵ㰴�ܳɼ��Ӹߵ�������
ע��
   ��1��ÿ��ѧ����Ϣ������������ѧ�š��Ա𡢳��������պ�3�ſεĳɼ���
   ��2��ϵͳ���к�������ʾһ�����׵Ĳ˵������ڲ˵�����������������ܣ�
   ��3������Ĺ�����Ҫ���ʵ�֡�*/
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
	friend istream &operator>>(istream &is, Date &dt);  //cin����istream�Ķ��� 
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
	int n;//�������
	if (m<1 || m>12) return false;
	if (d<1) return false;
	n = 31;
	switch (m)
	{
	case 2:
		if (y % 4 == 0 && y % 100 || y % 400 == 0)//�ж��Ƿ�������
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
		cout<<"���������������������루�ꡢ�¡��գ���";
		is>>dt.year>>dt.month>>dt.day;
	}
	return is;
}
ostream &operator<<(ostream &os, Date &dt)
{
	os<<dt.year<<"��"<<dt.month<<"��"<<dt.day<<"��";
	return os;
}
class student
{
	friend class stu_list;	  //��Ԫ���� 
	//char name[name_num];  //   ��ʹ����������ÿ����λ�ô�һ�����֣����޸�����ʱ��Ҫ���ǣ����ʱ����Ҫ���ǣ� 
	string name;
	string number;
	char gender;
	Date date;
	float score1, score2, score3;
	float sum;
public:
	student *next;    //��ͬ��һ���� 
	student(void);
	~student(void);
	student &operator=(const student &stu);  //����ʽ����
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
	cout<<"����������������ѧ�š��Ա�M(��)/F(Ů)��������|��|�ա����ſη�����"<<"\n"; 
	cin>>name>>number>>gend;
	while(gend != 'F' && gend != 'M' && gend != 'f' && gend != 'm')
	{
		cout<<"�Ա�����������������룺";
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
	cout << "������" << name << '\t' << "ѧ�ţ�" << number << endl;
	cout << "�Ա�" << gender << '\t' << '\t' << "���������գ�" << date << endl;
	cout << "���ſγ̳ɼ���" << score1 << '\t' << score2 << '\t' << score3 << endl;
	cout << "�ܷ֣�" << sum << endl;
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
	stu_list & Delete(void);        //����������ѧ�Ų��ҽڵ㣬��ɾ��
	void find(void);         //������������ѧ�Ų��ҽڵ㣬����ʾѧ����Ϣ
	void find_extreme(void); //�ҵ��ܳɼ���ߺ���͵�ѧ������ʾ����Ϣ�� 
	student* Max(student *ptr);
	void sort_sum(void);  //������ڵ㰴�ܳɼ��Ӹߵ������� 
	void stu_count(void);  //ͳ���������� 
};
int stu_list::count = 0;  //��Ϊ�����ڶ�������û����һ����������������Ŀռ䣬ֻ��ͨ���������壬���ɿռ䣬ʵ�ֳ�ʼ������privateû����������ͨ�����������ˣ��Ϳ����޸��� 
stu_list &stu_list::Append(const student &stu)
{
	student *ptr = last;
	*ptr = stu;
	last = new student;
	ptr->next = last;
	count++;
	cout<<"����ڵ㣡"<<endl;
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
	cout<<"������Ҫɾ����ѧ������������ѧ�ţ�";
	cin>>item;
	student *temp = head;
	while (temp->next != last) {
		if (temp->next->name == item || temp->next->number == item) {
			temp->next->disp();
			cout << "�Ƿ�ɾ����ѧ����Ϣ����Y/N����";
			cin >> flag;
			while (flag != 'Y' && flag != 'y' && flag != 'N' && flag != 'n') {
				cout << "��������ȷָ�";
				cin >> flag;
			}
			if (flag == 'Y' ||flag == 'y') {
				cout << "ɾ���ڵ㣡" << endl;
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
	cout<<"������Ҫ���ҵ�ѧ������������ѧ�ţ�";
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
	if (flag == 0)  cout<<"���޴��ˣ�"<<endl;
}
void stu_list::find_extreme(void)
{
	cout << "���Ҳ���ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ��" << endl;
	float temp_max, temp_min;
	student *temp = head->next;
	if(temp != last )  //�ǿձ� 
	{
		temp_max = temp_min = temp->sum;
		if(temp->next == last) //һ��ѧ�� 
		{
			cout<<"�б���ֻ��һ��ѧ����û���ܳɼ���ߺ���͵�ѧ��������Ϣ����"<<endl;
			temp->disp(); 
		} 
		//����ѧ�������� 
		while (temp->next != last)  //���ҳ������ͷֵķ�ֵ 
		{
			if (temp->next->sum > temp_max)
			temp_max = temp->next->sum;
			else if (temp->next->sum < temp_min)
			temp_min = temp->next->sum;
			temp = temp->next;
		}
		if (temp_min == temp_max && count != 1)  //�����ͷ���ͬ����� 
		{
			char flag = 'N';
			cout<<"��������ѧ���ܳɼ���ͬ���Ƿ���Ҫ��ʾ���ǵ���Ϣ��Y/N����";
			cin>>flag;
			while (flag != 'N' && flag != 'n' && flag != 'Y' && flag != 'y')
			{
				cout<<"����������������룺";
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
		else if(temp_min < temp_max)  //�������ͷ� 
		{
			//�������߷������
			cout<<"�ܳɼ���ߵ�ѧ����" <<endl;
			temp = head->next;
			while (temp != last)
			{
				if (temp->sum == temp_max)
				temp->disp();
				temp = temp->next;
			}
			//�������ͷ������
			cout<<"�ܳɼ���͵�ѧ����"<<endl;
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
	cout<<"�б�Ϊ�գ�"<<endl; 
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
	return pmax;   //֮���Կ��Է�������Ϊ����ָ��Ŀռ��Ǻ������ⶨ��ģ�return��pmax�����ַ���Ѿ��еĵ�ַ���������ں������ڲ�new�����ģ���������������ˣ����ؾ��Ҳ����ˣ� 
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
	cout << "���������" << endl;
	p = head->next;
	while (p != last) {
		p->disp();
		p = p->next;
	}
}
void stu_list::stu_count()
{
	cout<<"������ѧ��������Ϊ��"<<stu_list::count<<endl;
}
int main(){
	stu_list slist;
	int order = 0;
	student stu;
	while (order != 6) 
	{
		cout << "|*------------------ѧ����Ϣ����ϵͳ--------------------*|" << endl;
		cout << "|                    ����0������ڵ�                     |" << endl;
		cout << "|                    ����1��ɾ���ڵ�                     |" << endl;
		cout << "|                    ����2�����ҽڵ�                     |" << endl;
		cout << "|       ����3�����Ҳ���ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ      |" << endl;
		cout << "|              ����4��ͳ�������е�ѧ������               |" << endl;
		cout << "|          ����5��������ڵ㰴�ܳɼ��Ӹߵ�������         |" << endl;
		cout << "|                    ����6���˳�ϵͳ                     |" << endl;
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
			cout << "�˳�ϵͳ��" << endl;
			break;
		default:
			cout << "���������Ϣ�����������롣" << endl;
			cin >> order;
			break;
		}
	}
	return 0;
}


