#include <iostream>
#include <vector>
#include <set>

void move_head (std::pair<int,int> &head, const char dir) {
	switch (dir) {
		case 'U':
			head.first++;
			break;
		case 'R':
			head.second++;
			break;
		case 'L':
			head.second--;
			break;
		case 'D':
			head.first--;
			break;
		default:
			break;
	}
}

void move_tail (std::pair<int,int> head, std::pair<int,int> &tail) {
	
	int row_diff = head.first - tail.first;
	int col_diff = head.second - tail.second;
	if (std::abs(row_diff) >= 2) {
		tail.first += row_diff / 2;						// Vertical and horizontal case
		if (std::abs(col_diff) >= 2) {
			tail.second += col_diff / 2;				// Intermediate knots, diagonal
		}
		else {
			tail.second += head.second - tail.second;	// Diagonal case
		}
	}
	else if (std::abs(col_diff) >= 2) {
		tail.second += col_diff / 2;				// Vertical and horizontal case
		tail.first += head.first - tail.first;		// Diagonal case
	}
}

void solve_part_1 () {
	std::pair<int,int> head(0,0);			// (row,col)
	std::pair<int,int> tail(0,0);			// (row,col)
	std::set<std::pair<int,int>> visited;

	int val;
	char dir;
	while (scanf(" %c %d", &dir, &val) != EOF) {
		for (int k = 0; k < val; k++) {
			move_head(head, dir);
			move_tail(head, tail);
			visited.insert(tail);
		}
	}

	printf("[Answer 1] There are %lu positions the tail visited at least once.\n", visited.size());
}

void solve_part_2 () {
	std::vector<std::pair<int,int>> long_rope;
	long_rope.assign(10, {0,0});
	std::set<std::pair<int,int>> visited;

	int val;
	char dir;
	while (scanf(" %c %d", &dir, &val) != EOF) {
		for (int k = 0; k < val; k++) {
			move_head(long_rope[0], dir);
			for (int i = 0; i < long_rope.size()-1; i++) {
				move_tail(long_rope[i], long_rope[i+1]);
			}
			visited.insert(long_rope.back());
		}
	}

	printf("[Answer 2] There are %lu positions the tail visited at least once.\n", visited.size());
}

int main () {

	//solve_part_1();
	solve_part_2();

	return 0;
}
