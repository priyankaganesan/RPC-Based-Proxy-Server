#include "LRU_cache.h"

using namespace std;


//Default Constructor to initialize max_size to default Q_MAX_SIZE
LRU_cache::LRU_cache()
{
	max_size=Q_MAX_SIZE;
	current_size=0;
}

//One parameter Constructor that allows max_size initialization
LRU_cache::LRU_cache(size_t max)
{
	max_size=max;
	current_size=0;
}

bool LRU_cache::is_full(size_t data_size)
{
	if(current_size+data_size>max_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool LRU_cache::insert(string url, string data)
{
	Queue_node* temp;
	if(data.length() > max_size)
	{
		return false;
	}
	while(is_full(data.length()))
	{
		temp=queue.front_node();
		current_size=current_size-temp->size;
		queue_ptr.erase(temp->url);
		queue.remove_front();
	}
	temp=new Queue_node();
	current_size=current_size+data.length();
	cout<<"Response size is   "<<data.length();
	cout<<"Current size is    "<<current_size;
	temp->url=url;
	temp->data=data;
	temp->size=data.length();
	queue.push(temp);
	queue_ptr[url]=temp;
	return true;

}

bool LRU_cache::access_cache(string url, string& data)
{
	Queue_node *temp;
//	bool is_present;
	
	if(queue_ptr.count(url)==0)
	{
		return false;
	}

	else
	{
		temp=queue_ptr[url];
		data=temp->data;
		queue.send_to_back(temp);
		return true;
	}

}

