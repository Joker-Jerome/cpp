#include <iostream>
 
template <class T>
T average(T *array, int length)
{
    T sum = 0;
    for (int count=0; count < length; ++count)
        sum += array[count];
 
    sum /= length;
    return sum;
}
 
int main()
{
    int array1[] = { 5, 3, 2, 1, 4 };
    std::cout << average(array1, 5) << '\n';
 
    double array2[] = { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(array2, 4) << '\n';
 
    return 0;
}
