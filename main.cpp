#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "queue.hpp"

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
 	ft::queue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	
	std::cout << queue.front() << std::endl;
	std::cout << queue.back() << std::endl;

	queue.front() += queue.back();

	std::cout << queue.front() << std::endl;
	std::cout << queue.back() << std::endl;
	std::cout << std::endl;
}
