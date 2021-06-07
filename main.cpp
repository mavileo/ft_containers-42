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
	size_t s = 2;
	int i = 1;

 	ft::list<int> lst;
 	ft::list<int> lst2(s, i);
 	ft::list<int> lst3(lst2.begin(), lst2.end());

	lst.push_back(i);
	lst.push_back(i);
	lst.push_back(i);
	print_lst(lst);
	print_lst(lst2);
	print_lst(lst3);
	
	std::cout << (lst2 >= lst3);


/*	print_lst(lst);
	*it = 99;
	std::cout << *it << std::endl;
	std::cout << std::endl;
 */	
}
