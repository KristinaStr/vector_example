#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>
#include "vector.hpp"





vector_t::vector_t()
{
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
}

vector_t::vector_t(vector_t const & other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new int  [capacity_];
    for ( unsigned int i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }
}

vector_t & vector_t::operator =(vector_t const & other)
{
 if (this !=  &other)
    {
        delete [] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ =  new int [capacity_];
        for (unsigned int i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	 bool success = false;
    if (size_ == other.size_ && capacity_ == other.capacity_)
    {
        success = true;
        for (unsigned int i = 0; i < size_; i++)
        {
            if (data_[i] != other.data_[i])
            {
                success = false;
                break;
            }
        }
    }
    return success;
	
}

vector_t::~vector_t()
{
	delete [] data_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (size_ == capacity_) 
    {
        auto new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;

        int *mas = new int [new_capacity];
        for ( unsigned int i = 0; i < size_; i++)
        {
            mas[i] = data_[i];
        }

        delete [] data_;

        capacity_ = new_capacity;
        data_ = mas;
    }

    data_[size_] = value;
    size_++;
}

void vector_t::pop_back()
{
	if (size == 0) return;
    size -- ;
    if (size == 0 || size_*2 == capacity_)
    {
        int *mas;
        capacity_= capacity_/2;
        mas = new int [ capacity_];
        for (unsigned int i = 0; i < size; i++)
        {
            mas[i] = data_[i];
        }
         delete [] data_;
        mas =  data_;
    }
}

int & vector_t::operator [](std::size_t index)
{

        if(index < size_)
	{
            return (*this)[index];
        }
        else
	{
            throw std::out_of_range("Invalid range") ;
	}	
}

int vector_t::operator [](std::size_t index) const
{
	if(index < size_)
	{
            return (*this)[index];
        }
        else
	{
            throw std::out_of_range("Invalid range") ;
        }
	
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	
    bool success = true;
    if (lhs = rhs)
    {
        success != success;
    }
	return success;
	
}
