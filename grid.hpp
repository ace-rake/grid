#ifndef GRID_HPP
# define GRID_HPP

#include <cstddef>
#include <stdatomic.h>
#include <utility>
#include <string>

// Custom class: grid
template <typename T>
class	grid
{
	public:
		// Constructor
		grid	(size_t, size_t);

		// Copy constructor
		grid	(grid<T> & other);

		// Destructor
		~grid	(void);

		// Getters
		size_t	getSizeY()const;
		size_t	getSizeX()const;

		
		// Inserters
		void	insert(T, size_t, size_t);
		void	insert(T, std::pair<int, int>);

		void	insertRow(T, size_t);
		void	insertColumn(T, size_t);
		void	fill(T);
		void	insertString(std::string, size_t);

		// Operator overloads
		void	operator=(T other);
		void	operator=(const grid<T> & other);
		T * &	operator[](int)const;

		// Iterator
		class iterator
		{
			public:
				using iterator_category = std::forward_iterator_tag; // Single-pass traversal
				using value_type = T;                                // The type of elements
				using difference_type = std::ptrdiff_t;              // For pointer arithmetic
				using pointer = T*;                                  // Type of a pointer to the value
				using reference = T&;                                // Type of a reference to the value

			public:
				iterator(T ** grid, int x, int y, int size_x, int size_y):_grid(grid), _x(x), _y(y), _size_x(size_x), _size_y(size_y){}
				T & operator*(){ return _grid[_y][_x];}

				iterator& operator++(){
					_x++;
					if (_x >= _size_x)
					{
						_x = 0;
						_y++;
					}
					return *this;
				}
				iterator operator++(int){
					iterator temp = *this;
					++(*this);
					return temp;
				}
				bool operator==(const iterator& other) const {
					return _grid == other._grid && _x == other._x && _y == other._y;
				}

				bool operator!=(const iterator& other) const {
					return !(*this == other);
				}
				std::pair<int, int>	getCoords(){return {_y, _x};}

			private:
				T ** _grid;
				size_t	_x, _y;
				size_t	_size_x, _size_y;

		};

		iterator	begin()const{
			return iterator(_grid, 0, 0, _size_x, _size_y);
		}
		iterator	end()const{
			return iterator(_grid, 0, _size_y, _size_x, _size_y);
		}

		// Accessors
		T &	at(std::pair<int, int>)const;
		T &	at(size_t, size_t)const;
		grid<T>::iterator	search(T)const;

		// Transformers
		void	resize(size_t, size_t);
		void	rotate90(bool clockWise = true);
		void	transpose();
		

	private:
		T **		_grid;
		atomic_bool	_isMalloced = false;
		size_t		_size_y;
		size_t		_size_x;

		bool		_outOfBounds(size_t, size_t)const;
		bool		_outOfXBounds(size_t)const;
		bool		_outOfYBounds(size_t)const;
		void		_throwOutOfBounds()const;

		void		_freeGrid();	// grid_structors.hpp
		void		_createGrid();	// grid_structors.hpp
		void		_deepCopy(grid<T> const &);// grid_structors.hpp

};

using namespace std;

#include "grid_structors.hpp"

#include "grid_getters.hpp"

#include "grid_accessors.hpp"

#include "grid_operators.hpp"

#include "grid_inserters.hpp"

#include "grid_outOfBoundsChecks.hpp"

#include "grid_transformers.hpp"

#endif

