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

	print_lst(lst);

	std::cout << "\n";

	lst.pop_front();
	print_lst(lst);
}
