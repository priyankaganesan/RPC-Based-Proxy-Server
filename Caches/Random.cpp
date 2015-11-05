#include "Random.h"

Random::Random()
{
	max_size = CACHE_MAX_SIZE;
}

Random::Random(int cache_size)
{
	max_size = cache_size;	
}

int Random::is_cache_full(int response_size)
{
	if (response_size + current_size > max_size){
		return 1;
	}
	return 0;
}

int Random::url_exists(string url)
{
	if (url_to_response.count(url))	{
		return 1;
	}
	return 0;
}

int Random::access_cache(string url, string &response)
{
	if(url_exists(url)){
		response = url_to_response[url];
		return 1;
	}
	return 0;
}

int Random::insert(string url, string response)
{
	int response_size = response.length();
	if (response_size > max_size){
		return 0;
	}
	while(is_cache_full(response_size)){
		remove_node();
	}
	url_to_response[url] = response;
	current_size += response_size;
	url_list.push_back(url);
	return 1;
}

void Random::remove_node()
{
	int index = rand() % url_list.size();
	string url=url_list[index];
	url_list.erase(url_list.begin()+index-1);
	current_size -= (url_to_response[url]).length();
	url_to_response.erase(url);
}