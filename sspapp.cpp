#include"sspapp.h"
#include"graph.cpp"
#include<string>
#include<iostream>
using std::string;
using std::cin;
SSPapp::SSPapp()
{
	
}
SSPapp::~SSPapp()
{
	
}
void SSPapp::processQueries()
{
	int vibecheck = 0;
	string input;
	int nameNum = 0;
	int edgeNum = 0;
	int vertNum;
	int edgeTotal;
	string t;
	string f;
	int w;
	while( cin >> input)
	{
		if( input == "quit" )
		{
			return;
		}
		if(vibecheck == 0)//num of vertices
		{
			vertNum = std::stoi(input);
			vibecheck++;
		}
		if(vibecheck == 1)//alphanumeric vertex identifiers
		{
			while( nameNum < vertNum )
			{
				cin >> input;
				myGraph.addVertex(input);
				nameNum++;
			}
			vibecheck++;
		}
		if(vibecheck == 2)//num of edges
		{
			edgeTotal = std::stoi(input);
			vibecheck++;
		}
		if(vibecheck == 3)//list of edges [vert vert len]
		{
			while( edgeNum < edgeTotal )
			{
				cin >> f;
				cin >> t;
				cin >> w;
				myGraph.addEdge(f,t,w);
				edgeNum++;
			}
			vibecheck++;
		}
		if(vibecheck > 3)// List of queries
		{
			string to;
			string from;
			cin >> from;
			cin >> to;
			std::cout << myGraph.getShortestPath(from, to) << std::endl;
			vibecheck++;
		}
	}
	return;
}
void SSPapp::readGraph()
{
	
}
int main()
{
	SSPapp myApp;
	myApp.processQueries();
	return 0;
}
