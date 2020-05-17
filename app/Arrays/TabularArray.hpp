/*
 * TabularArray.h
 *
 *  Created on: Dec 31, 2019
 *
 *  This work, "TabularArray", is a derivative of "array2d[1]"
 *  by "jpreiss[2]", used under CC BY(Public Domain).
 *
 * [1]: https://github.com/jpreiss/array2d
 * [2]: https://github.com/jpreiss
 *
 *      Author: LavishK1
 */

#ifndef APP_ARRAYS_TABULARARRAY_HPP_
#define APP_ARRAYS_TABULARARRAY_HPP_

#include "TableSubArray.hpp"

namespace Veronix
{
namespace App
{
namespace Array
{

//
// TabularArray has fixed size at construction.
//
// Memory is stored in a contiguous block.
// begin() and end() "iterators" allow std::algorithm compatibility.
//
// Operator() & [] is used for 2D indexing.
// Arrays are row-major: arr(3, 1)/arr[3][1] and arr(3, 2)/arr[3][2] are consecutive in memory.
//
//
template <typename TableType>
class TabularArray
{
public:
	explicit TabularArray(size_t, size_t);
	explicit TabularArray(const TabularArray &);
	virtual ~TabularArray();
	size_t rows() const;
	size_t columns() const;
	TableSubArray<TableType> const &operator[](size_t) const;
	TableSubArray<TableType> &operator[](size_t);
	TableType const &operator()(size_t, size_t) const;
	TableType &operator()(size_t, size_t);
	TableType const *data() const;
	TableType *data();
	TableType const *begin() const;
	TableType *begin();
	TableType const *end() const;
	TableType *end();

private:
	size_t to1dindex(size_t, size_t) const;
	void initializeSubArrays();
	const size_t table_rows;
	const size_t table_cols;
	TableType *table_data;
	TableSubArray<TableType> **subArrays;
};


template<typename TableType>
TabularArray<TableType>::TabularArray(size_t rows, size_t cols) :
table_rows(rows),
table_cols(cols),
table_data(new TableType[table_rows * table_cols]),
subArrays(nullptr)
{
	initializeSubArrays();
}

template<typename TableType>
TabularArray<TableType>::TabularArray(const TabularArray& tabularArray):
table_rows(tabularArray.table_rows),
table_cols(tabularArray.table_cols),
table_data(new TableType[table_rows * table_cols]),
subArrays(nullptr)
{
	initializeSubArrays();
	for (size_t index = 0; index < table_rows * table_cols; index++)
		table_data[index] = tabularArray.table_data[index];
}

template<typename TableType>
void TabularArray<TableType>::initializeSubArrays()
{
	subArrays = new TableSubArray<TableType> *[table_rows];
	for (size_t index = 0; index < table_rows; index++)
		subArrays[index] = new TableSubArray<TableType>(table_data + index * table_cols, table_cols);
}

template<typename TableType>
TabularArray<TableType>::~TabularArray()
{
	if (table_data)
		delete [] table_data;

	if (subArrays)
	{
		for (size_t index = 0; index < table_rows; index++)
			delete subArrays[index];

		delete [] subArrays;
	}
}

template<typename TableType>
size_t TabularArray<TableType>::rows() const
{
	return table_rows;
}

template<typename TableType>
size_t TabularArray<TableType>::columns() const
{
	return table_cols;
}

template<typename TableType>
size_t TabularArray<TableType>::to1dindex(size_t row, size_t column) const
{
	return row * table_cols + column;
}

template<typename TableType>
const TableSubArray<TableType> &TabularArray<TableType>::operator [](size_t index) const
{
	if(index < 0 || index >= table_rows)
		throw "Out of bound row Index";

	return *subArrays[index];
}

template<typename TableType>
TableSubArray<TableType> &TabularArray<TableType>::operator [](size_t index)
{
	if(index < 0 || index >= table_rows)
		throw "Out of bound row Index";

	return *subArrays[index];
}

template<typename TableType>
const TableType& TabularArray<TableType>::operator ()(size_t row, size_t col) const
{
	if (row < 0 || row >= table_rows || col < 0 || col >= table_cols)
		throw "Out of bound error Array indexes";

	return table_data[to1dindex(row, col)];
}

template<typename TableType>
TableType& TabularArray<TableType>::operator ()(size_t row, size_t col)
{
	if (row < 0 || row >= table_rows || col < 0 || col >= table_cols)
		throw "Out of bound error Array indexes";

	return table_data[to1dindex(row, col)];
}

template<typename TableType>
const TableType* TabularArray<TableType>::data() const
{
	return table_data;
}

template<typename TableType>
TableType* TabularArray<TableType>::data()
{
	return table_data;
}

template<typename TableType>
const TableType* TabularArray<TableType>::begin() const
{
	return table_data;
}

template<typename TableType>
TableType* TabularArray<TableType>::begin()
{
	return table_data;
}

template<typename TableType>
const TableType* TabularArray<TableType>::end() const
{
	return table_data + table_rows * table_cols;
}

template<typename TableType>
TableType* TabularArray<TableType>::end()
{
	return table_data + table_rows * table_cols;
}

} /* namespace Array */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_ARRAYS_TABULARARRAY_HPP_ */
