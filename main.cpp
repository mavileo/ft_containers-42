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

 	ft::map<std::string, int> map2;

	map2.insert(map.begin(), map.end());

	ft::map<std::string, int>::iterator it = map.begin();
	it++;
	it++;
	it++;

	map.erase(map.begin(), it);

	it--;
	it--;
	it--;


	ft::map<std::string, int>::iterator it0 = map.begin();

	while (it0 != map.end()){
		std::cout << (it0)->second << std::endl;
		it0++;}


	std::cout << "\n";

	ft::map<std::string, int>::iterator it2 = map2.begin();

	while (it2 != map2.end()){
		std::cout << (it2)->second << std::endl;
		it2++;}

	map.swap(map2);
	std::cout << "\n";
	std::cout << "\n";

	ft::map<std::string, int>::iterator it3 = map.begin();

	while (it3 != map.end()){
		std::cout << (it3)->second << std::endl;
		it3++;}

	std::cout << std::endl;

	ft::map<std::string, int>::iterator it4 = map2.begin();

	while (it4 != map2.end()){
		std::cout << (it4)->second << std::endl;
		it4++;}


}
