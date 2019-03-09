#include <iostream>
#include <algorithm>

void bubbleSort(int array[], int lengthArray)
{
    bool arraySorted(false);
    int iteration=0;
    while (!arraySorted)
    {
        arraySorted=true;
        for (int index=0; index<lengthArray-1; ++index)
        {
            if (array[index]>array[index+1])
                {
                    std::swap(array[index],array[index+1]);
                    arraySorted=false;
                }
        }
        --lengthArray; // the biggest element of the current subarray is the last element after one iteration
        ++iteration; // even if the array is sorted
    }
    std::cout << "BlubbleSort terminated after " << iteration << " iterations. \n";
}

int main()
{
    int array[]={10,6,3,2,9,7,1,5,4,8};
    const int lengthArray(sizeof(array)/sizeof(array[0]));
    bubbleSort(array,lengthArray);
    for (int index=0; index < lengthArray; ++index)
        std::cout << array[index] << " ";
    return 0;
}
