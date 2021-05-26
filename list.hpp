/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:35:11 by mavileo           #+#    #+#             */
/*   Updated: 2021/05/26 17:47:11 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft {

	template < class T, class Alloc = std::allocator<T> > class list {
		
		public :
			
			typedef T value_type;
			typedef allocator_type = Alloc;
			
			list() {}
			~list() {}
		
			
	}

}