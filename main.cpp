#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "vector.hpp"

void	print_vect(ft::vector<int> vect) {
	ft::vector<int>::iterator it = vect.begin();
	while (it != vect.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\n";
}

void	debug_vect(ft::vector<int> vect) {
	ft::vector<int>::iterator it = vect.begin();
	size_t i = 0;
	if (vect.size() == 0)
		return ;
	while (i < vect.size()) {
		std::cout << i << "/" << vect.size() << std::endl;
		std::cout << *it << std::endl;
		std::cout << std::endl;
		it++;
		i++;
	}
	std::cout << i << "/" << vect.size() << std::endl;
	std::cout << *it << std::endl;
	std::cout << std::endl;
}

bool equal(int a, int b) {
  return (a<=b);
};

int main() {
 	ft::vector<int> vect;

	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	
 	ft::vector<int> vect2;

	vect2.push_back(4);
	vect2.push_back(5);
	vect2.push_back(6);
	

	vect.insert(vect.begin(), vect2.begin(), vect2.end());

	print_vect(vect);

	vect.resize(size_t(10), 0);

	print_vect(vect);

	vect.erase(vect.begin(), vect.begin()+3);

	print_vect(vect);

}
