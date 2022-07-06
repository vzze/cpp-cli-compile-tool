#include "build.h"
#include "new.h"
#include "run.h"

int main(int argc, char ** argv) {
    if(argc == 1) {
        std::cout << "cmd build -compiler:[String] -outfile:[String] -dir:[String] [String][]\n";
        std::cout << "cmd build debug\n";
        std::cout << "cmd build release\n";
        std::cout << "cmd build -compiler:g++ -outfile:bin/main -dir:src -std=c++17 -O2\n";
        std::cout << "cmd new [ProjectName]\n";
        std::cout << "cmd run\n";
        return 0;
    }

    std::string first = argv[1];
    std::vector<std::string> args;

    for(std::size_t i = 2; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    if(first == "build") {
        if(args[0] == "release") {
            std::vector<std::string> newr = { "-c:g++", "-o:bin/main", "-d:src", "-std=c++20", "-O3", "-Wall" };
            return build(newr);
        } else if(args[0] == "debug") {
            std::vector<std::string> newr = { "-c:g++", "-o:bin/main", "-d:src", "-std=c++20", "-O0", "-g", "-Wall" };
            return build(newr);
        } else {
            return build(args);
        }
    } else if(first == "new") {
        return new_project(args);
    } else if(first == "run") {
        return run();
    }
}
