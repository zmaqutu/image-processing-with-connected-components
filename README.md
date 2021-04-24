# Tag Enumeration

<div align="center" >
  <img src="https://img.shields.io/badge/made%20by-Zongo%20Maqutu-blue?style=for-the-badge&labelColor=20232a" />
  <img src="https://img.shields.io/badge/C++-Assignment-fffe6a?style=for-the-badge&logo=java&labelColor=20232a" />
  <img src="https://img.shields.io/badge/MQTZON001-CS3-fffe6a?style=for-the-badge&logo=java&labelColor=7b6aff" />
  <img src="https://img.shields.io/badge/XML Tag Enumeration-20232a?style=for-the-badge&logo=html" />
</div>

## Description 
*This C++ applicaiton parses a text file with XML tags. Sample text files are provided in the data folder*

## How to use
*A Makefile is provided just run the following code snippet in the root directory (where the makefile is):*

```unix
$ make
```

*If everything works fine, you will find the excecutable target file in the build folder*

*To run the program simply run* 
```unix
$ ./build/target.ext {ARGS}
```

*Where ARGS is the name of any input file*
*To remove all binary files run*
```unix
$ make clean
```

*Here is a snippet of the user menu when you run the program*

```unix
$ r: Read and process tag file
p: Print all tags
d: Dump/write tags and data to a file called tag.txt
l: List/print tag data for given tag to cout
q: Quit

Enter an option (r,p,d,l) or q to quit, and press return...
```
