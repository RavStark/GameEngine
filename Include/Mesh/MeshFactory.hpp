#pragma once

class MeshFactory
{
public:

	template<class T>
	static T* createMesh()
	{
		return new T();
	}
	template<class T>
	static T* createMesh(const char* data)
	{
		return new T(data);
	}
};