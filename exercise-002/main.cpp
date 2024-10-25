#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"

// .bss Segment
// nicht initialisierte globale Variablen
int foo;
int foo2;

// .data Segment
// initialisierte globale Variablen
int bar = 100;
int bar2 = 50;

// .rodata Segment
// konstante globale Variablen
const int rodata = 4711;
const int rodata2 = 4712;

void myfunction() 
{
    static int value = 100;
    fmt::println("[myfunction] The value of variable value : {} and its address {}", value, fmt::ptr(&value));
    value = value + 1;
}

void myfunctionBSS() 
{
    static int bss;
    fmt::println("[myfunctionBSS] The value of variable bss : {} and its address {}", bss, fmt::ptr(&bss));
    bss = bss + 1;
}

void myfunctionStack(uint8_t a, uint8_t b) 
{
    fmt::println("[myfunctionStack] The value of variable a : {} and its address {}", a, fmt::ptr(&a));
    fmt::println("[myfunctionStack] The value of variable b : {} and its address {}", b, fmt::ptr(&b));
}

void indirectCall()
{
    uint8_t value = 34;
    fmt::println("[indirectCall] The value of the variable value: {} address of value: {}",value,fmt::ptr(&value));
    myfunctionStack(22,23);

}

auto main(int argc, char** argv) -> int
{
    int local_variable;
    int local_variable2;

    int local_variable3 = 10;
    int local_variable4 = 20;

    const int local_variable5 = 10;
    const int local_variable6 = 20;

    static int local_variable7 = 10;
    static int local_variable8 = 20;

    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME}; /* create an instance of an App with the variable name app*/
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    fmt::println("Welcome to exercise 2");
    fmt::println("The value of foo {} and the address {}",foo,fmt::ptr(&foo));
    fmt::println("The value of foo2 {} and the address {}",foo2,fmt::ptr(&foo2));
    fmt::println("The value of bar {} and the address {}",bar,fmt::ptr(&bar));
    fmt::println("The value of bar2 {} and the address {}",bar2,fmt::ptr(&bar2));
    fmt::println("The value of rodata {} and the address {}",rodata,fmt::ptr(&rodata));
    fmt::println("The value of rodata2 {} and the address {}",rodata2,fmt::ptr(&rodata2));
    fmt::println("The value of local_variable {} and the address {}",local_variable,fmt::ptr(&local_variable));
    fmt::println("The value of local_variable2 {} and the address {}",local_variable2,fmt::ptr(&local_variable2));
    fmt::println("The value of local_variable3 {} and the address {}",local_variable3,fmt::ptr(&local_variable3));
    fmt::println("The value of local_variable4 {} and the address {}",local_variable4,fmt::ptr(&local_variable4));
    fmt::println("The value of local_variable5 {} and the address {}",local_variable5,fmt::ptr(&local_variable5));
    fmt::println("The value of local_variable6 {} and the address {}",local_variable6,fmt::ptr(&local_variable6));
    fmt::println("The value of local_variable7 {} and the address {}",local_variable7,fmt::ptr(&local_variable7));
    fmt::println("The value of local_variable8 {} and the address {}",local_variable8,fmt::ptr(&local_variable8));
    myfunction();
    myfunction();
    myfunctionBSS();
    myfunctionBSS();
    myfunctionStack(foo /*bss segment*/, bar /*data segment*/);
    myfunctionStack('a', 'b');
    indirectCall();

    int* ptr = new int(68);
    int* ptr2 = new int(72);

    fmt::println("The value of the variable ptr is {} the address of ptr: {}", *ptr, fmt::ptr(ptr));
    fmt::println("The value of the variable ptr is {} the address of ptr: {}", *ptr2, fmt::ptr(ptr2));

    return 0;
}
