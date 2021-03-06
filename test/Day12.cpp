#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "Day12.h"

TEST_CASE("Testing Day 12 process 1")
{
    Day12 day;

    vector<string> input = day.loadLinesString("F10\nN3\nF7\nR90\nF11");

    CHECK_MESSAGE(25 == day.process1(input), "test process 1");
}

TEST_CASE("Testing Day 12 process 2")
{
    Day12 day;

    vector<string> input = day.loadLinesString("F10\nN3\nF7\nR90\nF11");

    CHECK_MESSAGE(286 == day.process2(input), "test process 2");
}
