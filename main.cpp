#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "list.hpp"

void	print_lst(ft::list<int> lst) {
	ft::list<int>::iterator it = lst.begin();
	size_t i = 0;
	while (i++ < lst.size()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\n";
}

int main() {
 	ft::list<int> lst;

	lst.push_back(10);
	lst.push_back(2);
	lst.push_front(3);
/*
	std::cout << lst.front() << std::endl;
	std::cout << lst.back() << std::endl << std::endl;

	print_lst(lst);

	lst.pop_front();
	print_lst(lst);
	
	lst.pop_back();
	print_lst(lst);

	lst.pop_front();
	print_lst(lst);
	
	lst.pop_back();
	print_lst(lst);
 */
	ft::list<int>::iterator it = lst.begin();
	while (1) {
		std::cout << *it << std::endl;
		it++;
	}
}