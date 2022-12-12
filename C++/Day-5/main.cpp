/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 5: Supply Stacks ---
        - C++ solution
        - Rewritten the input of the stacks (problem input is a joke, right?!)
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>

class Movement
{
public:
    uint32_t qtd;
    uint32_t src;
    uint32_t dst;
public:
    Movement (const uint32_t qtd, const uint32_t src, const uint32_t dst)
    {
        this->qtd = qtd;
        this->src = src;
        this->dst = dst;
    }
    void print ()
    {
        printf("Qtd: %u || Src: %u || Dst: %u\n",this->qtd,this->src,this->dst);
    }
};

void read_input (std::vector<std::stack<char>> &stacks,std::vector<Movement> &movs)
{
    // Read the stacks
    uint32_t num_stacks;
    std::cin >> num_stacks;
    stacks.assign(num_stacks,std::stack<char>());

    std::string line, token;
    for (uint32_t i = 0; i < num_stacks; i++)
    {
        std::cin >> line;
        for (uint32_t j = 0; j < line.size(); j++)
        {
            char c = line[j];
            stacks[i].push(c);
        }
    }
    // Read the movements
    uint32_t qtd, src, dst;
    std::getline(std::cin,line);
    std::getline(std::cin,line);
    while (std::getline(std::cin,line))
    {
        // DEBUG
        //printf("%s\n",line.c_str());
        std::stringstream ss(line);

        // Tokenizing the movements
        std::vector<std::string> tokens;
        while(std::getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }
        
        qtd = std::stoul(tokens[1]);
        src = std::stoul(tokens[3]);
        dst = std::stoul(tokens[5]);

        Movement mov(qtd,src-1,dst-1);  // start index = 0
        movs.push_back(mov);
    }
    
    // DEBUG
    //for (uint32_t i = 0; i < movs.size(); i++)
    //    movs[i].print();
}

void solve_part_1 (std::vector<std::stack<char>> stacks, std::vector<Movement> movs)
{
    for (uint32_t i = 0; i < movs.size(); i++)
    {
        // Remove the 'qtd' of elements from 'src' to 'dst'
        for (uint32_t j = 0; j < movs[i].qtd; j++)
        {
            
            char c = stacks[movs[i].src].top();
            stacks[movs[i].src].pop();
            stacks[movs[i].dst].push(c);
        }
    }

    std::vector<char> ans_1;
    for (uint32_t i = 0; i < stacks.size(); i++)
    {
        char c = stacks[i].top();
        ans_1.push_back(c);
    }

    printf("[Answer 1] = ");
    for (uint32_t i = 0; i < ans_1.size(); i++)
        printf("%c",ans_1[i]);
    printf("\n");
}

void solve_part_2 (std::vector<std::stack<char>> stacks, std::vector<Movement> movs)
{
    for (uint32_t i = 0; i < movs.size(); i++)
    {
        // Remove the 'qtd' of elements from 'src' to 'dst'
        // Sustain the order by storing the elements in an auxiliary array and reverse its order
        std::vector<char> aux;
        for (uint32_t j = 0; j < movs[i].qtd; j++)
        {
            char c = stacks[movs[i].src].top();
            stacks[movs[i].src].pop();
            aux.push_back(c);
        }
        std::reverse(aux.begin(),aux.end());
        for (uint32_t j = 0; j < aux.size(); j++)
        {
            char c = aux[j];
            stacks[movs[i].dst].push(c);
        }
    }

    std::vector<char> ans_2;
    for (uint32_t i = 0; i < stacks.size(); i++)
    {
        char c = stacks[i].top();
        ans_2.push_back(c);
    }

    printf("[Answer 2] = ");
    for (uint32_t i = 0; i < ans_2.size(); i++)
        printf("%c",ans_2[i]);
    printf("\n");
}

int main ()
{
    std::vector<std::stack<char>> stacks;
    std::vector<Movement> movements;
    read_input(stacks, movements);

    solve_part_1(stacks, movements);
    solve_part_2(stacks, movements);

    return 0;
}