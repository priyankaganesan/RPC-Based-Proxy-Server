#include <iostream>
#include <string>
#include <map>
#include "Queue.h"

class fifo
{
	Queue fifo_queue;
	int max_size;
	int current_size;
	string url;
	map<string, Queue_node*> url_to_node;

	public:
	fifo();
	fifo(int cache_size);
	int access_cache(string url, string &response);
	int insert(string url, string response);

	private:
	int is_cache_full(int response_size);
	int url_exists(string url);
	void remove_node();	
};
