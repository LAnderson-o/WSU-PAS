#ifndef TESTS
#define TESTS
#include "queue.hpp"

class Tests {
public:
	bool emptyEnqueue(Data newData);
	bool singleEnqueue(Data newData);
	bool singleDequeue();
	bool doubleDequeue();
	void runSim24();
	void runSim(int length);

	bool runTests();
private:
};

#endif
