#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"


void	test_list() {
	std::cout << "TESTING LIST\n";
	std::cout << "\nCreate a list on 10 int initialised to 1\nft::list<int> lst((size_t)10, (int)1);\n";
	std::cout << "\nPrinting the list lst with the iterator :\n";

	ft::list<int> lst((size_t)10, (int)1);
	ft::list<int>::iterator it = lst.begin();
	
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	
	std::cout << "Size of lst : " << lst.size() <<std::endl;
	std::cout << "Is lst empty ? " << lst.empty() <<std::endl;

	std::cout << "\nPush front -1\n";
	lst.push_front(-1);

	it = lst.begin();
	
	while (it != lst.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting the list lst with the reverse iterator :\n";
	
	ft::list<int>::reverse_iterator rit = lst.rbegin();
	while (rit != lst.rend())
		std::cout << *rit++ << std::endl;
	
	std::cout << "\nModify front value through access function\nlst.front() -= 1;\n";
	lst.front() -= 1;
	
	std::cout << "\nModify back value through iterator\n--lst.end() = 10;\n";
	--lst.end() = 10;
 	
	 std::cout << "\nlst.front() : " << lst.front() << std::endl;
 	std::cout << "\nlst.back() : " << lst.back() << std::endl;
	
	std::cout << "\nPushing 11 at the back of the list and pop the front element\n";
	lst.push_back(11);
	lst.pop_front();
	
	std::cout << "\nCreate a new list lst2 and create elements with iterators constructor\nft::list<int> lst2(lst.begin(), lst.end());\n";
	ft::list<int> lst2(lst.begin(), lst.end());

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;
	
	std::cout << "\nErase the last half of lst2\n";
	for (int i = 0; i < 5; i++)
		it--;
	lst2.erase(it, lst2.end());

	std::cout << "\nPrinting the lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nResize lst2 to 3\n";
	lst2.resize(3);

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting lst\n";
	it = lst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	
	std::cout << "\nSwap lst and lst2\n";
	lst.swap(lst2);

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting lst\n";
	it = lst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nRemove elements who have 11 for value in lst2\n";
	lst2.remove((int)11);

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPush front 6, 8, 5 and 7 in lst2\n";
	lst2.push_front(6);
	lst2.push_front(8);
	lst2.push_front(5);
	lst2.push_front(7);

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nSort lst2\n";
	lst2.sort();

	std::cout << "\nPrinting lst2\n";
	it = lst2.begin();
	while (it != lst2.end())
		std::cout << *it++ << std::endl;

	std::cout << "Size of lst2 : " << lst2.size() <<std::endl;
	std::cout << "Is lst2 empty ? " << lst2.empty() <<std::endl;
}

int main() {
 	std::cout << "\nTESTING FT_CONTAINERS\n\n";

	test_list();

 	std::cout << "\n-----------------------------------\n\n";


}
