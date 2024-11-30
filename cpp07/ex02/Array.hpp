#include <iostream>
#include <exception>

template <typename T>

class Array
{
    private:
        T *arr;
        unsigned int length;
    public:
        Array(){
            arr = new T[0]();
            length = 0;
        }

        Array(unsigned int n)
        {
            arr = new T[n]();
            length = n;
        }

        Array(const Array &copy)
        {
            arr = NULL;
            (*this) = copy;
        }

        Array &operator=(const Array &copy)
        {
            if(arr != NULL)
               delete[] arr;
            length = copy.length;
            arr = new T[length]();

            for (unsigned int  i = 0 ; i < length ; i++)
                arr[i] = copy.arr[i];

            return (*this);
        }

        T &operator[](unsigned int index)
        {
            if (index >= length)
                throw std::out_of_range("Index out of bounds");
            return (arr[index]);
        }

        T operator[](unsigned int index) const
        {
            if (index >= length)
                throw std::out_of_range("Index out of bounds");
            return (arr[index]);
        }
    
        unsigned int size() const
        {
            return (length);
        }

       ~Array()
        { 
            delete[] arr;
        }
};