# brainf
A simple brainf*ck transpiler to C written in C++.

## Installation
```bash
git clone https://github.com/henior2/brainf.git
cd brainf
```
To install globally:
```bash
make install
```

Or locally:
```bash
make local
```

To clear the build files:
```bash
make clean # cleans the build files
make remove # uninstalls the program both locally and globally
```

## Usage
```
Usage: brainf [-o output_file] [-d] [-h|--help] [-v|--version] [-c] input_file
Options:
        -o output_file          Specify the output file
        -d                      Enable debug mode
        -h, --help              Show this help message
        -v, --version           Display version information
        -c                      Compile with the compiler selected in config.h
```
