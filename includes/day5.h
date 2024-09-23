#ifndef DAY5_H
#define DAY5_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>

// parses a line of crates in stacks
std::vector<char> parse_line_of_stacks(const std::string& line);

// parses stacks list and creates a vector of stacks
std::vector<std::stack<char>> parse_stack_file(const std::string& filename);

// parses line of moves and creates vector in form (num crates, from, to)
std::vector<int> parse_line_moves(const std::string& line);

// parses moves and create a vector or vectors in form from-num_crates_to
std::vector<std::vector<int>> parse_moves(const std::string& filename);

// moves crates with CrateMover 9000
void move_crates(const std::vector<std::vector<int>>& moves,
                 std::vector<std::stack<char>>& stacks);

// moves crates with CrateMover 9001
void move_crates_9001(const std::vector<std::vector<int>>& moves,
                      std::vector<std::stack<char>>& stacks);

// collect top crates
void print_top_crates(const std::vector<std::stack<char>>& stacks);

template <typename T> void print_stacks_of_crates(std::vector<std::stack<T>> st)
{
    for (auto s : st)
    {
        while (!s.empty())
        {
            std::cout << s.top() << ' ';
            s.pop();
        }
        std::cout << '\n';
    }
}


#endif // DAY5_H
