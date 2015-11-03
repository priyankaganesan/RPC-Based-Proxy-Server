#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>

#define CACHE_MAX_SIZE 1048576

using namespace std;

class Random
{
	int max_size;
	int current_size;
	string url;
	string http_response;
	map<string, string> url_to_response;
	std::vector<string> url_list;

	public:
	Random();
	Random(int cache_size);
	int access_cache(string url, string &response);
	int insert(string url, string response);
	
	private:
	int is_cache_full(int response_size);
	int url_exists(string url);
	void remove_node();	
};