#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <stdio.h>
#include <string.h>

namespace fs = boost::filesystem;

/**
 * \brief   Return the filenames of all files that have the specified extension
 *          in the specified directory and all subdirectories.
 */
std::vector<fs::path> get_all(fs::path const &root, std::string const &ext)
{
    std::vector<fs::path> paths;

    if (fs::exists(root) && fs::is_directory(root))
    {
        for (auto const &entry : fs::recursive_directory_iterator(root))
        {
            if (fs::is_regular_file(entry) && entry.path().extension() == ext)
                paths.emplace_back(entry.path().filename());
        }
    }

    return paths;
}

int main(int argc, char *argv[])
{
    bool directory = true;
    String path = argv[1];

    char *token = strtok(path, ".");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        if (token == "argos")
        {
            directory = false;
        }

        token = strtok(NULL, "-");
    }

    return 0;
}