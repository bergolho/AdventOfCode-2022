'''
----------------------------------------------------------------------
Simple Python script to create files for solving a problem
in the Advent of Code programming contest.
----------------------------------------------------------------------
Author: Lucas Berg (@bergolho)
Version: 17-12-2022
----------------------------------------------------------------------
'''

import os
import sys
import urllib

# GLOBALS
YEAR = 2022
BASE_URL = "https://adventofcode.com"

def usage ():
    print("-"*50)
    print("Usage:> python %s <day_number>" % (sys.argv[0]))
    print("-"*50)

def create_cpp_file (path):
    print("[!] Creating a new 'main.cpp' file ...")
    file = open(path + "/main.cpp", "w")
    file.write("#include <iostream>\n\n")
    file.write("void solve_part_1 () {\n")
    file.write("\t // Your solution goes here ...\n")
    file.write("}\n\n")
    file.write("void solve_part_2 () {\n")
    file.write("\t // Your solution goes here ...\n")
    file.write("}\n\n")
    file.write("int main () {\n")
    file.write("\tsolve_part_1();\n")
    file.write("\tsolve_part_2();\n")
    file.write("\treturn 0;\n")
    file.write("}\n")
    file.close()

def create_makefile (path):
    print("[!] Creating a new 'Makefile' file ...")
    file = open(path + "/Makefile", "w")
    file.write("CC = g++\n")
    file.write("CFLAGS = -std=c++11 -O2 -c -Wall -Wno-unused-result\n\n")
    file.write("all: main\n\n")
    file.write("main: main.o\n")
    file.write("\t$(CC) -o main main.o\n\n")
    file.write("main.o: main.cpp\n")
    file.write("\t$(CC) $(CFLAGS) main.cpp\n\n")
    file.write("clean:\n")
    file.write("\trm -rf *o main\n\n")
    file.close()

def create_folder_and_files (day):
    path = "Day-%d" % (day)
    if (not os.path.exists(path)):
        print("[!] Creating a new folder '%s' ..." % (path))
        os.makedirs(path)
    else:
        print("[-] Folder '%s' already exists!" % (path))

    create_cpp_file(path)
    create_makefile(path)

def main ():
    if (len(sys.argv) != 2):
        usage()
        sys.exit(1)
    
    day = int(sys.argv[1])
    create_folder_and_files(day)

if __name__ == "__main__":
    main()