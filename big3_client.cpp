#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdbool.h>
using namespace std;

class Client
{
	friend ostream& operator <<(ostream& os, const Client& newpelatis);
	private:
		int* id;
		string* name;
		int* years;
		int* starter_salary;
		int* salary; //salary + (50 x year)
	public:
		Client(const int& xid=0, const string& xname=" ", const int& xyears=0, const int& xsalary=0);
		~Client();
		Client(const Client& c);
		Client& operator =(const Client& c);
		int getid() const;
		string getname() const;
		int getyears() const;
		int getstarter_salary() const;
		int getsalary() const;
		void setid(const int& xid=0);
		void setname(const string& xname=" ");
		void setyears(const int& xyears=0);
		void setsalary(const int& xsalary=0);
		void printa();
		_Bool find(const string& keyword);
};

Client::Client(const int& xid, const string& xname, const int& xyears, const int& xsalary)
{
	cout<<"constructor"<<endl;
	id=new int;
	*id=xid;
	name=new string;
	*name=xname;
	years=new int;
	*years=xyears;
	starter_salary=new int;
	*starter_salary=xsalary;
	salary=new int;
 	*salary=xsalary+(50*(*years));
}

Client::~Client()
{
	cout<<"destructor"<<endl;
    delete id;
	delete name;
	delete years;
	delete starter_salary;
	delete salary;
}

Client::Client(const Client& c)
{
	cout<<"copy constructor"<<endl;
	id=new int;
	*id=c.getid();
	name=new string;
	*name=c.getname();
	years=new int;
	*years=c.getyears();
	starter_salary=new int;
	*starter_salary=c.getstarter_salary();
	salary=new int;
	*salary=c.getsalary();
}

Client& Client::operator =(const Client& c)
{
	cout<<"assign operator ="<<endl;
	if (this==&c)
	{
		return *this;
	}else{
        *id=c.getid();
		*name=c.getname();
		*years=c.getyears();
		*starter_salary=c.getstarter_salary();
		*salary=c.getsalary();
		return *this;
	}
}

int Client::getid() const
{
	return *id;
}

string Client::getname() const
{
	return *name;
}

int Client::getyears() const
{
	return *years;
}

int Client::getstarter_salary() const
{
    return *starter_salary;
}

int Client::getsalary() const
{
	return *salary;
}

void Client::setid(const int& xid)
{
	*id=xid;
}

void Client::setname(const string& xname)
{
	*name=xname;
}

void Client::setyears(const int& xyears)
{
	*years=xyears;
}

void Client::setsalary(const int& xsalary)
{
	*starter_salary=xsalary;
	*salary=xsalary+(50*(*years));
}

void Client::printa()
{
	cout<<"printa"<<endl;
	cout<<" ***************************************"<<endl;
	cout<<" client id -------> "<<getid()<<endl;
  cout<<" client name -----> "<<getname()<<endl;
  cout<<" years of work ---> "<<getyears()<<endl;
  cout<<" starter salary --> "<<getstarter_salary()<<endl;
  cout<<" final salary ----> "<<getsalary()<<endl;
	cout<<" ***************************************"<<endl;
}

_Bool Client::find(const string& keyword)
{
	if ((*name).find(keyword)!=string::npos)
	{
		return 1;
	}else{
		return 0;
	}
}

void menu();
Client newadd();
void search(vector <Client> pelatis);

int main()
{
  int choice;
	vector <Client> pelatis;
	
	while (true)
	{
		menu();
		cin>>choice;
		
		if (choice==1)
		{
			pelatis.push_back(newadd());
		}
		
		if (choice==2)
		{
      if (pelatis.size()==0)
			{
				cout<<" NO CLIENTS YET"<<endl;
			}
			
			for (int i=0; i<pelatis.size(); ++i)
			{
				pelatis[i].printa();
			}
			system("pause");
		}
		
		if (choice==3)
		{
      if (pelatis.size()==0)
			{
				cout<<" NO CLIENTS YET"<<endl;
			}
			
			search(pelatis);
			system("pause");
		}
		
		if (choice==4)
		{
			if (pelatis.size()==0)
			{
				cout<<" NO CLIENTS YET"<<endl;
			}

			for (int i=0; i<pelatis.size(); ++i)
			{
				cout<<pelatis[i];
			}
			system("pause");
		}
		
		if (choice==0)
		{
			break;
		}
	}
	
	system("pause");
}

void menu()
{
	system("color f1");
	cout<<"**********************************************************"<<endl;
	cout<<" Add new client ------------------ 1"<<endl;
	cout<<" Show clients with printa -------- 2"<<endl;
	cout<<" Search client ------------------- 3"<<endl;
	cout<<" Show clients with << ------------ 4"<<endl;
	cout<<" close --------------------------- 0"<<endl;
	cout<<" Choice : ";
}

Client newadd()
{
  int id,years,salary;
  string name;
	Client newpelatis(id,name,years,salary);
	cout<<" dwse id : ";
	cin>>id;
	newpelatis.setid(id);
	cout<<" dwse onoma : ";
	cin>>name;
	newpelatis.setname(name);
	cout<<" dwse xronia douleias : ";
	cin>>years;
	newpelatis.setyears(years);
	cout<<" dwse arxiko mis8o : ";
	cin>>salary;
	newpelatis.setsalary(salary);
	
	return newpelatis;
}

void search(vector <Client> pelatis)
{
	string keyword;
	cout<<" Give a keyword : ";
	cin>>keyword;
	for(int i=0; i<pelatis.size();++i)
	{
		if (pelatis[i].find(keyword))
		{
			pelatis[i].printa();
		}
	}
}

ostream& operator <<(ostream& os, const Client& newpelatis)
{
	os<<"operator <<"<<endl;
	os<<" ***************************************"<<endl;
	os<<" client id -------> "<<newpelatis.getid()<<endl;
  os<<" client name -----> "<<newpelatis.getname()<<endl;
  os<<" years of work ---> "<<newpelatis.getyears()<<endl;
  os<<" starter salary --> "<<newpelatis.getstarter_salary()<<endl;
  os<<" final salary ----> "<<newpelatis.getsalary()<<endl;
	os<<" ***************************************"<<endl;
	return os;
}
