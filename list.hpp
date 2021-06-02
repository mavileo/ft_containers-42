/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/06/02 19:41:17 by mavileo          ###   ########.fr       */
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
			&value = NULL;
			prev = NULL;
			next = NULL;
			last = true;
		}

		Node(T val, Node<T> *p, Node<T> *n, bool l) {
			value = val;
			prev = p;
			next = n;
			last = l;
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
	class list_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<T>*				pointer;
			typedef Node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t	difference_type;

			list_iterator() {}
			list_iterator(pointer p) {ptr = p;}
			list_iterator &operator= (const list_iterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_iterator() {}

			list_iterator operator ++() { ptr = ptr->get_next(); return (*this); };

			list_iterator operator ++(int)
			{
				list_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			list_iterator operator --() { ptr = ptr->get_prev(); return (*this); };

			list_iterator operator --(int)
			{
				list_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator ==(list_iterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(list_iterator const& b) const { return (ptr != b.ptr); };

			value_type operator *() { return (ptr->get_value()); };
			const_reference operator *() const { return (*(ptr->get_value())); };								// *a
			pointer operator ->() { return (ptr); };											// a->b
			pointer operator ->() const { return (ptr); };	
		private :
			pointer ptr;
	};

	template < class T >
	class list_reverse_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<T>*				pointer;
			typedef Node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t	difference_type;

			list_reverse_iterator() {}
			list_reverse_iterator(pointer p) {ptr = p;}
			list_reverse_iterator &operator= (const list_reverse_iterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_reverse_iterator() {}

			list_reverse_iterator operator ++() { ptr = ptr->get_prev(); return (*this); };

			list_reverse_iterator operator ++(int)
			{
				list_reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			list_reverse_iterator operator --() { ptr = ptr->get_next(); return (*this); };

			list_reverse_iterator operator --(int)
			{
				list_reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			bool operator ==(list_reverse_iterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(list_reverse_iterator const& b) const { return (ptr != b.ptr); };

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
			Node<T> *_last;

			Node<T> *get_last() {
				Node<T> *last = _node;
				
				while (last->get_next() != _last) {
					last = last->get_next();
				}
				return last;
			}

		public :
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename std::size_t							size_type;
			typedef typename std::ptrdiff_t							difference_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;

			typedef typename ft::list_iterator<T>					iterator;
			//typedef typename ft::listConstIterator<T>				const_iterator;
			//typedef typename ft::listReverseIterator<iterator>		reverse_iterator;
			//typedef typename ft::listConstReverseIterator<iterator>	const_reverse_iterator;

			// MEMBER FUNCS
			list() {
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
			}
			~list() {
/* 				if (_node) {
					while (_node != _last) {
						_node = _node->get_next();
						delete _node->get_prev();
					}
				}
				delete _last;
 */			}

			// ITERATORS
			list_iterator<T> begin() {
				return list_iterator<T>(_node);
			}
			list_iterator<T> end() {
				return list_iterator<T>(_last);
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
				return get_last()->get_value();
			}

			// MODIFIERS
			void push_front(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, _last, _last, false);
					_last->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				else {
					Node<T> *n = new Node<T>(value, _last, _node, false);
					_node->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				_size++;
			}
			void pop_front() {
				if (!_node) {
					return ;
				} else if (_node->get_next() == _last) {
					delete _node;
					_node = NULL;
				} else {
					_node->get_next()->set_prev(NULL);
					Node<T> *tmp = _node;
					_node = _node->get_next();
					_last->set_next(_node);
					delete tmp;
				}
				_size--;
			}
			void push_back(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, _last, _last, false);
					_last->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				else {
					Node<T> *last = _last->get_prev();
					Node<T> *n = new Node<T>(value, last, _last, false);
					last->set_next(n);
					_last->set_prev(n);
				}
				_size++;
			}
			void pop_back() {
				if (!_node) {
					return ;
				} else if (_node->get_next() == _last) {
					delete _node;
					_node = NULL;
				} else {
					Node<T> *last = _last->get_prev();
					last->get_prev()->set_next(_last);
					_last->set_prev(last->get_prev());
					delete last;
				}
				_size--;
			}
	};
}
