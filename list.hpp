/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/06/04 20:24:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include "reverse_iterator.hpp"

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
		bool	get_last() {
			return last;
		}
		Node	*get_ptr() {
			return this;
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

			list_iterator operator =(value_type val)
			{
				ptr->set_value(val);
				return this;
			};

			bool operator ==(list_iterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(list_iterator const& b) const { return (ptr != b.ptr); };

			value_type operator *() { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); };
			const_reference operator *() const { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); };
			pointer operator ->() { return (ptr); };
			pointer operator ->() const { return (ptr); };

			pointer get_ptr() { return ptr; };
		private :
			pointer ptr;
	};
	template < class T, class Alloc = std::allocator<T> >
	class list {

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
			typedef typename ft::list_reverse_iterator<iterator>	reverse_iterator;
			//typedef typename ft::listConstReverseIterator<iterator>	const_reverse_iterator;

			// MEMBER FUNCS
			explicit list (const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
			}
			explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
				while (n--)
					this->push_back(val);
			}
/*
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				for (iterator it = first; it != last; it++)
					this->push_back(*it);
			};

			list (const list& x) {
				ft::list<T> new_list(x.begin(), x.start());
				*this = new_list;
			}
 */
			~list() {
				//this->clear();
				//delete _last;
			}

			// ITERATORS
			iterator begin() {
				return (_last->get_prev()) ? iterator(_node) : iterator(_last);
			}
			reverse_iterator rbegin() {
				return (_last->get_prev()) ? reverse_iterator(_last->get_prev()) : iterator(_last);
			}
			iterator end() {
				return iterator(_last);
			}
			reverse_iterator rend() {
				return reverse_iterator(_last);
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
				return _last->get_prev()->get_value();
			}

			// MODIFIERS
			void assign(T value) {
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
			iterator erase (iterator position)
			{
				iterator ret = position->get_next();
				_pop_node(position);
				return (ret);
			};
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
				return (last);
			};
			void swap (list& x) {
				Node<T> *n = _node;
				size_t s = _size;
				Node<T> *l = _last;
				
				_node = x._node;
				_size = x._size;
				_last = x._last;

				x._node = n;
				x._size = s;
				x._last = l;
			}
			void resize (size_type n, value_type val = value_type()) {
				if (_size < n)
					while (_size < n)
						this->push_back(val);
				else
					while (_size > n)
						this->pop_back();
			}
			void clear() {
				if (!_node) {
					return ;
				} else {
					_node = _node->get_next();
					while (_node != _last) {
						delete _node->get_prev();
						_node = _node->get_next();
					}
					delete _node->get_prev();
					_node = NULL;
					_last->set_prev(NULL);
					_last->set_next(NULL);
					_size = 0;
				}
			}

		private :
			Node<T> *_node;
			size_t _size;
			Node<T> *_last;

			void _pop_node(int pos) {
				int i = 0;
				Node<T> *tmp = _node;
				
				if (pos < 0 || _size < 1 || pos > _size)
					return ;
				while (i++ < pos)
					tmp = tmp->get_next();
				if (tmp->get_prev() == _last && tmp->get_next() == _last)
					return this->clear();
				tmp->get_prev()->set_next(tmp->get_next());
				tmp->get_next()->set_prev(tmp->get_prev());
				delete tmp;
				_size--;
			}

			void _pop_node(iterator it) {
				if (it->get_ptr() == _node)
					_node = _node->get_next();
				if (it->get_prev() == _last && it->get_next() == _last)
					return this->clear();
				it->get_prev()->set_next(it->get_next());
				it->get_next()->set_prev(it->get_prev());
				delete it->get_ptr();
				_size--;
			}

	};
}
