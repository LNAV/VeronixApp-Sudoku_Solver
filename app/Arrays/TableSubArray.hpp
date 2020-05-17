/*
 * TableSubArray.hpp
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#ifndef APP_ARRAYS_TABLESUBARRAY_HPP_
#define APP_ARRAYS_TABLESUBARRAY_HPP_

#include <cstddef>
#include <cassert>

namespace Veronix
{
namespace App
{
namespace Array
{

//
// TableSubArray has fixed size at construction and represents an row for table.
//
// Memory is stored in a contiguous block.
// begin() and end() "iterators" allow std::algorithm compatibility.
//
// Operator[] is used for 2D indexing.
//
//
template <typename TableType>
class TabularArray;

template <typename rowType>
class TableSubArray
{
public:
	rowType const &operator[](size_t) const;
	rowType &operator[](size_t);
	rowType const *data() const;
	rowType *data();
	rowType const *begin() const;
	rowType *begin();
	rowType const *end() const;
	rowType *end();

private:
	explicit TableSubArray(rowType *, size_t);
	explicit TableSubArray(const TableSubArray &);
	virtual ~TableSubArray();
	const size_t row_size;
	rowType * const row_data;
	friend class TabularArray<rowType>;
};


template<typename rowType>
inline TableSubArray<rowType>::TableSubArray(rowType* row_start, size_t row_size) : row_data(row_start), row_size(row_size)
{
	assert(row_data);
}

template<typename rowType>
inline TableSubArray<rowType>::TableSubArray(const TableSubArray &subArray) : row_data(subArray.row_data), row_size(subArray.row_size)
{
	assert(row_data);
}

template<typename rowType>
inline TableSubArray<rowType>::~TableSubArray()
{

}

template<typename rowType>
inline const rowType& TableSubArray<rowType>::operator [](size_t index) const
{
	if (index < 0 || index >= row_size)
		throw "Out of bound index";

	return row_data[index];
}

template<typename rowType>
inline rowType& TableSubArray<rowType>::operator [](size_t index)
{
	if (index < 0 || index >= row_size)
		throw "Out of bound index";

	return row_data[index];
}

template<typename rowType>
inline const rowType* TableSubArray<rowType>::data() const
{
	return row_data;
}

template<typename rowType>
inline rowType* TableSubArray<rowType>::data()
{
	return row_data;
}

template<typename rowType>
inline const rowType* TableSubArray<rowType>::begin() const
{
	return row_data;
}

template<typename rowType>
inline rowType* TableSubArray<rowType>::begin()
{
	return row_data;
}

template<typename rowType>
inline const rowType* TableSubArray<rowType>::end() const
{
	return row_data + row_size;
}

template<typename rowType>
inline rowType* TableSubArray<rowType>::end()
{
	return row_data + row_size;
}



} /* namespace Array */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_ARRAYS_TABLESUBARRAY_HPP_ */
