/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/05/28 16:46:02 by mavileo          ###   ########.fr       */
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


		public :
			Node<T> *node;
			size_t _size;
			typedef T value_type;

			list() {}
			~list() {}

			void set_node(Node<T> *n) {
				node = n;
			}

			void push_back(T value) {
				if (!node) {
					Node<T> *n = new Node<T>(value, NULL, NULL);
					n->set_prev(n);
					n->set_next(n);
					node = n;
				}
				else {
					Node<T> *n = new Node<T>(value, node->get_prev(), node);
					node->get_prev()->set_next(n);
					node->set_prev(n);
				}
			}
	};
}
