#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"

void	test_list() {
	std::cout << "TESTING LIST\n";
	std::cout << "\nCreate a list of 10 int initialised to 1\nft::list<int> lst((size_t)10, (int)1);\n";
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

void	test_stack() {
	std::cout << "TESTING STACK\n";
	std::cout << "\nCreate a stack\n";

	ft::stack<int, ft::list<int> > stack;
	
	std::cout << "Size of stack : " << stack.size() <<std::endl;
	std::cout << "Is stack empty ? " << stack.empty() <<std::endl;

	std::cout << "\nPush 0, 1, 2 and 3\n";
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << "Size of stack : " << stack.size() <<std::endl;
	std::cout << "Is stack empty ? " << stack.empty() <<std::endl;

	std::cout << "\nStack top : " << stack.top() << "\n";
	
	std::cout << "\nPop the stack\n";
	stack.pop();

	std::cout << "\nStack top : " << stack.top() << "\n";

	std::cout << "Size of stack : " << stack.size() <<std::endl;
}


void	test_queue() {
	std::cout << "TESTING QUEUE\n";
	std::cout << "\nCreate a queue\n";

	ft::queue<int, ft::list<int> > queue;
	
	std::cout << "Size of queue : " << queue.size() <<std::endl;
	std::cout << "Is queue empty ? " << queue.empty() <<std::endl;

	std::cout << "\nPush 0, 1, 2 and 3\n";
	queue.push(0);
	queue.push(1);
	queue.push(2);
	queue.push(3);

	std::cout << "Size of queue : " << queue.size() <<std::endl;
	std::cout << "Is queue empty ? " << queue.empty() <<std::endl;

	std::cout << "\nQueue front : " << queue.front() << "\n";
	std::cout << "\nQueue back : " << queue.back() << "\n";
	
	std::cout << "\nPop the queue\n";
	queue.pop();

	std::cout << "\nQueue front : " << queue.front() << "\n";
	std::cout << "\nQueue back : " << queue.back() << "\n";
	
	std::cout << "Size of queue : " << queue.size() <<std::endl;
}


void	test_vector() {
	std::cout << "TESTING VECTOR\n";
	std::cout << "\nCreate a vector on 10 int initialised to 1\nft::vector<int> vect((size_t)10, (int)1);\n";

	ft::vector<int> vect((size_t)10, (int)1);
	std::cout << "\nPrinting the vector vect with the iterator :\n";
	ft::vector<int>::iterator it = vect.begin();

	while (it != vect.end()){
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "Size of vect : " << vect.size() <<std::endl;
	std::cout << "Is vect empty ? " << vect.empty() <<std::endl;

	std::cout << "\nPush back -1\n";
	vect.push_back(-1);

	it = vect.begin();
	
	while (it != vect.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting the vector vect with the reverse iterator :\n";
	
	ft::vector<int>::reverse_iterator rit = vect.rbegin();
	while (rit != vect.rend())
		std::cout << *rit++ << std::endl;
	
	std::cout << "\nModify front value through access function\nvect.front() -= 1;\n";
	vect.front() -= 1;
	
	std::cout << "\nModify back value through access function\nvect.back() = 9;\n";
	vect.back() = 9;
	
	std::cout << "\nvect.front() : " << vect.front() << std::endl;
 	std::cout << "\nvect.back() : " << vect.back() << std::endl;
	
	std::cout << "\nCreate a new vector vect2 and create elements with iterators constructor\nft::vector<int> vect2(vect.begin(), vect.end());\n";
	ft::vector<int> vect2(vect.begin(), vect.end());

	std::cout << "\nPrinting vect2\n";
	it = vect2.begin();
	while (it != vect2.end())
		std::cout << *it++ << std::endl;
	
	std::cout << "\nErase the last half of vect2\n";
	for (int i = 0; i < 5; i++)
		it--;
	vect2.erase(it, vect2.end());

	std::cout << "\nPrinting the vect2\n";
	it = vect2.begin();
	while (it != vect2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nResize vect2 to 3\n";
	vect2.resize(3);

	std::cout << "\nPrinting vect2\n";
	it = vect2.begin();
	while (it != vect2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting vect\n";
	it = vect.begin();
	while (it != vect.end())
		std::cout << *it++ << std::endl;
	
	std::cout << "\nSwap vect and vect2\n";
	vect.swap(vect2);

	std::cout << "\nPrinting vect2\n";
	it = vect2.begin();
	while (it != vect2.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting vect\n";
	it = vect.begin();
	while (it != vect.end())
		std::cout << *it++ << std::endl;

	std::cout << "\nPrinting vect2\n";
	it = vect2.begin();
	while (it != vect2.end())
		std::cout << *it++ << std::endl;

	std::cout << "Size of vect2 : " << vect2.size() <<std::endl;
	std::cout << "Vect2 capacity : " << vect2.capacity() <<std::endl;
}


void	test_map() {
	std::cout << "TESTING MAP\n";
	std::cout << "\nCreate an empty map comtainer\nft::map<std::string, int> map;\n";

	ft::map<std::string, int> map;

	std::cout << "Size of map : " << map.size() <<std::endl;
	std::cout << "Map empty ? : " << map.empty() <<std::endl;

	std::cout << "\nInsert values in map\n";
	map.insert(std::pair<std::string, int>("aaa", 2));
 	map.insert(std::pair<std::string, int>("bbb", 3));
 	map.insert(std::pair<std::string, int>("ccc", 4));
	map.insert(std::pair<std::string, int>("ddd", 5));
	map.insert(std::pair<std::string, int>("a", 1));
	map.insert(std::pair<std::string, int>("zzz", 6));


	std::cout << "\nPrinting map with the iterator :\n";

	ft::map<std::string, int>::iterator it = map.begin();

	while (it != map.end()){
		std::cout << (it)->first << " : " << (it)->second << std::endl;
		it++;
	}

	std::cout << "\nCreate a new empty map map2 and create elements with iterators constructor\nmap2.insert(map.begin(), map.end());\n";

 	ft::map<std::string, int> map2;

	map2.insert(map.begin(), map.end());

	std::cout << "\nPrinting map2 with the iterator :\n";

	ft::map<std::string, int>::iterator it2 = map2.begin();

	while (it2 != map2.end()){
		std::cout << (it2)->first << " : " << (it2)->second << std::endl;
		it2++;}

	std::cout << "\nPrinting map with the reverse iterator :\n";
	
	ft::map<std::string, int>::reverse_iterator rit = map.rbegin();

	while (rit != map.rend()){
		std::cout << (rit)->first << " : " << (rit)->second << std::endl;
		rit++;
	}
	
	std::cout << std::endl;

	std::cout << "Size of map : " << map.size() <<std::endl;
	std::cout << "Map empty ? : " << map.empty() <<std::endl <<std::endl;

	std::cout << "Size of map2 : " << map2.size() <<std::endl;
	std::cout << "Map2 empty ? : " << map2.empty() <<std::endl <<std::endl;


	std::cout << "\nErase the first 3 elements of map\n";
	it = map.begin();
	it++;
	it++;
	it++;

	map.erase(map.begin(), it);

	it = map.begin();

	std::cout << "\nPrinting map :\n";

	while (it != map.end()){
		std::cout << (it)->first << " : " << (it)->second << std::endl;
		it++;
	}

	std::cout << "\nPrinting map2 :\n";

	it = map2.begin();

	while (it != map2.end()){
		std::cout << (it)->first << " : " << (it)->second << std::endl;
		it++;
	}

	std::cout << "\nSwap map and map2 :\n";
	map.swap(map2);

	it = map.begin();

	std::cout << "\nPrinting map :\n";

	while (it != map.end()){
		std::cout << (it)->first << " : " << (it)->second << std::endl;
		it++;
	}

	std::cout << "\nPrinting map2 :\n";

	it = map2.begin();

	while (it != map2.end()){
		std::cout << (it)->first << " : " << (it)->second << std::endl;
		it++;
	}

	std::cout << std::endl;

	std::cout << "Size of map : " << map.size() <<std::endl;
	std::cout << "Map empty ? : " << map.empty() <<std::endl <<std::endl;

	std::cout << "Size of map2 : " << map2.size() <<std::endl;
	std::cout << "Map2 empty ? : " << map2.empty() <<std::endl <<std::endl;

	std::cout << "\nFind element with the key 'a'\n";
	it = map.find("a");
	std::cout << (it)->first << " : " << (it)->second << std::endl;

	std::cout << "\nit = map.lower_bound('aaa');\n";
	it = map.lower_bound("aaa");
	std::cout << (it)->first << " : " << (it)->second << std::endl;

	std::cout << "\nit = map.upper_bound('aaa');\n";
	it = map.upper_bound("aaa");
	std::cout << (it)->first << " : " << (it)->second << std::endl;
}

int main() {
 	std::cout << "\nTESTING FT_CONTAINERS\n\n";

	test_list();

 	std::cout << "\n-----------------------------------\n\n";

	test_stack();

 	std::cout << "\n-----------------------------------\n\n";

	test_queue();

 	std::cout << "\n-----------------------------------\n\n";

	test_vector();

 	std::cout << "\n-----------------------------------\n\n";

	test_map();

 	std::cout << "\n-----------------------------------\n\n";


}
