#include <iostream>

using namespace std;

class node{
public:
    int key = -1;    
    int val = -1;
    node* next_ptr = nullptr;
    node(int key = -1,int val = -1)
    {
        this->key = key;
        this->val = val;
    }
};

class Solution {
public:
    node* ptr = nullptr;
    void add_node(int key ,int val)
    {
        int hash_key = val % 7;
        if (hash_key < 0)
        {
            hash_key = 0 - hash_key;
        }
        node* temp = &ptr[hash_key];
        if (temp->val == -1)
        {
            temp->key = key;
            temp->val = val;
        }
        else
        {
            while (1)
            {
                if (temp->next_ptr == nullptr)
                {
                    temp->next_ptr = new node(key,val);
                    break;
                }
                else
                {
                    temp = temp->next_ptr;
                }
            }
        }
    }

    int lengthOfLongestSubstring(string s = "pwwkew") 
    {
        if (s.length() == 0)
        {
            return 0;
        }
        node* temp = nullptr;
        int result = 0;
        ptr = new node[10];
        int times = 0;
        for (int hash_key = 0, i = 0; i < s.length(); times++, i++)
        {
            hash_key = (int)s[i] % 7;
            if (hash_key < 0)
            {
                hash_key = 0 - hash_key;
            }
            add_node(i, (int)s[i]);
            temp = &ptr[hash_key];
            if (temp->val != -1)
            {
                while (1)
                {
                    if (temp->val == s[i] && temp->key != i)
                    {
                        i = temp->val - 1;
                        if (ptr != nullptr)
                        {
                            delete[] ptr;
                            ptr = new node[10];
                        }
                        if (result < times)
                        {
                            result = times;
                        }
                        times = -1;
                        break;
                    }
                    else if (temp->next_ptr != nullptr)
                    {
                        temp = temp->next_ptr;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (result < times)
        {
            return times;
        }
        return result;
    }
};

int main()
{
    Solution a;
    int b = a.lengthOfLongestSubstring();
    cout << b;
}