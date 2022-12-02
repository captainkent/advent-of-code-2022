#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct SElf
{
    int calories;
};

int main(int argc, char** argv)
{
    // Only argument is the file to parse.
    std::string   file_path = "input.txt";
    std::ifstream file(file_path);

    std::vector<SElf> elves;
    int               calories = 0;
    std::string       line;

    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            calories += std::stoi(line);
        }
        else
        {
            elves.push_back({calories});
            calories = 0;
        }
    }

    // Last elf needs to be added manually
    elves.push_back({calories});

    // Sort the array
    std::sort(elves.begin(), elves.end(),
              [](const SElf& a, const SElf& b)
              { return a.calories > b.calories; });

    // Part 1
    std::cout << elves[0].calories << std::endl;

    // Part 2
    std::cout << elves[0].calories + elves[1].calories + elves[2].calories
              << std::endl;
}