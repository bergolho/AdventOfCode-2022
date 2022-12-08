/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 4: Camp Cleanup ---
        - C++ solution
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <map>

void read_input (std::vector<std::pair<uint32_t,uint32_t>> &intervals_1, \
                 std::vector<std::pair<uint32_t,uint32_t>> &intervals_2)
{
    uint32_t a, b, c, d;
    while (scanf("%u-%u,%u-%u",&a,&b,&c,&d) != EOF)
    {
        std::pair<uint32_t,uint32_t> interval_1 = std::make_pair(a,b);
        std::pair<uint32_t,uint32_t> interval_2 = std::make_pair(c,d);

        intervals_1.push_back(interval_1);
        intervals_2.push_back(interval_2);
    }
}

void solve_part_1 (std::vector<std::pair<uint32_t,uint32_t>> intervals_1, \
                 std::vector<std::pair<uint32_t,uint32_t>> intervals_2)
{
    uint32_t ans = 0;
    for (uint32_t i = 0; i < intervals_1.size(); i++)
    {
        // DEBUG
        //printf("[Interval 1] %u - %u\n",intervals_1[i].first,intervals_1[i].second);
        //printf("[Interval 2] %u - %u\n",intervals_2[i].first,intervals_2[i].second);
        
        uint32_t size_1 = intervals_1[i].second - intervals_1[i].first + 1;
        uint32_t size_2 = intervals_2[i].second - intervals_2[i].first + 1;

        // Interval 1 might be inside Interval 2
        if (size_1 < size_2)
        {
            if (intervals_1[i].first >= intervals_2[i].first && intervals_1[i].second <= intervals_2[i].second)
                ans++;
        }
        // Interval 2 might be inside Interval 1
        else if (size_2 < size_1)
        {
            if (intervals_1[i].first <= intervals_2[i].first && intervals_1[i].second >= intervals_2[i].second)
                ans++;
        }
        // Otherwise, the Intervals might be equal
        else
        {
            if (intervals_1[i].first == intervals_2[i].first && intervals_1[i].second == intervals_2[i].second)
                ans++;
        }
    }
    printf("[Answer 1] Number of assignments = %u\n",ans);
}

void solve_part_2 (std::vector<std::pair<uint32_t,uint32_t>> intervals_1, \
                 std::vector<std::pair<uint32_t,uint32_t>> intervals_2)
{
    uint32_t ans = 0;
    for (uint32_t i = 0; i < intervals_1.size(); i++)
    {
        std::map<uint32_t,uint32_t> hash_table;
        for (uint32_t j = intervals_1[i].first; j <= intervals_1[i].second; j++)
        {
            hash_table[j] = 1;
        }
        for (uint32_t j = intervals_2[i].first; j <= intervals_2[i].second; j++)
        {
            // Overlap !!!
            if (hash_table.find(j) != hash_table.end())
            {
                ans++;
                break;
            }
        }
    }
    printf("[Answer 2] Number of assignments = %u\n",ans);
}

int main ()
{
    std::vector<std::pair<uint32_t,uint32_t>> intervals_1, intervals_2; 
    read_input(intervals_1,intervals_2);

    solve_part_1(intervals_1,intervals_2);
    solve_part_2(intervals_1,intervals_2);

    return 0;
}