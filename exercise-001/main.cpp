#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto printVector(std::vector<int>* parVector)
{
    fmt::print("[{}]\n", fmt::join(*parVector, ", "));
}

auto sortVector(std::vector<int>* parVector)
{
    std::sort(parVector->begin(), parVector->end());
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    int counter = 20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", counter, "How many items to insert");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    /*std::cout << counter << std::endl;*/

    std::vector<int> testVector;
    for (int i=0; i<counter; i++)
    {
        testVector.push_back(rand() % 100);
        /*std::cout << testVector[i] << std::endl;*/
    }
    
    fmt::print("Vektor unsortiert: ");
    printVector(&testVector);
    
    auto start = std::chrono::system_clock::now();
    sortVector(&testVector);
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;

    fmt::print("Vektor sortiert: ");
    printVector(&testVector);

    fmt::print("Benötigte Zeit: {}", elapsed);

    return 0; /* exit gracefully*/
}