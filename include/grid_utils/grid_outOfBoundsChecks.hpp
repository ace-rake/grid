#ifndef GRID_OUTOFBOUNDSCHECKS_HPP
# define GRID_OUTOFBOUNDSCHECKS_HPP


// Out of bounds checks
#include <cstddef>
template <typename T>
bool	grid<T>::_outOfBounds(size_t y, size_t x) const
{
	return _outOfYBounds(y) || _outOfXBounds(x);
}

template <typename T>
bool	grid<T>::_outOfXBounds(size_t x) const
{
	if (x >= _size_x)
		return true;
	return false;
}

template <typename T>
bool	grid<T>::_outOfYBounds(size_t y) const
{
	if (y >= _size_y)
		return true;
	return false;
}

template <typename T>
void	grid<T>::_throwOutOfBounds()const
{
	throw out_of_range("Given co-ordinates do no lie within the grid");
}
#endif

