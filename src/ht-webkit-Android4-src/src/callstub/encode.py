#!/usr/bin/python

import sys
import argparse

# Requires PyElfTools
# Get it from: https://github.com/eliben/pyelftools

from elftools.elf.elffile import ELFFile

def write_raw(fp, data):
    fp.write(data)

ELEM_PER_LINE = 8

def write_c(fp, data):
    fp.write("#include <stdio.h>\n")
    fp.write("#include <stdlib.h>\n")
    fp.write("#include <string.h>\n")
    fp.write("\n")
    fp.write("char *SC = ")

    for i in range(0, len(data), ELEM_PER_LINE):
        barr = data[i:i+ELEM_PER_LINE]
        fp.write("    ")

        fp.write('"')
        for b in barr:
            fp.write(r"\x{:02x}".format(ord(b)))
        fp.write('"')

        if i >= len(data) - ELEM_PER_LINE:
            fp.write(";")

        fp.write("\n")

    fp.write(r"""
int main(void)
{
  char c;
  printf("Press any key to start ...");
  scanf("%c", &c);
  (*(void(*)()) SC)();
  return 0;
}
""")


def write_js(fp, data):
    fp.write("SHELLCODE = [\n")
    
    for i in range(0, len(data), ELEM_PER_LINE):
        barr = data[i:i+ELEM_PER_LINE]
        fp.write("    ")

        for b in barr:
            fp.write("0x{:02x}, ".format(ord(b)))

        fp.write("\n")

    fp.write("];\n")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("input", help="The input ELF file", 
                        type=argparse.FileType("rb"))

    parser.add_argument("-j", "--javascript", 
                       help="Save shellcode to javascript file",
                       type=argparse.FileType("w+"))
    parser.add_argument("-r", "--raw",
                       help="Save shellcode to raw binary file",
                       type=argparse.FileType("wb+"))
    parser.add_argument("-c", "--cstub",
                       help="Save shellcode to a C stub test file",
                       type=argparse.FileType("wb+"))

    args = parser.parse_args()

    elffile = ELFFile(args.input)
    text = elffile.get_section_by_name(".text")
    data = text.data()

    if args.javascript is None and args.raw is None and args.cstub is None:
        sys.stderr.write("No output file(s) specified, nothing to do.\n")
        return

    if args.javascript is not None:
        write_js(args.javascript, data)
    
    if args.raw is not None:
        write_raw(args.raw, data)

    if args.cstub is not None:
        write_c(args.cstub, data)

if __name__ == "__main__":
    main()
