#include "list.hpp"

namespace ft {

	template <class T, class Container = list<T> >
	class queue {

		public :
			typedef T													value_type;
			typedef Container											container_type;
			typedef typename std::size_t								size_type;

			explicit queue (const container_type& ctnr = container_type()) {
				(void)ctnr;
				container_type lst;
				_lst = lst;
			}

			bool empty() const {
				return _lst.empty();
			}

			size_type size() const {
				return _lst.size();
			}

			value_type& front() {
				return _lst.front();
			}

			const value_type& front() const {
				return _lst.front();
			}

			value_type& back() {
				return _lst.back();
			}

			const value_type& back() const {
				return _lst.back();
			}

			void push (const value_type& val) {
				_lst.push_back(val);
			}

			void pop() {
				_lst.pop_front();
			}

		private :
			container_type _lst;

	};

	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs == rhs);
	}

	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs != rhs);
	}

	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs < rhs);
	}

	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs <= rhs);
	}

	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs > rhs);
	}

	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return (lhs >= rhs);
	}

}