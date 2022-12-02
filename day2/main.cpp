#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::map<std::string, int> points = {{"win", 6}, {"draw", 3}, {"loss", 0},
                                     {"X", 1},   {"Y", 2},    {"Z", 3}};

int score_part1(const std::string& them, const std::string& me)
{
    std::string result = "";

    if (them == "A" && me == "X" || //
        them == "B" && me == "Y" || //
        them == "C" && me == "Z")
    {
        result = "draw";
    }
    else if (them == "A" && me == "Y" || //
             them == "B" && me == "Z" || //
             them == "C" && me == "X")
    {
        result = "win";
    }
    else
    {
        result = "loss";
    }

    return points[result] + points[me];
}

int score_part2(const std::string& them, const std::string& strat)
{
    std::string me     = "";
    std::string result = "";

    if (strat == "X" && them == "A" || //
        strat == "Y" && them == "C" || //
        strat == "Z" && them == "B")
    {
        me = "Z";
    }
    else if (strat == "X" && them == "C" || //
             strat == "Y" && them == "B" || //
             strat == "Z" && them == "A")
    {
        me = "Y";
    }
    else
    {
        me = "X";
    }

    if (strat == "X")
    {
        result = "loss";
    }
    else if (strat == "Y")
    {
        result = "draw";
    }
    else
    {
        result = "win";
    }

    return points[result] + points[me];
}

int main(int argc, char** argv)
{
    // Only argument is the file to parse.
    std::string   file_path = "input";
    std::ifstream file(file_path);

    std::string      line;
    std::vector<int> scores;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string        them, me;
        if (!(iss >> them >> me))
        {
            break;
        }

        scores.push_back(score_part2(them, me));
    }

    auto res = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << res << std::endl;
}