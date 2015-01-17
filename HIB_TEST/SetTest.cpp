#include <set>

void main()
{
	std::set<int> sc;
	for (int i = 0; i < 10; i++) 
	{
		sc.insert(i);
	}

	std::set<int>::iterator iter;
	
	/*
	for (iter = sc.begin(); iter != sc.end(); ++iter) 
	{
		
		//if (*iter == 3) 
		//{
		//	printf("%d\n", *iter);
		//	sc.erase(iter);
		//}
	}
	*/

	std::set<int>::iterator t = NULL;
	for (iter = sc.begin(); iter != sc.end(); iter++) 
	{
		if (*iter == 3) 
		{
			t = iter;
			break;
		}
	}
	if (t != NULL) 
	{
		sc.erase(t);
	}

	/*
	iter = sc.begin();
	for (; sc.size(); ) 
	{
		//if (*iter == 3) 
		//{
			std::set<int>::iterator t = iter;
			iter++;
		
			sc.erase(t);
		//}
		
	}
	*/

	/*
	iter = sc.find(3);
	sc.erase(iter);
	*/

	for (iter = sc.begin(); iter != sc.end(); ++iter) 
	{
		printf("%d \t", *iter);
	}
}