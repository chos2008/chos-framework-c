#include <iostream>

using namespace std;

class Clazz
{
public:
	Class()
	{
	
	}
};

class Base
{

public:

    int _base;

    virtual void printinfo()
	{
		cout << "Base::printinfo " << _base << endl;
    }
};

class Derived : public Base
{
public:

	int _derived;

    virtual void printinfo()
    {
		cout << "Derived::printinfo " << _derived << endl;
    }
};

 

int main(void)
{
    
    cout<<"sizeof(Clazz): "<<sizeof(Clazz)<<endl;

	cout<<"----------------------------"<<endl;
    
	Base b1;
	b1.printinfo();

    Derived* pd = static_cast<Derived*>(&b1); // down-casting          不安全
	cout<<"Address of b1:"<<&b1<<", address of pd to point: "<<pd<<"\n";
	pd->printinfo();

	Derived& d = static_cast<Derived&>(b1); // down-casting          不安全
	cout<<"Address of b1:"<<&b1<<", address of d: "<<&d<<"\n";
	d.printinfo();

	//Derived* pd1 = dynamic_cast<Derived*>(&b1); // 编译时有warning，运行时出错

	//Derived& rd = dynamic_cast<Derived&>(b1); // 编译时有warning，运行时出错

	cout<<"----------------------------"<<endl;

	Derived d1;
	d1.printinfo();
    
	Base* pb = static_cast<Base*>(&d1); // up-casting                安全
	cout<<"Address of d1:"<<&d1<<", address of pb to point: "<<pb<<"\n";
    pb->printinfo();

    Base& b = static_cast<Base&>(d1); // up-casting                安全
	cout<<"Address of d1:"<<&d1<<", address of b: "<<&b<<"\n";	
	b.printinfo();

	Base* pb1 = dynamic_cast<Base*>(&d1); // up-casting
	cout<<"Address of d1:"<<&d1<<", address of pb1 to point: "<<pb1<<"\n";
	pb1->printinfo();

	Base &rb = dynamic_cast<Base &>(d1); // up-casting
	cout<<"Address of d1:"<<&d1<<", address of rb: "<<&rb<<"\n";
	rb.printinfo();

	cout<<"----------------------------"<<endl;

    const Base* bBase = new Base();
    Base* cBase = const_cast<Base*>(bBase);
    //Base* dBase = dynamic_cast<Base*>(bBase); // 不能通过编译
    //Base* eBase = static_cast<Base*>(bBase); // 不能通过编译
    //Base* fBase = reinterpret_cast<Base*>(bBase); // 不能通过编译

	int aInt = 10;
    long aLong = 11;

    float aFloat = 11.11f;

    double aDouble = 12.12;


    aInt = static_cast<int>(aFloat); // 基本数据类型转换
    void* sth = static_cast<void*>(&aDouble); // 将double指针类型转换成void指针类型
    double* bDouble = static_cast<double*>(sth); // 将void指针类型转换成double指针类型

    cout << *bDouble << endl;

    int bInt = reinterpret_cast<int>(pb1); // 将地址或指针转换成整数

    cout << bInt << endl;

    pb1 = reinterpret_cast<Base*>(bInt); // 将整数转换成地址或指针

    int* cInt = reinterpret_cast<int*>(&aFloat); // 这个转换的结果会出乎意料

    cout << (int)*cInt << endl;
    return 0;

}