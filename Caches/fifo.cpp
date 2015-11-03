#include <iostream>
#include <string>
#include <map>
#include "fifo.h"

fifo::fifo()
{
	max_size = Q_MAX_SIZE;
}

fifo::fifo(int cache_size)
{
	max_size = cache_size;	
}

int fifo::is_cache_full(int response_size)
{
	if (response_size + current_size > max_size){
		return 1;
	}
	return 0;
}

int fifo::url_exists(string url)
{
	if (url_to_node.count(url))	{
		return 1;
	}
	return 0;
}

int fifo::access_cache(string url, string &response)
{
	cout<<"url_exists(url)"<<url_exists(url);
	if(url_exists(url)){
		response = url_to_node[url]->data;
		return 1;
	}
	return 0;
}

int fifo::insert(string url, string response)
{
	cout<<endl<<"Insertion happening";
	int response_size = response.length();
	if (response_size > max_size){
		return 0;
	}
	while(is_cache_full(response_size)){
		remove_node();
	}
	Queue_node *node = new Queue_node();
	node->url = url;
	node->data = response;
	node->size = response_size;
	fifo_queue.push(node);
	url_to_node[url] = node;
//	cout<<(url_to_node[url])->url)<<endl;
//	cout<<(url_to_node[url])->data)<<endl;
	current_size += response_size;
	cout<<"Response size is   "<<response_size;
	cout<<"Current size is    "<<current_size;
	return 1;
}

void fifo::remove_node()
{
	fifo_queue.remove_front();
	current_size -= (url_to_node[url])->size;
	url_to_node.erase((url_to_node[url])->url);
}

