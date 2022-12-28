/*
    Advent of Code 2022 - Programming Contest (https://adventofcode.com/2022)
    Author: Lucas Berg (@bergolho)
------------------------------------------------------
    --- Day 8: Treetop Tree House ---
        - C++ solution
*/

#include <iostream>
#include <vector>
#include <string>

void print_grid (std::vector<std::vector<uint32_t>> grid) {
	printf("%u %u\n",grid.size(),grid[0].size());
	for (uint32_t i = 0; i < grid.size(); i++) {
		for (uint32_t j = 0; j < grid[i].size(); j++) {
			printf("%u ", grid[i][j]);
		}
		printf("\n");
	}
}

bool check_cell (std::vector<std::vector<uint32_t>> grid, const int i, const int j) {
	uint32_t nlin = grid.size();
	uint32_t ncol = grid[0].size();
	uint32_t cur_height = grid[i][j];
	
	std::vector<uint32_t> north;
	for (int k = i-1; k >= 0; k--) {
		north.push_back(grid[k][j]);
	}
	std::vector<uint32_t> south;
	for (int k = i+1; k < nlin; k++) {
		south.push_back(grid[k][j]);
	}
	std::vector<uint32_t> east;
	for (int k = j+1; k < ncol; k++) {
		east.push_back(grid[i][k]);
	}
	std::vector<uint32_t> west;
	for (int k = j-1; k >= 0; k--) {
		west.push_back(grid[i][k]);
	}

	bool is_north_ok = true;
	for (int k = 0; k < north.size(); k++) {
		if (cur_height <= north[k]) {
			is_north_ok = false;
			break;
		}
	}
	bool is_south_ok = true;
	for (int k = 0; k < south.size(); k++) {
		if (cur_height <= south[k]) {
			is_south_ok = false;
			break;
		}
	}
	bool is_east_ok = true;
	for (int k = 0; k < east.size(); k++) {
		if (cur_height <= east[k]) {
			is_east_ok = false;
			break;
		}
	}
	bool is_west_ok = true;
	for (int k = 0; k < west.size(); k++) {
		if (cur_height <= west[k]) {
			is_west_ok = false;
			break;
		}
	}

	return (is_north_ok | is_south_ok | is_east_ok | is_west_ok);
}

void parse_grid (std::vector<std::string> in, std::vector<std::vector<uint32_t>> &grid) {
	grid.assign(in.size(), std::vector<uint32_t>());
	for (uint32_t i = 0; i < in.size(); i++) {
		for (uint32_t j = 0; j < in[i].size(); j++) {
			char c = in[i][j];
			grid[i].push_back(atol(&c));
		}
	}
}

void read_input (std::vector<std::string> &in) {
	std::string line;
	while (std::getline(std::cin,line)) {
		in.push_back(line);
	}
}

void solve_part_1 (std::vector<std::string> in) {
	std::vector<std::vector<uint32_t>> grid;
	parse_grid(in,grid);
	//print_grid(grid);

	uint32_t nlin = grid.size();
	uint32_t ncol = grid[0].size();
	uint32_t ans = (nlin*ncol)-((nlin-2)*(ncol-2));
	for (int i = 1; i < nlin-1; i++) {
		for (int j = 1; j < ncol-1; j++) {
			bool is_visible = check_cell(grid, i, j);
			if (is_visible) {
				//printf("Visible\n\n",i, j);
				ans++;
			}		
		}
	}
	printf("[Answer 1] %u\n", ans);
}

void solve_part_2 () {
	 // Your solution goes here ...
}

int main () {
	std::vector<std::string> input;
	read_input(input);

	solve_part_1(input);
	solve_part_2();

	return 0;
}
