#include <iostream>
#include <string>

using namespace std;

enum class state {
    START,
    SIGH,
    INT,
    DOT,
    INT_DOT,
    E,
    DEC,
    E_SIGH,
    E_INT,
    INVAILD,
};

enum class event {
    SIGH,
    DOT,
    E,
    DIGIT,
    OTHER,
};

class Solution {
public:
    state type[10][5] = {
        state::SIGH,state::DOT,state::INVAILD,state::INT,state::INVAILD,//START
        state::INVAILD,state::DOT,state::INVAILD,state::INT,state::INVAILD,//SIGH
        state::INVAILD,state::INT_DOT,state::E,state::INT,state::INVAILD,//INT
        state::INVAILD,state::INVAILD,state::INVAILD,state::DEC,state::INVAILD,//DOT
        state::INVAILD,state::INVAILD,state::E,state::INT_DOT,state::INVAILD,//INT_DOT
        state::E_SIGH,state::INVAILD,state::INVAILD,state::E_INT,state::INVAILD,//E
        state::INVAILD,state::INVAILD,state::E,state::DEC,state::INVAILD,//DEC
        state::INVAILD,state::INVAILD,state::INVAILD,state::E_INT,state::INVAILD,//E_SIGH
        state::INVAILD,state::INVAILD,state::INVAILD,state::E_INT,state::INVAILD,//E_INT
        state::INVAILD,state::INVAILD,state::INVAILD,state::INVAILD,state::INVAILD//INVAILD
    };

    bool isNumber(string s) {
        state State = state::START;
        for (int i = 0; i < s.size(); i++)
        {
            event Event = getEvent(s[i]);
            State = type[(int)State][(int)Event];
        }
        if (State == state::INT || State ==state::E_INT || State==state::DEC || State==state::INT_DOT)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    event getEvent(char s)
    {
        if (s == '+' || s == '-')
        {
            return event::SIGH;
        }
        else if (s == 'e' || s == 'E')
        {
            return event::E;
        }
        else if (s >= '0' && s <= '9')
        {
            return event::DIGIT;
        }
        else if (s == '.')
        {
            return event::DOT;
        }
        else
        {
            return event::OTHER;
        }
    }
};
