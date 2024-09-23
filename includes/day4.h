#ifndef DAY4_H
#define DAY4_H

#include <string>
#include <utility>
#include <vector>

using range_pair = std::pair<std::pair<int, int>, std::pair<int, int>>;
using vec_range_pairs = std::vector<range_pair>;

// parses single line and returns two std::pairs with edges of ranges of IDs
range_pair parse_line(const std::string& line);


// parses a file with ranges data
vec_range_pairs parse_ranges(const std::string& filename);


// counts assignments fully containing the others
int count_full_duplicates(const vec_range_pairs& ranges);


// return true if ranges fully overlap
bool if_fully_overlap(const range_pair& pair_of_ranges);

// return true if ranges overlap at all
bool if_overlap(const range_pair& pair_of_ranges);




#endif // DAY4_H
