#include <iostream>
#include <list>
#include <string>
#include <iterator>

int main() {
	std::list<int> lst;
	lst.push_back(1);
	lst.push_front(2);
	std::list<int>::iterator it;
	it = lst.begin();
	std::cout << *it;
	it++;
	std::cout << *it;
	
}
