#pragma once

template<class T>
class Allocator
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef std::true_type propagate_on_container_move_assignment;

	Allocator() throw();
	Allocator(const Allocator&other) throw();

	template<typename U>
	Allocator(const Allocator<U>&other) throw();

	~Allocator() throw();
};