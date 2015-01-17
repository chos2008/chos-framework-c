#ifndef BINARY_REQUEST
#define BINARY_REQUEST
class BinaryRequest
{
private:

	int version;

	int length;

	int command;

	int userId;

public:

	// 注册
	static const int REG;
	// 登录
	static const int LOGIN;
	// 地图
	static const int MAP;
	// 世界
	static const int WORLD;
	// 剧情
	static const int INSTANCE;
	// 关卡
	static const int BARRIER;

	BinaryRequest();

	BinaryRequest(int version, int length, int command, int userId);

	int getVersion();

	void setVersion(int version);

	int getLength();

	void setLength(int length);

	int getCommand();

	void setCommand(int command);

	int getUserId();

	void setUserId(int userId);
};
#endif