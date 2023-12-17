#include <iostream>
#include "IntArray.h"

using namespace std;


int main()
{
    try
    {
        IntArray array(10);
        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;

        array.resize(8);

        array.insertBefore(20, 7);

        array.remove(3);

        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        {
            IntArray b{ array };
            b = array;
            array = array;
        }

        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
    }
    catch (bad_range& e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (bad_length& b)
    {
        cout << "Exception caught: " << b.what() << endl;
    }


    std::cout << '\n';

    return 0;
}