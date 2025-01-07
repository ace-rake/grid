#ifndef GRID_TRANSFORMERS_HPP
# define GRID_TRANSFORMERS_HPP

#include <cstddef>
template <typename T>
void	grid<T>::resize(size_t newY, size_t newX)
{
	grid<T> copy(newY, newX);
	copy = *this;
	_freeGrid();
	_size_y = newY;
	_size_x = newX;
	_createGrid();
	*this = copy;
}

template <typename T>
void	grid<T>::rotate90(bool clockWise)
{
	grid<T> copy(_size_y,_size_x);
	copy = *this;
	resize(_size_x, _size_y);
	for (auto it = copy.begin(); it != copy.end(); it++)
	{
		pair<int, int> p = it.getCoords();
		if (clockWise)
			this->at(p.second, copy.getSizeY() - 1 - p.first) = *it;
		else
			this->at( copy.getSizeY() - 1 - p.second, p.first) = *it;
	}
}

template <typename T>
void	grid<T>::transpose()
{
	grid<T> copy(_size_y,_size_x);
	copy = *this;
	for (auto it = copy.begin(); it != copy.end(); it++)
	{
		pair<int, int> p = it.getCoords();
		this->at(copy.getSizeX() - 1 - p.first, copy.getSizeY() - 1 - p.second) = *it;
	}
}

#endif

/*

011	11213111
1+1	1+111111
112	01111111
111	
113	
111	
111	
111	

3,8

0,0 -> 0,8
1,1 -> 1,7
2,2 -> 2,6
4,2 -> 2,3

y,x -> x, sizeY - y - 1

0,0 -> 2,0
1,1 -> 1,1
2,2 -> 0,2
4,2 -> 0,4

y,x -> x, y

*/
