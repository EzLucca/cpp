#include "PmergeMe.hpp"
#include <string>
#include <charconv>
#include <string_view>

bool isPositiveInteger(const char* str)
{
    if (str == nullptr || *str == '\0')
        return false;

    std::string_view sv(str);

    int value{};
    auto [ptr, ec] = std::from_chars(
        sv.data(),
        sv.data() + sv.size(),
        value
    );

    return ec == std::errc{} &&
           ptr == sv.data() + sv.size() &&
           value > 0;
}

int main (int argc, char **argv)
{
    // validate argvs to create unsorted list
    if (argc < 2)
        std::cerr << "./program args[...]" << std::endl;
    while (*argv)
    {
        //validate argv
        if(!isPositiveInteger(*argv))
            std::cout << "Wrong: "  << *argv << std::endl;
        else
            std::cout << *argv << std::endl;
        argv++;
    }
    return 0;
}
