#include "new.h"

int new_project(std::vector<std::string> & args) {
    std::string name = "";
    for(auto & arg : args)
        name += arg + " ";
    name.pop_back();

    std::cout << std::flush;

    std::string sys_cmd = "start powershell.exe \"New-Item -ItemType Directory -Name '" + name + "'; New-Item -ItemType File -Path './" + name + "/' -Name '.gitignore'; New-Item -ItemType Directory -Path './" + name + "/' -Name 'src'; New-Item -ItemType File -Path './" + name + "/src/' -Name 'main.cc'; New-Item -ItemType Directory -Path './" + name + "/' -Name 'bin'; 'bin' | Out-File -FilePath './" + name + "/.gitignore' -Encoding default; git init './" + name + "'\"";

    return system(sys_cmd.c_str());
}
