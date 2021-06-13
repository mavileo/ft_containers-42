#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"


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

	while (it != map.end()){
		std::cout << (it)->second << std::endl;
		it++;}

 	it--;
 	it--;
 	it--;
	map.erase(map.begin(), it);

	std::cout << std::endl;

	ft::map<std::string, int>::iterator it2 = map.begin();

	while (it2 != map.end()){
		std::cout << (it2)->second << std::endl;
		it2++;}


}
