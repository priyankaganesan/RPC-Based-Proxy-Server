#include <iostream>
#include <string.h>
#include <cstring>
#include <map>
#include <stdbool.h>

#define Q_MAX_SIZE 1040983249

using namespace std;

struct Queue_node
{
	string data;
	string url;
	size_t size;
	Queue_node *next;
	Queue_node *prev;

};

class Queue
{
	private:
		Queue_node* front;
		Queue_node* back;

	public:
		Queue()
		{
			front=back=NULL;
		}

		//Pushes element to the back of the queue.
		void push(Queue_node* node)
		{
			if(node==NULL)
				return;

			if(front==NULL)
			{
				front=back=node;
				node->next=NULL;
				node->prev=NULL;
			}
			else
			{
				back->next=node;
				node->prev=back;
				back=node;
				node->next=NULL;
			}

		}

		Queue_node* front_node()
		{
			return front;
		}

		//The front of the queue is the LRU/LFU position. Removes the front node from the queue.
		void remove_front()
		{
			Queue_node* temp=front;
			if(temp==NULL)
				return;
			if(front==back)
			{
				front=back=NULL;
				delete temp;
				return;
			}
			front=front->next;
			front->prev=NULL;
			delete temp;
			return;
		}

		void send_to_back(Queue_node* node)
		{
			if(node==NULL)
			{
				return;
			}
			if(front==NULL||back==NULL)
			{
				return;
			}

			if(node==front && node==back)
			{
				return;
			}
			else if(node==front)
			{
				front=front->next;
				front->prev=NULL;
				back->next=node;
				node->next=NULL;
				node->prev=back;
				back=node;
				return;
			}
			else if(node==back)
			{
				return;
			}

			else
			{
				node->next->prev=node->prev;
				node->prev->next=node->next;
				back->next=node;
				node->prev=back;
				node->next=NULL;
				back=node;
				return;
			}

		}

};


