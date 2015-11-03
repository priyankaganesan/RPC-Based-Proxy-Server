#include "Queue.h"

class LRU_cache
{
	private:
		size_t max_size; //Maximum size of cache
		size_t current_size; //Current size of cache
		Queue queue;
		map<string, Queue_node*> queue_ptr;
		

	public:
		//Default Constructor to initialize max_size to default MAX
		LRU_cache();

		//One parameter Constructor that allows max_size initialization
		LRU_cache(size_t max);

		bool is_full(size_t data_size);

		bool insert(string url, string data);

		bool access_cache(string url, string& data);

};