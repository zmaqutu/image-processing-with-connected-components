# Image Processing with Connected Components

<div align="center" >
  <img src="https://img.shields.io/badge/made%20by-Zongo%20Maqutu-blue?style=for-the-badge&labelColor=20232a" />
  <img src="https://img.shields.io/badge/C++-Assignment-fffe6a?style=for-the-badge&logo=java&labelColor=20232a" />
  <img src="https://img.shields.io/badge/MQTZON001-CS3-fffe6a?style=for-the-badge&logo=java&labelColor=7b6aff" />
  <img src="https://img.shields.io/badge/XML Tag Enumeration-20232a?style=for-the-badge&logo=html" />
</div>

## Description 
*This C++ applicaiton reads a greyscale PGM file and extracts the pixels that are above a user provided threshold as white pixels 
using Bredth first search*

## How to use
*A Makefile is provided just run the following code snippet in the root directory (where the makefile is):*

```unix
$ make
```

*If everything works fine, you will find the excecutable target file in the build folder*

*To run the program simply run* 
```unix
$ ./build/findComp {ARGS}
```

*You can run some predifined sample inputs using the following run commands*
```unix
$ make runAllArguments  
```
*The run command above runs a the program with all aruments provided

```unix
$ make runWriteOnly
```
*The run command above only does the extraction and writes it to an output file without printing component data

```unix
$ make runPrintAllComponents
```
*The run command above runs the program and prints out all components data in a sorted fashion


*To remove all binary files run*
```unix
$ make clean
```

*Here is a snippet of the user menu when you run the program*
*Output files can be found in the "output_files" folder*
