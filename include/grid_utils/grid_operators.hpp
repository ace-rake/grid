#ifndef GRID_OPERATORS_HPP
# define GRID_OPERATORS_HPP


// Operator overloads
#include <iostream>
#include <ostream>
template <typename T>
void	grid<T>::operator=(T other)
{
	this->fill(other);
}

template <typename T>
void	grid<T>::operator=(const grid<T> & other)
{
	if (!other.isMalloced())
		return ;
	for (int y = 0; y < _size_y; y++)
		for (int x = 0; x < _size_x; x++)
		{
			try{ at(y, x) = other.at(y, x);}
			catch(std::out_of_range &e)
			{continue ;}
		}
}


// << operator
template <typename T>
std::ostream& operator<<(std::ostream & o, const grid<T> & g)
{
	size_t xSize = g.getSizeX();
	size_t ySize = g.getSizeY();
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
			std::cout << "[" << g.at(y, x) << "]";
		std::cout << std::endl;
	}
	return o;
}

// Subscript operator
template <typename T>
T * &	grid<T>::operator[](int index) const
{
	if (_outOfYBounds(index))
		_throwOutOfBounds();
	return _grid[index];
}

template <>
inline ostream& operator<<(ostream & o, const grid<bool> & g)
{
	size_t xSize = g.getSizeX();
	size_t ySize = g.getSizeY();
	for (int y = 0; y < ySize; ++y)
	{
		for (int x = 0; x < xSize; ++x)
		{
			std::cout << "[" << (g.at(y, x) == true ? "\033[32;1m1" : "\033[31;1m0") << "\033[0m]";
		}
		std::cout << std::endl;
	}
	return o;
}

#endif

