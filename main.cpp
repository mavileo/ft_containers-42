#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "list.hpp"

void	print_lst(ft::list<int> lst) {
	ft::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\n";
}

void	debug_lst(ft::list<int> lst) {
	ft::list<int>::iterator it = lst.begin();
	size_t i = 0;
	while (i < lst.size()) {
		std::cout << i << "/" << lst.size() << std::endl;
		std::cout << *it << std::endl;
		std::cout << "Is last : " << it->get_last() << std::endl;
		std::cout << std::endl;
		it++;
		i++;
	}
	std::cout << i << "/" << lst.size() << std::endl;
	std::cout << *it << std::endl;
	std::cout << "Is last : " << it->get_last() << std::endl;
	std::cout << std::endl;
}

int main() {
 	ft::list<int> lst(3, 2);

	debug_lst(lst);

	ft::list<int>::iterator it = lst.begin();
	lst.erase(it++);
	debug_lst(lst);
	lst.erase(it++);
	debug_lst(lst);
	lst.erase(it++);
	std::cout << "OOOO " << lst.begin()->get_value() << " IIIII\n";
	debug_lst(lst);
/*	print_lst(lst);
	*it = 99;
	std::cout << *it << std::endl;
	std::cout << std::endl;
 */	
}