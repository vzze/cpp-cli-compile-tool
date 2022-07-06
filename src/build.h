#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

extern std::vector<std::string_view> file_exts;
extern std::vector<std::string_view> flags;

void rec(std::string root, std::string & cmd);

int build(std::vector<std::string> & args);
