#include "../includes/day3.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <utility>

std::vector<std::pair<std::string, std::string>>
parse_lines(const std::string& filename)
{
    std::ifstream ist{filename};

    if (!ist)
        throw std::runtime_error("Can't open the file\n");

    std::vector<std::pair<std::string, std::string>> pairs;
    std::string line;

    while (ist >> line)
    {
        pairs.emplace_back(line.substr(0, line.length() / 2),
                           line.substr(line.length() / 2));
    }

    return pairs;
}


std::vector<char>
find_unique_chars(const std::vector<std::pair<std::string, std::string>>& vec)
{
    std::vector<char> result(vec.size());

    for (int i{0}; i < vec.size(); ++i)
    {
        for (int j{0}; j < vec[i].first.length(); ++j)
        {
            if (find(vec[i].second.begin(), vec[i].second.end(),
                     vec[i].first[j]) != vec[i].second.end())
            {
                result[i] = (vec[i].first[j]);
            }
        }
    }

    return result;
}


std::map<char, int> create_priority_table()
{
    constexpr int num_letters{26};
    constexpr int max_priority{52};
    constexpr int char_a_index{97};
    constexpr int char_A_index{65};

    std::map<char, int> result;

    for (int i{0}; i < max_priority / 2; ++i)
    {
        result[static_cast<char>(char_a_index + i)] = i + 1;
    }

    for (int i{0}; i < max_priority / 2; ++i)
    {
        result[static_cast<char>(char_A_index + i)] = i + num_letters + 1;
    }

    return result;
}


int count_priority(const std::map<char, int>& m, const std::vector<char>& v)
{
    int result{0};

    for (const auto& priority : v)
    {
        // std::cerr << priority << '\n';
        result += m.find(priority)->second;
    }

    return result;
}


std::vector<std::string> split_file_on_lines(const std::string& filename)
{
    std::ifstream ist{filename};

    if (!ist)
        throw std::runtime_error("Can't open a file for reading\n");

    std::vector<std::string> lines;
    std::string line;

    while (ist >> line)
    {
        lines.push_back(line);
    }

    return lines;
}


std::vector<char> find_items(const std::vector<std::string>& lines)
{
    std::vector<char> items;
    for (int i{0}; i < lines.size(); i += 3)
    {
        int num_bages_in_group{0};
        for (const auto& letter : lines[i])
        {
            if (std::find(lines[i + 1].begin(), lines[i + 1].end(), letter) !=
                lines[i + 1].end())
                if (std::find(lines[i + 2].begin(), lines[i + 2].end(),
                              letter) != lines[i + 2].end())
                {
                    items.push_back(letter);
                    break;
                }
        }
    }

    return items;
}
