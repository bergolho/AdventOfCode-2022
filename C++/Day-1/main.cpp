/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 1: Calorie Counting ---
        - C++ solution
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

class Elf
{
public:
    uint32_t id;
    double calories;
public:
    Elf ()
    {
        this->id = 0;
        this->calories = 0.0;
    }
    Elf (const double calories)
    {
        this->id = 0;
        this->calories = calories;
    }
    Elf (const uint32_t id, const double calories)
    {
        this->id = id;
        this->calories = calories;
    }
    void print ()
    {
        printf("[Elf %u] Calories = %g\n",this->id,this->calories);
    }
    bool operator< (const Elf& elf) const 
    { 
        return this->calories < elf.calories; 
    }
};

// Read and store the input
void read_elves (std::vector<Elf> &elves)
{
    std::string line;
    uint32_t num_elves = 0;
    double calories = 0.0;
    
    while (getline(std::cin,line))
    {
        if (line.empty())
        {
            Elf elf(num_elves,calories);
            elves.push_back(elf);
            calories = 0.0;
            num_elves++;
        }
        else
        {
            calories += std::stod(line.c_str());
        }
    }
    // Process the last Elf
    Elf elf(num_elves,calories);
    elves.push_back(elf);
    calories = 0.0;
    num_elves++;
}

void print_elves (std::vector<Elf> elves)
{
    for (uint32_t i = 0; i < elves.size(); i++)
    {
        elves[i].print();
    }
}

int main ()
{
    std::vector<Elf> elves;
    read_elves(elves);
    
    std::sort(elves.begin(),elves.end());
    std::reverse(elves.begin(),elves.end());

    // Answer 1
    //printf("[Answer 1] Elf id = %u || Maximum calories = %g\n",elves[0].id,elves[0].calories);
    printf("[Answer 1] %g\n",elves[0].calories);

    // Answer 2
    double ans_2 = 0.0;
    for (uint32_t i = 0; i < 3; i++)
        ans_2 += elves[i].calories;
    printf("[Answer 2] %g\n",ans_2);

    // DEBUG
    //print_elves(elves);

    return 0;
}