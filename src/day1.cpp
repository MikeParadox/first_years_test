#include "../includes/day1.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::pair<int, int>> calculate_calories(const std::string& filename)
{
    std::ifstream ist{filename};
    if (!ist)
        throw("Can't open the file for reading\n");

    std::vector<std::pair<int, int>> result;
    int num_of_elf{0};
    int num_calories{0};

    while (ist)
    {
        std::string line;
        std::getline(ist, line);
        // std::cerr << "line is " << line << '\n';
        if (std::isdigit(line[0]))
            num_calories = std::stoi(line);
        else
        {
            ++num_of_elf;
            result.push_back({++num_of_elf, ++num_calories});
            num_calories = 0;
        }
    }

    return result;
}


int find_max_calories(std::vector<std::pair<int, int>>& elves_and_calories)
{
    sort(elves_and_calories.begin(), elves_and_calories.end(),
         [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

    return (--elves_and_calories.end())->second;
}


void print_list_of_calories(const std::vector<std::pair<int, int>>& v)
{
    for (const auto& p : v)
    {
        std::cout << p.first << '\t' << p.second << '\n';
    }
}

int find_top_n(std::vector<std::pair<int, int>>& elves_and_calories, int n)
{
    sort(elves_and_calories.begin(), elves_and_calories.end(),
         [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

    int result{0};

    while (n > 0)
    {
        result += (elves_and_calories.end() - n)->second;
        --n;
    }

    return result;
}