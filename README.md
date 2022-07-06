# C++ CLI Compile Tool

Automatically detects source files and external dependencies in project folder

## Usage

```bash
cmd build -compiler:[String] -outfile:[String] -dir:[String] [String][]
cmd build debug
cmd build release
cmd build -compiler:g++ -outfile:bin/main -dir:src -std=c++17 -O2
cmd new [ProjectName]
cmd run
```
