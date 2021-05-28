#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "list.hpp"

int main() {
	ft::list<int> lst;

	lst.set_node(NULL);
	lst.push_back(10);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << lst.node->get_value() << std::endl;
	std::cout << lst.node->get_next()->get_value() << std::endl;
	std::cout << lst.node->get_next()->get_next()->get_value() << std::endl;
}
