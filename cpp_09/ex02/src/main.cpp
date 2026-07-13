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
    for (int i = 1; i < argc; i++)
        {
            if (!isPositiveInteger(argv[i]))
            {
                std::cerr << "Wrong: " << argv[i] << std::endl;
                exit (1);
            }
            else
                std::cout << argv[i] << " ";
        }
    std::cout << std::endl;
    return 0;
}
