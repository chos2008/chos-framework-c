/*
 *
 * @author ada
 * @version 1.0 
 * @since 1.0
 */
#include "../AbstractLinkedBarrier.hpp"

#if ! defined __INSTANCE
#define __INSTANCE

/**
 * ����
 */
class Instance 
{
private:

	int id;
	int idx;
	char *name;

    AbstractLinkedBarrier *barrier;

	// ���ͨ���Ĺؿ�
	AbstractLinkedBarrier *lastPassedBarrier;

	// �������Ĺؿ�
    AbstractLinkedBarrier *lastFightedBarrier;

	AbstractLinkedBarrier *lastBarrier;

public:
	Instance();

	Instance(int id, int idx, char* name, AbstractLinkedBarrier *barrier);

    int getId();

	int getIndex();

	char* getName();

	AbstractLinkedBarrier* getBarrier();

    void insert(AbstractLinkedBarrier * barrier);

	AbstractLinkedBarrier * getLastPassedBarrier();

	AbstractLinkedBarrier * getLastFightedBarrier();

    AbstractLinkedBarrier * last();

	void clearGlobal();

	void createGlobalInstance(int instanceId, const char *instanceName, int preInstanceId, const char *awards, const char *constraints, int level, const char *storyline);
};
#endif