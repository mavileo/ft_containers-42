#include "queue.hpp"

namespace ft {

	template <class T, class Container = list<T> >
	class stack {

		public :
			typedef T													value_type;
			typedef Container											container_type;
			typedef typename std::size_t								size_type;

			explicit stack (const container_type& ctnr = container_type()) {
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

			value_type& top() {
				return _lst.back();
			}

			const value_type& top() const {
				return _lst.back();
			}

			void push (const value_type& val) {
				_lst.push_back(val);
			}

			void pop() {
				_lst.pop_back();
			}

		private :
			container_type _lst;

	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs == rhs);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs != rhs);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs < rhs);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs <= rhs);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs > rhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs >= rhs);
	}

}