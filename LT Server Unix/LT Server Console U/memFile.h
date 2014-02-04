#include <cstddef>
#include <iostream>


template <typename T>
class memFile
{
public:
	memFile();
    memFile(T initial_value);

private:
   T memSize;

};

template <typename T>
memFile<T>::memFile()
{	
	memSize = 512;
}

template <typename T>
memFile<T>::memFile(T initial_value)
{
	memSize = initial_value;
}