#if ! defined WORLD_BARRIER 
#define WORLD_BARRIER

class WorldBarrier : public AbstractBarrier 
{

private:
	int x;
	int y;

public:
	WorldBarrier(int y, int y);


};

#endif