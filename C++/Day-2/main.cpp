/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 2: Rock Paper Scissors ---
        - C++ solution
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

void read_input (std::vector<std::pair<char,char>> &input)
{
    char a, b;
    while (std::cin >> a >> b)
    {
        input.push_back(std::make_pair(a,b));
    }
}

char calculate_my_play (char his_shape, char game_result)
{
    // Rock first
    if (his_shape == 'A' && game_result == 'X') return 'Z';
    else if (his_shape == 'A' && game_result == 'Y') return 'X';
    else if (his_shape == 'A' && game_result == 'Z') return 'Y';
    // Paper first
    else if (his_shape == 'B' && game_result == 'X') return 'X';
    else if (his_shape == 'B' && game_result == 'Y') return 'Y';
    else if (his_shape == 'B' && game_result == 'Z') return 'Z';
    // Scissor first
    else if (his_shape == 'C' && game_result == 'X') return 'Y';
    else if (his_shape == 'C' && game_result == 'Y') return 'Z';
    else if (his_shape == 'C' && game_result == 'Z') return 'X';
    else return '0';
}

uint32_t get_shape_number (const char my_shape)
{
    if (my_shape == 'X') return 1;
    else if (my_shape == 'Y') return 2;
    else if (my_shape == 'Z') return 3;
    else return 0; 
}

uint32_t calculate_game (const char his_shape, const char my_shape)
{
    uint32_t outcome;
    uint32_t shape_number = get_shape_number(my_shape);
    
    // GAME LOGIC
    //  Rock first
    if (his_shape == 'A' && my_shape == 'X')
        outcome = 3;
    else if (his_shape == 'A' && my_shape == 'Y')
        outcome = 6;
    else if (his_shape == 'A' && my_shape == 'Z')
        outcome = 0;
    //  Paper first
    else if (his_shape == 'B' && my_shape == 'X')
        outcome = 0;
    else if (his_shape == 'B' && my_shape == 'Y')
        outcome = 3;
    else if (his_shape == 'B' && my_shape == 'Z')
        outcome = 6;
    //  Scissors first
    else if (his_shape == 'C' && my_shape == 'X')
        outcome = 6;
    else if (his_shape == 'C' && my_shape == 'Y')
        outcome = 0;
    else if (his_shape == 'C' && my_shape == 'Z')
        outcome = 3;
    
    //printf("a = %c || b = %c\n",a,b);
    //printf("Shape = %u || Outcome = %u\n",shape_number,outcome);
    return shape_number+outcome;
}

void solve_part_1 (std::vector<std::pair<char,char>> input)
{
    char opponent, my_play;
    uint32_t total_score = 0;
    for (uint32_t i = 0; i < input.size(); i++)
    {
        opponent = input[i].first;
        my_play = input[i].second;
        total_score += calculate_game(opponent,my_play);
    }
    printf("[Answer 1] Total score = %u\n",total_score);
}

void solve_part_2 (std::vector<std::pair<char,char>> input)
{
    char opponent, game_result, my_play;
    uint32_t total_score = 0;
    for (uint32_t i = 0; i < input.size(); i++)
    {
        opponent = input[i].first;
        game_result = input[i].second;
        my_play = calculate_my_play(opponent,game_result);
        total_score += calculate_game(opponent,my_play);
    }
    printf("[Answer 2] Total score = %u\n",total_score);
}

int main ()
{
    std::vector<std::pair<char,char>> input; 
    read_input(input);

    solve_part_1(input);
    solve_part_2(input);

    return 0;
}