/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/05/28 18:01:44 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

template < class T>
class Node {
	private :
		T value;
		Node *prev;
		Node *next;
	
	public :
		Node() {
			value = 0;
			prev = NULL;
			next = NULL;
		}
		
		Node(T val, Node<T> *p, Node<T> *n) {
			value = val;
			prev = p;
			next = n;
		}
		
		~Node() {}

		void	set_value(T val) {
			value = val;
		}
		void	set_prev(Node<T> *prevPtr) {
			prev = prevPtr;
		}
		void	set_next(Node<T> *nextPtr) {
			next = nextPtr;
		}

		T	get_value() {
			return value;
		}
		Node	*get_prev() {
			return prev;
		}
		Node	*get_next() {
			return next;
		}
		
};


namespace ft {

	template <class T> class list {
		
		private :
			Node<T> *_node;
			size_t _size;

		public :
			typedef T value_type;

			list() {
				_node = NULL;
				_size = 0;
			}
			~list() {}

			// ITERATORS
			Node<T> *begin() {
				return _node;
			}

			// CAPACITY
			bool empty() {
				if (_size)
					return false;
				return true;
			}
			size_t size() {
				return _size;
			}
			size_t max_size() {
				return std::numeric_limits<size_t>::max() / (sizeof(value_type));
			}			

			// ELEMENT ACCESS
			T front() {
				return _node->get_value();
			}
			T back() {
				return _node->get_prev()->get_value();
			}

			// MODIFIERS
			void push_front(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, NULL, NULL);
					n->set_prev(n);
					n->set_next(n);
					_node = n;
				}
				else {
					Node<T> *n = new Node<T>(value, _node->get_prev(), _node);
					_node->get_prev()->set_next(n);
					_node->set_prev(n);
					_node = n;
				}
				_size++;
			}
			void pop_front() {
				if (!_node) {
					return ;
				} else if (_node == _node->get_prev()) {
					delete _node;
					_node = NULL;
				} else {
					_node->get_prev()->set_next(_node->get_next());
					_node->get_next()->set_prev(_node->get_prev());
					Node<T> *tmp = _node;
					_node = _node->get_next();
					delete tmp;
				}
				_size--;
			}
			void push_back(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, NULL, NULL);
					n->set_prev(n);
					n->set_next(n);
					_node = n;
				}
				else {
					Node<T> *n = new Node<T>(value, _node->get_prev(), _node);
					_node->get_prev()->set_next(n);
					_node->set_prev(n);
				}
				_size++;
			}
			void pop_back() {
				if (!_node) {
					return ;
				} else if (_node == _node->get_prev()) {
					delete _node;
					_node = NULL;
				} else {
					Node<T> *tmp = _node->get_prev();
					_node->get_prev()->get_prev()->set_next(_node);
					_node->set_prev(_node->get_prev()->get_prev());
					delete tmp;
				}
				_size--;
			}

	};
}
