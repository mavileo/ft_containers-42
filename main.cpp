#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "stack.hpp"

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
 	ft::stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	
	std::cout << stack.top() << std::endl;
	stack.pop();
	stack.top() += 2;
	std::cout << stack.top() << std::endl;

	std::cout << std::endl;
}
