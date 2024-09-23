#include "../includes/day7.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std::string_literals;
using namespace Day7;


int main(int args, char* argv[])
{
    Filesystem_assessor f{"day7.txt", 100000};

    size_t result{f.count_overall_size()};

    std::cout << "Sum of sizes of dirs more than 100000 is: " << result << '\n';


    return 0;
}





