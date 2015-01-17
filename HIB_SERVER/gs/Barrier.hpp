#if ! defined BARRIER
#define BARRIER

class Barrier
{

private:
	/** attribute id of fb barrier */
    int fb;

    char* name;

public:
	Barrier(int id, char* name);

	/** get attribute id of fb barrier */
    int get();

	char* getName();

    void pass();
};
#endif