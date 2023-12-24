#ifndef LANG_H
#define LANG_H

#define ccp constexpr const char*

ccp str_help = "Usage: brainf [-o output_file] [-d] [-h|--help] [-v|--version] [-c] input_file\nOptions:\n\t-o output_file\t\tSpecify the output file\n\t-d\t\t\tEnable debug mode\n\t-h, --help\t\tShow this help message\n\t-v, --version\t\tDisplay version information\n\t-c\t\t\tCompile with the compiler selected in config.h\n";
ccp str_version = "\nUse brainf --help for more information\n";
ccp error_no_input = "Error: No input file\n";
ccp error_no_output = "Error: No output file given\n";
ccp error_cant_input = "Error: Cannot open input file\n";
ccp error_cant_output = "Error: Cannot open output file\n";
ccp error_too_many_params = "Error: Too many parameters\n";
ccp error_too_many_output = "Error: Too many output files\n";
ccp error_parentheses = "Compilation Error: Unmatched parentheses (characters [ and ] )\n";
ccp str_trans_success = "Transpilation successful\n";
ccp str_trans_fail = "Transpilation failed\n";
ccp str_comp_success = "Compilation successful\n";
ccp str_comp_fail = "Compilation failed\n";
ccp warn_debug = "Warning: Debug mode is not yet implemented\n";

#endif