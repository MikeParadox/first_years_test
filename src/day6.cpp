#include "../includes/day6.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>


namespace Day6
{

void print_marker(const std::vector<char>& marker)
{
    for (const auto& elem : marker)
    {
        std::cout << elem << ' ';
    }
}

size_t find_end_of_marker(std::string_view filename)
{
    constexpr size_t marker_size{14};
    std::ifstream ist{filename.data()};
    if (!ist)
        throw std::runtime_error("Can't open the file\n");

    size_t result{marker_size};
    std::vector<char> marker;
    char ch;

    for (size_t i{0}; i < marker_size; ++i)
    {
        ist >> ch;
        marker.push_back(ch);
    }

    while (true)
    {
        if (marker_size != marker.size())
        {
            ist >> ch;
            marker.push_back(ch);
            ++result;
            continue;
        }

        auto first{marker.begin()};

        while (first != (marker.end()))
        {
            auto second{first + 1};
            bool found{false};

            while (second != marker.end() && !found)
            {
                if (*first == *second)
                    found = true;
                ++second;
            }
            ++first;
            if (found)
            {
                marker.erase(marker.begin(), first);
                break;
            }
        }

        if (marker.size() == marker_size)
            return result;
    }

    std::cout << "Something gone wrong\n";
    return -1;
}




} // namespace Day6

