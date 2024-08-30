#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        int* ptr = new int[n];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ptr[i] = 1;
            }
            else if (i == 1)
            {
                ptr[i] = 2;
            }
            else
            {
                ptr[i] = ptr[i - 1] + ptr[i - 2];
            }
        }
        return ptr[n - 1];
    }
};
