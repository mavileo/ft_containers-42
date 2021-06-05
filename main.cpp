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
	if (lst.size() == 0)
		return ;
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

bool equal(int a, int b) {
  return (a<=b);
};

int main() {
 	ft::list<int> lst;
 	ft::list<int> lst2;
 	
	lst.push_back(1);
	lst.push_back(10);
	lst.push_back(2);
	lst.push_back(7);
	lst.push_back(3);
	lst2.push_back(6);
	lst2.push_back(9);
	lst2.push_back(8);
	lst2.push_back(4);
	print_lst(lst);
	print_lst(lst2);

	lst.merge(lst2, equal);

	print_lst(lst);
	print_lst(lst2);

/*	print_lst(lst);
	*it = 99;
	std::cout << *it << std::endl;
	std::cout << std::endl;
 */	
}