/**
 * @file graph.cpp
 * @author Lukas Pecson
 * @description The cpp file for the graph class
 */
#include"graph.h"
#include<limits.h>
using std::map;
#include<iostream>
using namespace std;
Graph::Graph()
{
	
}
Graph::~Graph()
{
	map<string, Vertex>:: iterator it;
	for( it = vertices.begin(); it != vertices.end(); it++)
	{
		vertices[it->first].~Vertex();
	}
	map<string, vector<Neighbor>>:: iterator it2;
	for( it2 = adjList.begin(); it2 != adjList.end(); it2++)
	{
		int size = adjList[it2->first].size();
		for( int i=0; i<size; i++ )
		{
			adjList[it2->first][i].~Neighbor();
		}
	}
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
	Neighbor fromAdd = Neighbor(to, weight);//here
	Neighbor toAdd = Neighbor(from, weight);
	bool fromExists = false;
	bool toExists = false;
	if( !adjList.empty() )
	{
		map<string, vector<Neighbor>>:: iterator it;
		for( it = adjList.begin(); it != adjList.end(); it++)
		{
			if( it->first == from )
			{
				fromExists = true;
			}
			if( it->first == to )
			{
				toExists = true;
			}
		}
		if(fromExists)
		{
			adjList[from].push_back(fromAdd);
		}
		else
		{
			vector<Neighbor> add = {fromAdd};
			adjList[from] = add;
		}
		if(toExists)
		{
			adjList[to].push_back(toAdd);
		}
		else
		{
			vector<Neighbor> add = {toAdd};
			adjList[to] = add;
		}
	}
	else
	{
		vector<Neighbor> add = {fromAdd};
		vector<Neighbor> add2 = {toAdd};
		adjList[from] = add;
		adjList[to] = add2;
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



















