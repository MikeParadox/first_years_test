#include "../includes/day7.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


namespace Day7
{
void Filesystem_assessor::parse_filesystem()
{
    std::ifstream ist{filename};

    if (!ist)
        throw std::runtime_error("Can't opent the file\n");

    Directories dirs;
    std::string line;


    while (true)
    {
        getline(ist, line);

        std::string_view name{};

        if (line[0] == '$')
        {
            if (line.substr(5) == "..")
                continue;

            else if (line.substr(0, 4) == "$ cd")
            {
                name = line.substr(5);
                getline(ist, line);
            }
        }
        if (line == "$ ls" && name != "")
        {
            Directory dir{parse_directory(name, ist)};
            if (dir.dirs_contained.size() == 0)
                calculated_dirs.emplace(dir.name, dir);
            else
                parsed_dirs.emplace(dir.name, dir);
        }
        else
        {
            throw std::runtime_error(
                "Can't parse the file. Invalid structure\n");
        }
        if (!ist)
            break;
    }
}

Directory parse_directory(std::string_view dir_name, std::ifstream& ist)
{
    size_t size{0};
    std::vector<std::string> dirs_contained{};
    std::string line;

    while (ist)
    {
        auto ch{ist.get()};

        if (ch == '$')
        {
            ist.putback(ch);
            break;
        }

        ist.putback(ch);
        getline(ist, line);

        std::stringstream st_stream{line};
        std::string first;
        st_stream >> first;
        if (first == "dir")
        {
            st_stream >> first;
            dirs_contained.push_back(first);
        }
        else
        {
            size += stoi(first);
        }
    }

    return {dir_name.data(), size, dirs_contained};
}


void Filesystem_assessor::calculate_dir(Directory& dir)
{
    auto temp{dir.dirs_contained};

    for (auto it{temp.begin()}; it != temp.end(); ++it)
    {
        if (calculated_dirs.find(*it) != calculated_dirs.end())
        {
            dir.size += calculated_dirs[*it].size;
            dir.dirs_contained.erase(it);
        }
    }
}


// some malloc() error in if-clause
void Filesystem_assessor::calculate_dirs()
{
    auto temp{parsed_dirs};

    while (parsed_dirs.size() > 0)
    {
        for (auto& dir_to_calc : temp)
        {
            calculate_dir(dir_to_calc.second);

            if (dir_to_calc.second.dirs_contained.empty())
            {
                calculated_dirs[dir_to_calc.first] = dir_to_calc.second;
                parsed_dirs.erase(dir_to_calc.first);
            }
        }
    }
}

size_t Filesystem_assessor::count_overall_size()
{
    parse_filesystem();
    calculate_dirs();

    size_t result{0};

    for (const auto& dir : calculated_dirs)
    {
        if (dir.second.size >= min_dir_size)
        {
            result += dir.second.size;
        }
    }

    return result;
}





// print folder in form name: size and then every contained forlder on a new
// line
std::ostream& operator<<(std::ostream& ost, const Directory& d)
{
    ost << d.name << ": ";
    if (d.dirs_contained.size() == 0)
        ost << d.size;
    else
    {
        ost << d.size << '\n';
        for (const auto& elem : d.dirs_contained)
            ost << elem << '\n';
    }
    return ost;
}


} // namespace Day7

