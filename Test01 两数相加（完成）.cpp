#include <vector>
#include <iostream>
using namespace std;

struct node
{
	int key = -1;//�洢����
	int val = -1;//�洢����
	node* nextPtr = nullptr;
	node(int key = -1, int val = -1)
	{
		this->key = key;
		this->val = val;
	}
};

class Solution {
public:
	int input[17] = { 1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1 };
	node* ptr = nullptr;

	void add_node(int key, int val)
	{
		vector<int> k(input, input + 17);
		ptr = new node[10];
		int hash_key = key % 7;
		if (hash_key < 0)
		{
			hash_key = 0 - hash_key;
		}
		if (ptr[hash_key].key == -1)
		{
			ptr[hash_key].key = key;
			ptr[hash_key].val = val;
		}
		else
		{
			node* temp = &ptr[hash_key];
			while (1)
			{
				if (temp->nextPtr == nullptr)
				{
					temp->nextPtr = new node(key, val);
					break;
				}
				else
				{
					temp = temp->nextPtr;
				}
			}
		}
	}

	vector<int> twoSum(vector<int>& nums, int target)
	{
		for (int i = 0,hash_key = 0; i < nums.size(); i++)
		{
			add_node(nums[i], i);
			hash_key = (target - nums[i]) % 7;
			if (hash_key < 0)
			{
				hash_key = 0 - hash_key;
			}
			//�ж���û�д�����ײλ��
			if (ptr[hash_key].val != -1)
			{
				//��ȡ���ڵ�
				node* temp = &ptr[hash_key];
				while (1)
				{				
					if (temp->val == i && temp->nextPtr != nullptr)
					{
						//�ܾ���ͬλ������
						temp = temp->nextPtr;
					}
					else if (temp->key != (target - nums[i]) && temp->nextPtr != nullptr)
					{
						//�ܾ�����λ������
						temp = temp->nextPtr;
					}
					else if (temp->val == i && temp->nextPtr == nullptr)
					{
						//�ܾ���ͬλ������
						break;
					}
					else if (temp->key != (target - nums[i]) && temp->nextPtr == nullptr)
					{
						//�ܾ�����λ������
						break;
					}
					else
					{
						int output[2];
						output[0] = i;
						output[1] = temp->val;
						vector<int> outputSTL(output, output + 2);
						cout << i << temp->val;
						return outputSTL;
					}
				}
			}
		}
		return vector<int>(2, 0);
	}
};
