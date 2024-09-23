#ifndef DAY3_H
#define DAY3_H

#include <map>
#include <string>
#include <vector>

// read lines from a file and split every line to two lines of the same size
std::vector<std::pair<std::string, std::string>>
parse_lines(const std::string& filename);


// finds unique letters in every line of input
std::vector<char>
find_unique_chars(const std::vector<std::pair<std::string, std::string>>& vec);


// creates a table for convertion from letter to int priority
std::map<char, int> create_priority_table();


// counts sum of priorities
int count_priority(const std::map<char, int>& m, const std::vector<char>& v);


// finds similar item for a set of three groups items
std::vector<std::string> split_file_on_lines(const std::string& filename);


// finds items for every group
std::vector<char> find_items(const std::vector<std::string>& lines);


#endif // DAY3_H
