#include "../includes/day5.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>


std::vector<char> parse_line_of_stacks(const std::string& line)
{
    std::vector<char> stacks;

    auto it = line.begin();
    int num_spaces{0};

    while (it != line.end())
    {
        if (*it == '[')
        {
            stacks.push_back(*(++it));
            ++it;
            num_spaces = 0;
        }
        else
        {
            ++num_spaces;
            ++it;
        }

        if (num_spaces == 4) // num spaces when there is no crate in a stack
        {
            stacks.push_back('0');
            num_spaces = 0;
        }
    }

    return stacks;
}


std::vector<std::stack<char>> parse_stack_file(const std::string& filename)
{
    std::ifstream ist{filename};


    if (!ist)
        throw std::runtime_error("Can't open a file for reading\n");

    constexpr int num_stacks{9};
    constexpr int max_num_crates_in_stack{8};
    std::vector<std::vector<char>> stacks_with_crates_in_reverse(num_stacks);
    std::string line;
    std::vector<std::stack<char>> stacks(num_stacks);

    while (getline(ist, line))
    {
        std::vector<char> line_of_crates{parse_line_of_stacks(line)};

        for (int i{0}; i < line_of_crates.size(); ++i)
            stacks_with_crates_in_reverse[i].push_back(line_of_crates[i]);
    }

    int num_of_stack{0};
    for (auto line_of_stacks_in_reverse : stacks_with_crates_in_reverse)
    {
        for (std::size_t i{line_of_stacks_in_reverse.size() - 1}; i >= 0; --i)
        {
            if (line_of_stacks_in_reverse[i] != '0')
                stacks[num_of_stack].push(line_of_stacks_in_reverse[i]);
        }
        ++num_of_stack;
    }

    return stacks;
}


std::vector<int> parse_line_moves(const std::string& line)
{
    std::vector<int> move;
    std::string w;
    int num_crates;
    int stack_from;
    int stack_to;

    std::istringstream iss{line};
    iss >> w >> num_crates >> w >> stack_from >> w >> stack_to;
    move.push_back(num_crates);
    move.push_back(stack_from - 1);
    move.push_back(stack_to - 1);

    return move;
}


std::vector<std::vector<int>> parse_moves(const std::string& filename)
{
    std::ifstream ist{filename};
    if (!ist)
        throw std::runtime_error("Can't open file for reading\n");

    std::vector<std::vector<int>> moves;
    std::string line;

    while (ist)
    {
        getline(ist, line);
        std::vector<int> move{parse_line_moves(line)};
        moves.push_back(move);
    }
    moves.pop_back();

    return moves;
}


void move_crates(const std::vector<std::vector<int>>& moves,
                 std::vector<std::stack<char>>& stacks)
{
    for (const auto& move : moves)
    {
        for (int i{0}; i < move[0]; ++i)
        {
            stacks[move[2]].push(stacks[move[1]].top());
            stacks[move[1]].pop();
        }
    }
}

// moves crates with CrateMover 9001
void move_crates_9001(const std::vector<std::vector<int>>& moves,
                      std::vector<std::stack<char>>& stacks)
{
    for (const auto& move : moves)
    {
        std::vector<char> moved;
        for (int i{0}; i < move[0]; ++i)
        {
            moved.push_back(stacks[move[1]].top());
            stacks[move[1]].pop();
        }

        for (std::size_t i{moved.size()}; i >= 0; --i)
        {
            stacks[move[2]].push(moved[i]);
        }
    }
}


void print_top_crates(const std::vector<std::stack<char>>& stacks)
{
    for (const auto& stack : stacks)
    {
        if (!stack.empty())
            std::cout << stack.top();
    }

    std::cout << '\n';
}
