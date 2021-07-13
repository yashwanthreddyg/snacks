// Copied from https://stackoverflow.com/a/28309550/2733273

#include <stdio.h>

int BinarySearch(int key, int data[], const int len)
{
    int low = 0;
    int high = len - 1;

    while (high >= low)
    {
        int mid = low + ((high - low) / 2);

        /**/ if (data[mid] < key)
            low = mid + 1;
        else if (data[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1; // KEY_NOT_FOUND
}

int LessThanEqualBinSearch(int key, int data[], const int len)
{
    int min = 0;
    int max = len - 1;
    // var max = data.length - 1; // Javascript, Java conversion

    while (min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)
            min = mid + 1;
        else if (data[mid] > key)
            max = mid - 1;
        else /*data[mid] = key)*/
            return mid;
    }

    if (max < 0)
        return 0; // key < data[0]
    else if (min > (len - 1))
        return -1; // key >= data[len-1] // KEY_NOT_FOUND
    else
        return (min < max)
                   ? min
                   : max + 1;
}

int LessThanEqualOrLastBinSearch(int key, int data[], const int len)
{
    int min = 0;
    int max = len - 1;
    // var max = data.length - 1; // Javascript, Java conversion

    while (min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)
            min = mid + 1;
        else if (data[mid] > key)
            max = mid - 1;
        else /*data[mid] = key)*/
            return mid;
    }

    if (max < 0)
        return 0; // key < data[0]
    else if (min > (len - 1))
        return len - 1; // key >= data[len-1]
    else
        return (min < max)
                   ? min
                   : max + 1;
}

int NextLargestBinSearch(int key, int data[], const int len)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        // To convert to Javascript:
        // var mid = low + ((high - low) / 2) | 0;
        int mid = low + ((high - low) / 2);

        /**/ if (data[mid] < key)
            low = mid + 1;
        else if (data[mid] > key)
            high = mid - 1;
        else
            return mid + 1;
    }

    if (high < 0)
        return 0; // key < data[0]
    else if (low > (len - 1))
        return len; // key >= data[len-1]
    else
        return (low < high)
                   ? low + 1
                   : high + 1;
}

int main()
{
    int items[] = {1, 3, 5, 7, 9, 11};
    int LENGTH = sizeof(items) / sizeof(items[0]);

    for (int i = -1; i < 14; ++i)
        printf("[%2d]: == %2d   <= %2d   <| %d   > %d\n", i, BinarySearch(i, items, LENGTH), LessThanEqualBinSearch(i, items, LENGTH), LessThanEqualOrLastBinSearch(i, items, LENGTH), NextLargestBinSearch(i, items, LENGTH));

    return 0;
}