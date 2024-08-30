#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
	int midEditDist(string word1 = "core", string word2 = "horse");
};

int Solution::midEditDist(string word1,string word2)
{
	int** arrayPtr = new int* [word1.size()];
	for (int i = 0; i < word1.size(); i++)
	{
		arrayPtr[i] = new int[word2.size()] {0};
	}


	for (int i = 0; i < word1.size(); i++)
	{
		for (int j = 0; j < word2.size(); j++)
		{
			if (i == 0 && j != 0)
			{
				arrayPtr[i][j] = arrayPtr[i][j - 1] + 1;
			}
			else if (i != 0 && j == 0)
			{
				arrayPtr[i][j] = arrayPtr[i - 1][j] + 1;
			}
			else if (i == 0 && j == 0)
			{
				arrayPtr[i][j] = 0;
			}
			else
			{
				if (arrayPtr[i][j - 1] < arrayPtr[i - 1][j])
				{
					if (arrayPtr[i][j - 1] < arrayPtr[i - 1][j - 1])
					{
						if (arrayPtr[i][j - 1] < arrayPtr[i - 1][j])
						{
							arrayPtr[i][j] = arrayPtr[i][j - 1];
						}
						else
						{
							arrayPtr[i][j] = arrayPtr[i - 1][j];
						}
					}
					else
					{
						arrayPtr[i][j] = arrayPtr[i - 1][j - 1];
					}
				}
				else
				{
					if (arrayPtr[i][j - 1] < arrayPtr[i - 1][j - 1])
					{
						arrayPtr[i][j] = arrayPtr[i - 1][j - 1];
					}
					else
					{
						if (arrayPtr[i - 1][j] < arrayPtr[i - 1][j - 1])
						{
							arrayPtr[i][j] = arrayPtr[i - 1][j];
						}
					}
				}
			}
			if (i = word1.size() && j == word2.size())
			{
				cout << arrayPtr[i][j];
				return arrayPtr[i][j];
			}
		}
	}
	return 0;
}