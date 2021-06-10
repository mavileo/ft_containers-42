#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "map.hpp"

void	print_map(ft::map<std::string, int> map) {
	std::cout << map.get_val() << std::endl;
	std::cout << "\n";
}

bool equal(int a, int b) {
  return (a==b);
};

int main() {
 	ft::map<std::string, int> map;

	map.insert(std::pair<std::string, int>("bbb", 19));
	map.insert(std::pair<std::string, int>("aaa", 18));
	map.insert(std::pair<std::string, int>("ccc", 20));
	map.insert(std::pair<std::string, int>("ddd", 21));
	std::cout << map.get_val() << std::endl;
	std::cout << map._node->get_left() << std::endl;
	std::cout << map._node->get_right() << std::endl;
	std::cout << map._node->get_left()->get_left() << std::endl;
	std::cout << map._node->get_right()->get_right() << std::endl;
	
}
