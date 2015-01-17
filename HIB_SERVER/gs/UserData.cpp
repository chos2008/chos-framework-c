#include "UserData.hpp"

UserData::UserData(char* userId, char* password) {
	this->userId = userId;
	this->password = password;
}

UserData::UserData(char* userId, char* password, char *lastLoginTime) {
	this->userId = userId;
	this->password = password;
	this->lastLoginTime = lastLoginTime;
}