#include <string>
#include <iostream>
using namespace std;

enum class state {
    START,
    POSITIVESIGH,
    NEGATIVESIGH,
    POSITIVEINT,
    NEGATIVEINT,
    OUTPUT
};

enum class event {
    POSITIVSIGH,
    NEGATIVESIGH,
    DIGIT,
    OTHER,
    SPACE
};

class Solution {
public:
    state type[5][5] = {
        state::POSITIVESIGH,state::NEGATIVESIGH,state::POSITIVEINT,state::OUTPUT,state::START,//START
        state::OUTPUT,state::OUTPUT,state::POSITIVEINT,state::OUTPUT,state::OUTPUT,//POSITIVESIGH
        state::OUTPUT,state::OUTPUT,state::NEGATIVEINT,state::OUTPUT,state::OUTPUT,//NEGATIVESIGH
        state::OUTPUT,state::OUTPUT,state::POSITIVEINT,state::OUTPUT,state::OUTPUT,//POSITIVEINT
        state::OUTPUT,state::OUTPUT,state::NEGATIVEINT,state::OUTPUT,state::OUTPUT,//NEGATIVEINT
    };
    int num = 0;
    state State = state::START;
    event Event = event::SPACE;
    int myAtoi(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            Event = getEvent(s[i]);
            State = type[(int)State][(int)Event];
            if (State == state::POSITIVEINT)
            {
                if (num > 214748364)
                {
                    return 2147483647;
                }
                else if (num <= 214748364 && num >= 214748360 && s[i] >'7')
                {
                    return 2147483647;
                }
                else
                {
                    num = num * 10;
                    num = num + s[i] - 48;
                }
            }
            else if (State == state::NEGATIVEINT)
            {
                if (num < -214748364)
                {
                    return -2147483648;
                }
                else if (num >= -214748364 && num <= -214748360 && s[i] >'7')
                {
                    return -2147483648;
                }
                else
                {
                    num = num * 10;
                    num = num - s[i] + 48;
                }
            }
            else if (State == state::OUTPUT)
            {
                return num;
            }
        }
        return num;
    }

    event getEvent(char s)
    {
        if (s == '+')
        {
            return event::POSITIVSIGH;
        }
        if (s == '-')
        {
            return event::NEGATIVESIGH;
        }
        else if (s >= '0' && s <= '9')
        {
            return event::DIGIT;
        }
        else if (s == ' ')
        {
            return event::SPACE;
        }
        else
        {
            return event::OTHER;
        }
    }
};
