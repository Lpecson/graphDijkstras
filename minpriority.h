/**
 * @file minpriority.h
 * @author Lukas Pecson
 * @description The header file for the minpriority class
 */
#ifndef __MINPRIORITY_H
#define __MINPRIORITY_H
#include<vector>
#include<string>
using std::string;
class MinPriorityQueue
{
	public:
	MinPriorityQueue();
	~MinPriorityQueue();
	void insert( const string & id, int key);
	void decreaseKey( const string & id, int newkey);
	string extractMin();
    void print();
	private:
	class Element
	{
		public:
		string* id;
		int key;
		Element();
		Element(const string & i, int k );
		~Element();
	};
	std::vector<Element*> minHeap;
	void buildMinHeap();
	void minHeapify(int i);
	int parent(int i);
	int left(int i);
	int right(int i);

};
#endif