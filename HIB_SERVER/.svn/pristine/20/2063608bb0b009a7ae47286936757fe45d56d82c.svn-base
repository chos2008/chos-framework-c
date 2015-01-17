#include "BinaryRequest.h"


// 注册
const int BinaryRequest::REG = 45;

// 登录
const int BinaryRequest::LOGIN = 46;

// 地图
const int BinaryRequest::MAP = 47;
	
// 世界
const int BinaryRequest::WORLD = 48;
	
// 剧情
const int BinaryRequest::INSTANCE = 49;
	
// 关卡
const int BinaryRequest::BARRIER = 50;

BinaryRequest::BinaryRequest()
{

}

BinaryRequest::BinaryRequest(int version, int length, int command, int userId)
{
	this->version = version;
	this->length = length;
	this->command = command;
	this->userId = userId;
}

int BinaryRequest::getVersion()
{
	return this->version;
}

void BinaryRequest::setVersion(int version)
{
	this->version = version;
}

int BinaryRequest::getLength()
{
	return this->length;
}

void BinaryRequest::setLength(int length)
{
	this->length = length;
}

int BinaryRequest::getCommand()
{
	return this->command;
}

void BinaryRequest::setCommand(int command)
{
	this->command = command;
}

int BinaryRequest::getUserId()
{
	return this->userId;
}

void BinaryRequest::setUserId(int userId)
{
	this->userId = userId;
}