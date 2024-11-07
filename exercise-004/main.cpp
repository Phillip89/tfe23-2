#include <fmt/chrono.h>
#include <fmt/format.h>

#include <vector> /* Provides std::vector */
#include "CLI/CLI.hpp"
#include "config.h" /* Make sure this file exists and defines PROJECT_NAME, PROJECT_VER, PROJECT_BUILD_DATE */
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

    MyVector vec(17);
    for (int i=0; i<vec.size(); i++)
    {
        vec.push_back(rand());
    }
    
    fmt::print("[");
    for (int i=0; i<vec.size(); i++)
    {
        fmt::print("{}, ", vec.at(i));
    }
    fmt::print("]");

    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(13);

    fmt::print("\n[");
    for (int i=0; i<vec.get_current_size(); i++)
    {
        fmt::print("{}, ", vec.at(i));
    }
    fmt::print("]");
    
    return 0; // Exit gracefully
}
