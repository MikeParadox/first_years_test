#include "../includes/day4.h"

#include <fstream>
#include <sstream>

// parses single line and returns two std::pairs with edges of ranges of IDs
range_pair parse_line(const std::string& line)
{
    std::stringstream st{line};

    int first_range_begin;
    int first_range_end;
    int second_range_begin;
    int second_range_end;
    char punct;

    st >> first_range_begin >> punct >> first_range_end >> punct >>
        second_range_begin >> punct >> second_range_end;

    return {{first_range_begin, first_range_end},
            {second_range_begin, second_range_end}};
}


vec_range_pairs parse_ranges(const std::string& filename)
{
    std::ifstream ist{filename};

    if (!ist)
        throw std::runtime_error("Can't open a file for reading\n");

    vec_range_pairs result;
    std::string line;

    while (ist >> line)
    {
        result.emplace_back(parse_line(line));
    }

    return result;
}


int count_full_duplicates(const vec_range_pairs& ranges)
{
    int num_duplicates{0};

    for (const auto& pair_of_ranges : ranges)
    {
        if (if_overlap(pair_of_ranges))
        {
            ++num_duplicates;
        }
    }

    return num_duplicates;
}

// return true if ranges fully overlap
bool if_fully_overlap(const range_pair& pair_of_ranges)
{
    if (pair_of_ranges.first.first >= pair_of_ranges.second.first &&
            pair_of_ranges.first.second <= pair_of_ranges.second.second ||
        pair_of_ranges.first.first <= pair_of_ranges.second.first &&
            pair_of_ranges.first.second >= pair_of_ranges.second.second)
        return true;
    return false;
}

// return true if ranges overlap at all
bool if_overlap(const range_pair& pair_of_ranges)
{
    if (pair_of_ranges.first.first <= pair_of_ranges.second.first &&
            pair_of_ranges.first.second >= pair_of_ranges.second.first ||
        pair_of_ranges.first.first >= pair_of_ranges.second.first &&
            pair_of_ranges.first.first <= pair_of_ranges.second.second)
        return true;
    return false;
}
