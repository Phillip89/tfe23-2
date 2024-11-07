#include <fmt/chrono.h>
#include <fmt/format.h>

#include <vector> 
#include "CLI/CLI.hpp"
#include "config.h"
#include "myVector.hpp"

auto main(int argc, char** argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME}; // Create an instance of an App with the variable name app
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        // Add a command line option -c or --count and fill the variable counter
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    MyVector vec(1);
    auto start = std::chrono::system_clock::now();
    for (int i=0; i<20; i++)
    {
        vec.push_back(rand());
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::println("The inserting took: {}", elapsed);
    fmt::print("\nwithout additional elements:\n[");
    for (int i=0; i<vec.size(); i++)
    {
        fmt::print("{}, ", vec.at(i));
    }
    fmt::print("]\n");

    int new_element = 12;
    int* new_element_pointer = &new_element;

    vec.push_back(new_element_pointer);
    vec.push_back(new_element);
    vec.push_back(new_element);
    vec.push_back(new_element);

    fmt::print("\nwith additional elements:\n[");
    for (int i=0; i<vec.get_current_size(); i++)
    {
        fmt::print("{}, ", vec.at(i));
    }
    fmt::print("]\n");
    
    return 0; // Exit gracefully
}
