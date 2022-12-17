#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

void read_input (std::vector<std::string> &in) {
	// Extract all the lines from the input and store in an array
	std::string line;
	while (std::getline(std::cin, line)) {
		in.push_back(line);
	}
}

void tokenize_line (std::string line, std::vector<std::string> &tokens) {
	std::string token;
	std::stringstream ss(line);
	while (std::getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	// DEBUG
	//for (uint32_t i = 0; i < tokens.size(); i++) {
	//	printf("'%s' ",tokens[i].c_str());
	//}
}

void update_pathname (std::string &pathname, std::vector<std::string> curr_dirs) {
	pathname.clear();
	for (uint32_t i = 0; i < curr_dirs.size(); i++) {
		pathname += curr_dirs[i] + "/";
	}
}

void calculate_pathsizes (std::vector<std::string> in, std::map<std::string, uint32_t> &hash_table) {
	// Keep track of the current path
	std::string pathname;
	std::vector<std::string> curr_dirs;

	uint32_t size = 0;
	for (uint32_t i = 0; i < in.size(); i++) {
		std::vector<std::string> tokens;
		tokenize_line(in[i], tokens);

		// Commands
		if (tokens[0] == "$") {
			// Change directory
			if (tokens[1] == "cd") {
				if (tokens[2] == "..") {
					curr_dirs.pop_back();
				}
				else {
					curr_dirs.push_back(tokens[2]);
				}
				//update_pathname(pathname, curr_dirs);
			}
			// List files
			else if (tokens[1] == "ls") {
				//printf("List directory\n");
			}
		}
		// Found a directory 
		else if (tokens[0] == "dir") {
			//printf("Found a directory\n");
		}
		// Found a file
		else {
			// Here, we add the file size to all the folder within the current path tree
			pathname.clear();
			size = std::stoul(tokens[0]);
			for (uint32_t j = 0; j < curr_dirs.size(); j++) {
				pathname += curr_dirs[j] + "/";
				hash_table[pathname] += size;
			}
		}
	}
}

void solve_part_1 (std::map<std::string, uint32_t> hash_table) {
	uint32_t ans = 0;
	for (auto it : hash_table) {
		std::string path = it.first;
		uint32_t path_size = it.second;
		if (path_size <= 100000) {
			//printf("Pathname: %s || Size: %u\n", path.c_str(), path_size);
			ans += path_size;
		}
	}
	printf("[Answer 1] %u\n", ans);
}

void solve_part_2 (std::map<std::string, uint32_t> hash_table) {
	uint32_t total_disk_usage = hash_table["//"];
	uint32_t free_disk_space = 70000000-total_disk_usage;

	printf("Free space: %u\n", free_disk_space);

	uint32_t ans = UINT32_MAX;
	for (auto it : hash_table) {
		std::string path = it.first;
		uint32_t path_size = it.second;
		uint32_t new_disk_usage = total_disk_usage - path_size;
		uint32_t new_free_disk_space = 70000000-new_disk_usage;
		
		// Deleting this folder will allow the update to be installed
		if (new_free_disk_space >= 30000000) {
			printf("Folder '%s' should be deleted.\n", path.c_str());
			// Update the answer
			if (path_size < ans)
				ans = path_size;
		}
	}
	printf("[Answer 2] %u\n", ans);
}

int main () {
	std::vector<std::string> input;
	read_input(input);

	// Hash table to store the sizes from all pathnames
	std::map<std::string, uint32_t> hash_table;
	calculate_pathsizes(input, hash_table);

	solve_part_1(hash_table);
	solve_part_2(hash_table);
	
	return 0;
}
