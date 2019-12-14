/**
 * @file graph.h
 * @author Lukas Pecson
 * @description The header file for the graph class
 */
#ifndef __GRAPH_H
#define __GRAPH_H
#include"minpriority.h"
#include<string>
#include<map>
#include<vector>
using std::vector;
using std::map;
using std::string;
class Graph
{
	public:
	Graph();
	~Graph();
	void addVertex(string name);
	void addEdge( string from, string to, int weight);
	string getShortestPath(string from, string to);
	private:
	class Vertex
	{
		public:
		Vertex();
		~Vertex();
		string* pi;//predecessor
		int key;
	};
	class Neighbor
	{
		public:
		Neighbor(string n, int w);
		~Neighbor();
		string* name;
		int weight;//the weight of line
	};
	void buildSSPTree(string source);
	void relax(string u, string v, int UWweight);
	string currentSource;
	map<string, Vertex> vertices;
	map<string, vector<Neighbor>> adjList;
	MinPriorityQueue minQ;
};
#endif