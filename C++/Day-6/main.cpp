/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 6: Tuning Trouble ---
        - C++ solution
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

void solve_part_1 (std::string in)
{
    for (uint32_t i = 0; i < in.size(); i++)
    {
        std::string window(in.begin()+i,in.begin()+i+4);
        if (window.size() == 4)
        {
            // DEBUG
            //printf("%s\n",window.c_str());
            std::unordered_set<char> hash_table(window.begin(),window.end());
            if (hash_table.size() == window.size())
            {
                printf("[Answer 1] = %u\n",i+4);
                break;
            }
        }
    }
}

void solve_part_2 (std::string in)
{
    for (uint32_t i = 0; i < in.size(); i++)
    {
        std::string window(in.begin()+i,in.begin()+i+14);
        if (window.size() == 14)
        {
            // DEBUG
            //printf("%s\n",window.c_str());
            std::unordered_set<char> hash_table(window.begin(),window.end());
            if (hash_table.size() == window.size())
            {
                printf("[Answer 2] = %u\n",i+14);
                break;
            }
        }
    }
}

int main ()
{
    std::string input;
    while (std::getline(std::cin,input))
    {
        solve_part_1(input);
        solve_part_2(input);
    }
    return 0;
}