#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "list.hpp"

void	print_lst(ft::list<int> lst) {
	Node<int> *tmp = lst.begin();
	for (int i = 0; i < int(lst.size()); i++) {
		std::cout << tmp->get_value();
		tmp = tmp->get_next();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	ft::list<int> lst;

	lst.push_back(10);
	lst.push_back(2);
	lst.push_front(3);

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
}
