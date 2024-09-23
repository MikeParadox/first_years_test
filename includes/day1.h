#ifndef DAY1_H
#define DAY1_H

#include <string>
#include <vector>

std::vector<std::pair<int, int>>
calculate_calories(const std::string& filename);

int find_max_calories(std::vector<std::pair<int, int>>& elves_and_calories);

void print_list_of_calories(const std::vector<std::pair<int, int>>& v);

int find_top_n(std::vector<std::pair<int, int>>& elves_and_calories, int n);

#endif
