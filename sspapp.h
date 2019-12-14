#ifndef __MSTAPP_
#define __MSTAPP_
#include"minpriority.h"
#include"graph.h"
class SSPapp
{
	public:
	SSPapp();
	~SSPapp();
	void processQueries();
	void readGraph();
	private:
	Graph myGraph;
};
#endif