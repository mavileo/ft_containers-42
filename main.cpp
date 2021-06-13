#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"

void	print_map(ft::map<std::string, int> map) {
	ft::map<std::string, int>::node_ptr node = map._node;
	ft::map<std::string, int>::node_ptr first_leaf = node;
	size_t i = 1;
	ft::map<std::string, int>::key_type key;

	while (first_leaf->get_left())
		first_leaf = first_leaf->get_left();
	std::cout << first_leaf->get_key() << std::endl;
	key = first_leaf->get_key();
	while (i < map.size()) {
		
	}
}

bool equal(int a, int b) {
  return (a==b);
};

int main() {
 	ft::map<std::string, int> map;

	map.insert(std::pair<std::string, int>("aaa", 2));

	map.insert(std::pair<std::string, int>("bbb", 3));
 	map.insert(std::pair<std::string, int>("ccc", 4));
	map.insert(std::pair<std::string, int>("ddd", 5));
	map.insert(std::pair<std::string, int>("a", 1));
	map.insert(std::pair<std::string, int>("zfhrstj", 6));

	ft::map<std::string, int>::iterator it = map.begin();

	while (it != map.end())
		std::cout << (it++)->second << std::endl;

	it--;
	it--;
	std::cout << (it)->second << std::endl;

}
