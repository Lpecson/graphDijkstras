/**
 * @file minpriority.cpp
 * @author Lukas Pecson
 * @description The functions for the minpriority class
 */
#include"minpriority.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
/**
 * @brief the constructor for elements in the minheap
 * @param string i is the id and k is the key for the element
 * @return no return
 */
MinPriorityQueue::Element::Element(const string & i, int k )
{
  this->id = new string(i);
  key = k;
}
/**
 * @brief the destructor for elements
 * @param no params
 * @return no return
 */
MinPriorityQueue::Element::~Element()
{
    delete id;
}
/**
 * @brief the constructor for minQueue
 * @param no params
 * @return no return
 */
MinPriorityQueue::MinPriorityQueue()
{
}
/**
 * @brief the destructor for minQueue, deletes each element in the queue
 * @param no params
 * @return no return
 */
MinPriorityQueue::~MinPriorityQueue()
{
    int size = minHeap.size();
    for( int i=0; i<size; i++ )
    {
        delete minHeap[i];
    }
}
/**
 * @brief builds minHeap using minHeapify
 * @param none
 * @return void
 */
void MinPriorityQueue::buildMinHeap()
{
  for( int i = minHeap.size()/2; i >= 0; i-- )
  {
    minHeapify(i);
  }
}
/**
 * @brief sets the queue to a min heap
 * checks if each node going downward is a min heap
 * @param i is the starting node
 * @return void
 */
void MinPriorityQueue::minHeapify(int i)
{
  int smallest;
  int l = left(i);
  int r = right(i);
  int size = minHeap.size();
  if( l < size && minHeap[l]->key < minHeap[i]->key )
  {
    smallest = l;
  }   
  else
  {
    smallest = i;
  }
  if( r < size && minHeap[r]->key < minHeap[smallest]->key )
  {
    smallest = r;
  }
  if( smallest != i )
  {
    Element* temp = minHeap[i];
    minHeap[i] = minHeap[smallest];
    minHeap[smallest] = temp;
    //exchange minHeap[i] with minHeap[smallest]
    minHeapify(smallest);
   }
}
/**
 * @brief returns the parent of a node
 * @param int i is the index of child we want to find the parent of
 * @return returns index of parent
 */
int MinPriorityQueue::parent(int i)
{
  return i/2;
}
/**
 * @brief returns the left child of a parent node
 * @param int i is the index of parent node
 * @return returns left child
 */
int MinPriorityQueue::left(int i)
{
  return 2*i;
}
/**
 * @brief returns the right child of a parent node
 * @param int i is index of parent node
 * @return returns right child
 */
int MinPriorityQueue::right(int i)
{
  return ( (2*i) + 1);
}
/**
 * @brief inserts an element into the queue
 * @param string id is the name and int key is the priority
 * @return void
 */
void MinPriorityQueue::insert( const string & id, int key)
{
  Element* info = new Element( id, key );
  minHeap.push_back(info);
  decreaseKey(id, key);
}
/**
 * @brief changes the priority key of an element in the queue
 * @param string id is the element in the queue to have its priority changed
 * and int newkey is the new priority
 * @return void
 */
void MinPriorityQueue::decreaseKey( const string & id, int newkey)
{
  int size = minHeap.size();
    for( int i=0; i < size; i++ )
    {
        if( *( minHeap[i]->id ) == id )
        {
            if( minHeap[i]->key > newkey )
            {
                minHeap[i]->key = newkey;
            }
        }
    }
  buildMinHeap();
}
/**
 * @brief returns lowest priority element
 * @param none
 * @return returns the lowest priority element in the Queue
 */
string MinPriorityQueue::extractMin()
{
  if( minHeap.empty() )
  {
    return "empty";
  }
  string minID = *( minHeap[0]->id );
  minHeap.erase( minHeap.begin() );
  minHeapify(0);
  return minID;
}
/**
 * @brief was used in testing not used in real program
 *
 */
void MinPriorityQueue::print()
{
  int size = minHeap.size();
  for( int i=0; i < size; i++ )
  {
    cout << minHeap[i]->id << " " << minHeap[i]->key << endl;
  }
}