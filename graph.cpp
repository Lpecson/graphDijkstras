/**
 * @file graph.cpp
 * @author Lukas Pecson
 * @description The cpp file for the graph class
 */
#include"graph.h"
#include<limits.h>
using std::map;
Graph::Graph()
{
	
}
Graph::~Graph()
{
	
}
Graph::Vertex::Vertex()
{
	pi = NULL;
}
Graph::Vertex::~Vertex()
{
	delete pi;
}
Graph::Neighbor::Neighbor(string n, int w)
{
	name = new string(n);
	weight = w;
}
Graph::Neighbor::~Neighbor()
{
	delete name;
}
void Graph::addVertex(string name)
{
	Vertex* add = new Vertex();
	vertices[name] = *add;
}
void Graph::addEdge( string from, string to, int weight)
{
	Neighbor* add = new Neighbor(to, weight);
	Neighbor* add2 = new Neighbor(from, weight);
	if( !adjList[from].empty() )
	{
		adjList[from].push_back(*add);
	}
	else
	{
		vector<Neighbor> temp;
		temp.push_back(*add);
		adjList.insert(std::pair<string, vector<Neighbor>>(from, temp));		
	}
	if( !adjList[to].empty() )
	{
		adjList[to].push_back(*add2);
	}
	else
	{
		vector<Neighbor> temp2;
		temp2.push_back(*add2);
		adjList.insert(std::pair<string, vector<Neighbor>>(to, temp2));
	}
}
void Graph::buildSSPTree(string source)
{
	string currentSource = source;
	string v = "";
	map<string, Vertex>:: iterator it;
	for( it = vertices.begin(); it != vertices.end(); it++)
	{
		vertices[it->first].key = INT_MAX;
		vertices[it->first].pi = new string("NIL");
		minQ.insert(it->first, INT_MAX);
	}
}
void Graph::relax(string u, string v, int UVweight)
{
	if( vertices[v].key > vertices[u].key + UVweight )
	{
		vertices[v].key = vertices[u].key + UVweight;
		vertices[v].pi = new string(u);
		minQ.decreaseKey( v, vertices[v].key);
	}
}
string Graph::getShortestPath(string from, string to)
{
	buildSSPTree(from);
	vertices[from].key = 0;
	minQ.decreaseKey(from, 0);
	string u = "";
	string v = "";	
	while ((u = minQ.extractMin()) != "empty") {
		int size = adjList[u].size();
		for (int i = 0; i < size; i++) {
			v = *(adjList[u][i].name);
			relax(u, v, adjList[u][i].weight);
		}
	}
	Vertex temp = vertices[to];
	string output = to + " with length " + std::to_string(vertices[to].key);
	while( *(temp.pi) != currentSource )
	{
		output = *(temp.pi) + "->" + output;
		temp = vertices[*(temp.pi)];
	}
	return from + "->" + output;
}
//map<string, Vertex> vertices;
//map<string, vector<Neighbor>> adjList;



















