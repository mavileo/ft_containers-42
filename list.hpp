/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/06/02 15:58:16 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

template < class T >
class Node {
	private :
		T value;
		Node *prev;
		Node *next;
		bool last;

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
		void	set_last(bool l) {
			last = l;
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
		bool	*get_last() {
			return last;
		}

};

namespace ft {
	template < class T >
	class listIterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<T>*				pointer;
			typedef Node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t	difference_type;

			listIterator() {}
			listIterator(pointer p) {ptr = p;}
			listIterator &operator= (const listIterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~listIterator() {}

			listIterator operator ++() { ptr = ptr->get_next(); return (*this); };

			listIterator operator ++(int)
			{
				listIterator tmp = *this;
				++(*this);
				return (tmp);
			};

			listIterator operator --() { ptr = ptr->get_prev(); return (*this); };

			listIterator operator --(int)
			{
				listIterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator ==(listIterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(listIterator const& b) const { return (ptr != b.ptr); };

			value_type operator *() { return (ptr->get_value()); };
			const_reference operator *() const { return (*(ptr->get_value())); };								// *a
			pointer operator ->() { return (ptr); };											// a->b
			pointer operator ->() const { return (ptr); };	
		private :
			pointer ptr;
	};

	template < class T, class Alloc = std::allocator<T> > class list {

		private :
			Node<T> *_node;
			size_t _size;

		public :
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename std::size_t							size_type;
			typedef typename std::ptrdiff_t							difference_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;

			typedef typename ft::listIterator<T>					iterator;
			//typedef typename ft::listConstIterator<T>				const_iterator;
			//typedef typename ft::listReverseIterator<iterator>		reverse_iterator;
			//typedef typename ft::listConstReverseIterator<iterator>	const_reverse_iterator;

			// MEMBER FUNCS
			list() {
				_node = NULL;
				_size = 0;
			}
			~list() {}

			// ITERATORS
			listIterator<T> begin() {
				return listIterator<T>(_node);
			}
			listIterator<T> end() {
				return listIterator<T>(_node + _size * sizeof(Node<T>));
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
			value_type front() {
				return _node->get_value();
			}
			value_type back() {
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
