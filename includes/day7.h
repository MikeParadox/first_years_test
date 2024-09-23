#ifndef DAY7_H
#define DAY7_H


#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Day7
{
// 1) parse the input in form of vector named dirs_to_calc of maps:
//      dir_name(string): size(size_t),
//      vector of elems to add to size(strings) - files sizes and names of
//      contained dirs
//
// 2) create vector<unordered_map>(calculated_dirs) consisting of dir_name:
//      size of dirs which size is completely calculated
//
// 3) calculate size of every dir in dirs_to_calc - if vector of elems to add
//      becomes empty, dir should be moved to calculated_dirs (deleted form
//      dirs_to_calc)
//
// 4) repeat 3 until dirs_to_calc_becomes empty
//
// 5) calculate sum of sizes of dirs more or equal than 100'000
//

struct Directory
{
    std::string name{};
    size_t size{};
    std::vector<std::string> dirs_contained{};
};

std::ostream& operator<<(std::ostream& ost, const Directory& d);

class Filesystem_assessor
{
    using Directories = std::unordered_map<std::string, Directory>;

public:
    Filesystem_assessor(std::string_view fn, size_t dir_size)
        : filename{fn}, min_dir_size{dir_size}
    {
    }

    // counts sum of sizes of dirs equal or more than min_dir_size
    size_t count_overall_size();

private:
    std::string filename;
    size_t min_dir_size;
    Directories calculated_dirs{};
    Directories parsed_dirs{};

    // parses filesystem to generate directories to calculate size of
    void parse_filesystem();
    // calculates the size of every directory in parsed_dirs and move them to
    //   calculated_dirs
    void calculate_dirs();
    void calculate_dir(Directory& dir);
};

// parses a directory
Directory parse_directory(std::string_view dir_name, std::ifstream& ist);



} // namespace Day7



#endif // DAY7_H
