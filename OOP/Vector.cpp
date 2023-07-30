// Vector Implementation using Template and OOP

#include <iostream>
using namespace std;

// Using template to create dynamic type vectors
template <typename T>
class MyVector
{
    size_t size;
    size_t capacity;

    T *array;

    // Doubling capacity of vector
    void resize()
    {
        if (size == capacity)
        {
            capacity = 0 ? 1 : capacity * 2;
            T *newArray = new T[capacity];

            for (size_t i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
        }
    }

public:
    // Constructor to initialize vector
    MyVector()
    {
        size = 0;
        capacity = 0;

        array = new T[capacity];
    }

    // Constructor to initialize vector with size and value
    MyVector(size_t size, T defaultValue = 0)
    {
        this->size = size;
        this->capacity = size;

        array = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            array[i] = defaultValue;
        }
    }

    // Deep copy constructor for one vector into other
    MyVector(MyVector<T> &copyVector)
    {
        size = copyVector.size;
        capacity = copyVector.capacity;

        array = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            array[i] = copyVector.array[i];
        }
    }

    // adding element to end of vector
    void push_back(T val)
    {
        resize();

        array[size] = val;
        size++;
    }

    // Removing last element from vector
    void pop_back()
    {
        if (size > 0)
        {
            size--;
        }
    }

    // Operator overloading (static polymorphism)
    T operator[](int idx)
    {
        return array[idx];
    }

    // Operator overloading (static polymorphism)
    T at(int idx)
    {
        return array[idx];
    }

    size_t getSize()
    {
        return size;
    }

    // Printing vector
    void printVector()
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
    
    // As array is dynamically allocated, deleting memory using destructor
    ~MyVector()
    {
        delete[] array;
    }
};

int main()
{
    MyVector<string> vector0(2, "Suyog");
    vector0.push_back("Yash");
    vector0.push_back("Sudesh");
    vector0.printVector();


    MyVector<int> vector1;
    vector1.push_back(15);
    vector1.printVector();


    // Calling copy(deep) constructor
    MyVector<int> vector2 = vector1;
    // MyVector<int> vector2(vector1);

    vector2.printVector();
}
