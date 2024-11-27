#include <fmt/chrono.h>
#include <fmt/format.h>

#include <vector> 
#include "CLI/CLI.hpp"
#include "config.h"

class Tier {
    public:
    virtual void iss() = 0;

    protected:
    std::string m_name{"Tier"};
};

class Hund : public Tier {
    public:
    Hund() {
        m_name = "Hund";
    }
    void iss() {
        fmt::println("Wuff! Fresse wie ein Hund!");
    }
};

class Katze : public Tier {
    public:
    void iss() override {
        fmt::println("Schnurr! Fresse wie eine Katze!");
    }
};

class Pudel : public Hund {
    public:
    void iss() final {
        fmt::println("Wuff! Fresse wie ein Pudel!");
    }
};

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

    Hund katrin;
    Katze miau;
    Pudel hans;

    katrin.iss();
    miau.iss();
    hans.iss();
    
    return 0; // Exit gracefully
}
