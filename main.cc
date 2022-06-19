#include <vector>
#include <string>
#include <filesystem>

#include <iostream>

std::vector<std::string_view> file_exts = {
    ".C", ".cc", ".cp", ".cxx", ".cpp", ".c++", ".ixx", ".cppm",
    ".c"
};

void rec(std::string root, std::string & cmd) {
    for(auto & f : std::filesystem::directory_iterator(root)) {
        if(!f.is_directory()) {
            for(std::string_view ext : file_exts) {
                std::string path = f.path().string();

                size_t loc = path.find(ext);

                if(loc != std::string::npos)
                    if(path.length() - loc == ext.length()) {
                        cmd += path + " ";
                        break;
                    }
            }
        } else {
            std::string dir = f.path().string();

            dir = dir.substr(dir.find_last_of("/\\") + 1);

            if(dir == "include") {
                cmd.insert(0, "-I" + f.path().string().substr(2) + " ");
            }

            rec(f.path().string(), cmd);
        }
    }
}

std::vector<std::string_view> flags {
    "-compiler:", "-outfile:", "-dir:",
    "-c:",        "-o:",       "-d:"
};

int main(int argc, char ** argv) {
    if(argc == 1) {
        std::cout << "cmd -compiler:[String] -outfile:[String] -dir:[String] [String][]\n";

        std::cout << "cmd -compiler:g++ -outfile:bin/main -dir:src -std=c++17 -O2\n";

        return 0;
    }

    std::string cmd;

    std::string comp = "";
    std::string outf = "";

    std::string dir = "";

    for(size_t i = 1; i < argc; i++) {
        std::string arg = argv[i];

        bool fF = false;

        for(auto flag : flags) {
            if(arg.find(flag) == 0) {
                fF = true;
                if(flag == "-compiler:" || flag == "-c:") {
                    comp = arg.substr(flag.length()); comp += " ";
                } else if(flag == "-outfile:" || flag == "-o:") {
                    outf = "-o ";
                    outf += arg.substr(flag.length());
                } else if(flag == "-dir:" || flag == "-d:") {
                    dir = arg.substr(flag.length());
                }
            }
        }
        if(!fF)
            cmd += arg + " ";
    }

    rec(".\\" + dir, cmd);

    cmd.insert(0, comp);

    cmd += outf;

    std::cout << cmd << '\n';

    return system(cmd.c_str());
}
