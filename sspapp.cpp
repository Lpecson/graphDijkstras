#include"sspapp.h"
#include"graph.cpp"
#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
SSPapp::SSPapp()
{
	
}
SSPapp::~SSPapp()
{
	
}
void SSPapp::processQueries()
{
	int edgeTotal;
	int vertTotal;
	int count = 0;
	int w;
	string vertName;
	string from;
	string to;
	cin >> vertTotal;
	while( count < vertTotal )
	{
		cin >> vertName;
		count++;
		myGraph.addVertex(vertName);
	}
	cin.ignore();
	count = 0;
	cin >> edgeTotal;
	while( count < edgeTotal )
	{
		cin >> from;
		cin >> to;
		cin >> w;
		cin.ignore();
		myGraph.addEdge(from, to, w);
	}
	while( cin >> from && from != "quit" )
	{
		cin >> to;
		cout << myGraph.getShortestPath(from, to) << endl;
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
