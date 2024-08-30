#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        string temp = "null";
        int dist = a.size() - b.size();
        if (dist < 0)
        {
            dist = 0 - dist;
            temp = b;
            b = a;
            a = temp;
        }
        temp = a;
        for (int i = b.size() - 1, k =0 ; i >= 0; i--)
        {
            if (a[i + dist + k] == '0' && b[i] == '1')
            {
                a[i + dist + k] = '1';
            }
            else if (a[i + dist + k] == '1' && b[i] == '0')
            {
                a[i + dist + k] = '1';
            }
            else if (a[i + dist + k] == '0' && b[i] == '0')
            {
                a[i + dist + k] = '0';
            }
            else
            {
                for (int j = i + dist + k; j >= 0; j--)
                {
                    if (a[j] == '1' && j != 0)
                    {
                        a[j] = '0';
                    }
                    else if (a[j] == '1')
                    {
                        a[j] = '0';
                        a.insert(0, "1");
                        k++;
                        break;
                    }
                    else
                    {
                        a[j] = '1';
                        break;
                    }
                }

            }
        }
        return a;
    }
};
