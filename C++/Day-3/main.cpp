/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 3: Rucksack Reorganization ---
        - C++ solution
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

void read_input (std::vector<std::string> &input)
{
    std::string line;
    while (std::cin >> line)
    {
        input.push_back(line);
    }
}

uint32_t get_priority_number (const char content)
{
    if (content >= 'a' && content <= 'z')
        return content-'a'+1;
    else if (content >= 'A' && content <= 'Z')
        return content-'A'+27;
    else
        return 0;
}

uint32_t calculate_priority (std::string content)
{
    uint32_t size_2 = content.size()/2; // Half the string for each rucksack
    std::string first_rucksack(content.begin(),content.begin()+size_2);
    std::string second_rucksack(content.begin()+size_2,content.end());
    
    // DEBUG
    //printf("First rucksack: %s\n",first_rucksack.c_str());
    //printf("Second rucksack: %s\n",second_rucksack.c_str());

    // Unique data structure to catch collisions 
    // Map STL -> Red Black Tree
    std::map<char,int> hash_table;
    for (uint32_t i = 0; i < first_rucksack.size(); i++)
    {
        hash_table[first_rucksack[i]] = 1;
    }
    for (uint32_t i = 0; i < second_rucksack.size(); i++)
    {
        if (hash_table.find(second_rucksack[i]) != hash_table.end())
        {
            return get_priority_number(second_rucksack[i]);
        }
    }
    return 0;
}

void process_rucksack (std::string rucksack, std::map<char,int> &hash_table)
{
    for (uint32_t j = 0; j < rucksack.size(); j++)
    {
        char c = rucksack[j];
        hash_table[c]++;
    }
}

void solve_part_1 (std::vector<std::string> input)
{
    uint32_t ans = 0;
    for (uint32_t i = 0; i < input.size(); i++)
    {
        ans += calculate_priority(input[i]);
    }    
    printf("[Answer 1] Sum of priorities = %u\n",ans);
}

void solve_part_2 (std::vector<std::string> input)
{
    uint32_t ans = 0;
    for (uint32_t i = 0; i < input.size(); i += 3)
    {
        std::map<char,int> first_hash_table;
        std::map<char,int> second_hash_table;
        std::map<char,int> third_hash_table;

        std::string first_rucksack = input[i];
        std::string second_rucksack = input[i+1];
        std::string third_rucksack = input[i+2];

        // Build a hash table for each rucksack
        process_rucksack(first_rucksack,first_hash_table);
        process_rucksack(second_rucksack,second_hash_table);
        process_rucksack(third_rucksack,third_hash_table);

        // Search in the hash tables for each alphabet letter
        char badge = ' ';
        for (char c = 'a'; c <= 'z'; c++)   // lowercase
        {
            uint32_t sucess = 0;
            if (first_hash_table.find(c) != first_hash_table.end())
                sucess++;
            if (second_hash_table.find(c) != second_hash_table.end())
                sucess++;
            if (third_hash_table.find(c) != third_hash_table.end())
                sucess++;
            
            // Match 3 times --> FOUND!
            if (sucess == 3)
            {
                //printf("Found badge '%c'\n",c);
                badge = c;
                break;
            }
        }
        
        for (char c = 'A'; c <= 'z' && badge == ' '; c++)   // uppercase
        {
            uint32_t sucess = 0;
            if (first_hash_table.find(c) != first_hash_table.end())
                sucess++;
            if (second_hash_table.find(c) != second_hash_table.end())
                sucess++;
            if (third_hash_table.find(c) != third_hash_table.end())
                sucess++;
            
            // Match 3 times --> FOUND!
            if (sucess == 3)
            {
                //printf("Found badge '%c'\n",c);
                badge = c;
                break;
            }
        }
        // Parse to the priority value and increment answer
        ans += get_priority_number(badge);
    }    
    printf("[Answer 2] Sum of priorities = %u\n",ans);
}

int main ()
{
    std::vector<std::string> input; 
    read_input(input);

    solve_part_1(input);
    solve_part_2(input);

    return 0;
}