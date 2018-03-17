#pragma once

class MeshFactory
{
public:

	template<class T>
	static T* createMesh()
	{
		return new T();
	}
};