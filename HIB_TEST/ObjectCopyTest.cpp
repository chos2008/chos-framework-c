#include <stdio.h>

class ObjectCopyClass
{
	private:

	public:
		ObjectCopyClass()
		{
			printf("ObjectCopyClass()\n");
		}

//		/*
		ObjectCopyClass(const ObjectCopyClass &o)
		{
			printf("ObjectCopyClass(const ObjectCopyClass &o)\n");
		}
//		*/
		
		~ObjectCopyClass()
		{
			printf("~ObjectCopyClass()\n");
		}

//		/*
		//TString& TString::operator=(const TString& s)
		ObjectCopyClass& operator=(const ObjectCopyClass &o)
		{
			printf("ObjectCopyClass& operator=(const ObjectCopyClass &o)\n");
			//this->data = s.data;
			return *this;
		}
//		*/
};

int main()
{
	ObjectCopyClass obj1;
	printf("address of obj1: %d\n", &obj1);

	ObjectCopyClass &_obj1 = obj1;
	printf("address of _obj1: %d\n", &_obj1);

	ObjectCopyClass obj2 = obj1;
	printf("address of obj2: %d\n", &obj2);

	obj2 = obj1;
	printf("address of obj2: %d\n", &obj2);

	ObjectCopyClass *p_obj1 = &obj1;
	printf("address of p_obj1: %d\n", &p_obj1);
	printf("address of p_obj1 point to: %d\n", p_obj1);

	ObjectCopyClass *p_obj2 = new ObjectCopyClass();
	printf("address of p_obj2: %d\n", &p_obj2);
	printf("address of p_obj2 point to: %d\n", p_obj2);
	delete p_obj2;
	return 0;
}