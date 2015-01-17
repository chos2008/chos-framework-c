#include <stdio.h>
#include <assert.h>
#include "../gs/Account.h"

Account testCreateAccount()
{
	char *id = "111", *password = "111";
	Account account(id, password);
	account.create();

	printf("Account id: %s, password: %s\n", account.getId(), account.getPassword());
	return account;
}

Account& testCreateAccountReturnReference()
{
	char *id = "222", *password = "222";
	Account account(id, password);
	account.create();

	printf("Account id: %s, password: %s\n", account.getId(), account.getPassword());
	return account;
}

Account* testCreateAccountReturnPoint()
{
	char *id = "333", *password = "333";
	Account account(id, password);
	account.create();

	printf("Account id: %s, password: %s\n", account.getId(), account.getPassword());
	return &account;
}

Account testCreateAccountWithNew()
{
	char *id = "444", *password = "444";
	Account *account = new Account(id, password);
	account->create();

	printf("Account id: %s, password: %s\n", account->getId(), account->getPassword());
	return *account;
}

Account& testCreateAccountWithNewReturnReference()
{
	char *id = "555", *password = "555";
	Account *account = new Account(id, password);
	account->create();

	printf("Account id: %s, password: %s\n", account->getId(), account->getPassword());
	return *account;
}

Account* testCreateAccountWithNewReturnPoint()
{
	char *id = "666", *password = "666";
	Account *account = new Account(id, password);
	account->create();

	printf("Account id: %s, password: %s\n", account->getId(), account->getPassword());
	return account;
}

int main()
{
	char*id = "111";
	char &id1 = (char &) id;
	char &id11 = (char &) *id;
	printf("Address of id: %ld\n", &id);
	printf("address of id to point: %ld\n", id);
	printf("value of address of id to point: %s\n", id);
	printf("address of id1: %ld\n", &id1);
	//printf("value of address of id1 to reference: %s\n", id1); // error, not read
	printf("address of id11: %ld\n", &id11);
	//printf("value of address of id11 to reference: %s\n", id11); // error, not read
	printf("..............\n");

	id = "222";
	char &id2 = (char &) id;
	char &id22 = (char &) *id;
	printf("Address of id: %ld\n", &id);
	printf("address of id to point: %ld\n", id);
	printf("value of address of id to point: %s\n", id);
	printf("address of id1: %ld\n", &id2);
	//printf("value of address of id1 to reference: %s\n", id2); // error, not read
	printf("address of id22: %ld\n", &id22);
	//printf("value of address of id22 to reference: %s\n", id22); // error, not read
	printf("..............\n");

	// error C2440: 'initializing' : cannot convert from 'const int' to 'class Account'
	//Account account01 = NULL;

	// error C2440: 'initializing' : cannot convert from 'const int' to 'class Account &'
	//Account &account02 = NULL;

	Account *account03 = NULL;

	Account account1 = testCreateAccount();
	assert(&account1 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(account1 != NULL);
	printf("Account id: %s, password: %s\n", account1.getId(), account1.getPassword());

	Account &account2 = testCreateAccountReturnReference();
	assert(&account2 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(account2 == NULL);
	//assert(account2 != account1); // error, not read
	assert(&account2 != &account1); // ok
	//printf("Account id: %s, password: %s\n", account2.getId(), account2.getPassword()); // error, not read

	Account *account3 = testCreateAccountReturnPoint();
	assert(account3 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(*account3 == NULL);
	//assert(*account3 != account1); // error, not read
	assert(account3 != &account1); // ok
	//printf("Account id: %s, password: %s\n", account3->getId(), account3->getPassword()); // error, not read

	Account account4 = testCreateAccountWithNew();
	assert(&account4 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(account4 == NULL);
	assert(account4 != account1); // ok
	assert(&account4 != &account1); // ok
	printf("Account id: %s, password: %s\n", account4.getId(), account4.getPassword()); // error, not read

	Account &account5 = testCreateAccountWithNewReturnReference();
	assert(&account5 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(account5 == NULL);
	assert(account5 != account4); // ok
	assert(&account5 != &account4); // ok
	//printf("Account id: %s, password: %s\n", account5.getId(), account5.getPassword()); // error, not read

	Account *account6 = testCreateAccountWithNewReturnPoint();
	assert(account6 != NULL);
	// 如果没有重载 != 操作符运算，则在编译时报：
	// error C2676: binary '!=' : 'class Account' does not define this operator or a conversion to a type acceptable to the predefined operator
	// 错误。
	//assert(*account6 == NULL);
	assert(*account6 != account5); // ok
	assert(account6 != &account5); // ok
	//printf("Account id: %s, password: %s\n", account6->getId(), account6->getPassword()); // error, not read

	printf("exit!\n");
	return 1;
}