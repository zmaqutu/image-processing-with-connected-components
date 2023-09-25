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
The run command above runs a the program with all aruments provided
<table>
  <tr>
    <td align="center">
    <img src="https://github.com/zmaqutu/image-processing-with-connected-components/assets/39608194/26a2c312-4495-4d59-8e5a-1a3487319d0a" style="width: 70%; height: auto;" alt="Before Processing">
      <br>
      <em>Before</em>
    </td>
    <td align="center">
      <img src="https://github.com/zmaqutu/image-processing-with-connected-components/assets/39608194/bc50a6e5-69af-4a7c-bcbf-dd9847187d34" style="width: 70%; height: auto;" alt="After Processing">
      <br>
      <em>After</em>
    </td>
  </tr>
</table>

```unix
$ make runWriteOnly
```
The run command above only does the extraction and writes it to an output file without printing component data

```unix
$ make runPrintAllComponents
```
The run command above runs the program and prints out all components data in a sorted fashion


*To remove all binary files run*
```unix
$ make clean
```
## Command line invocation

Assuming your executable is called `findcomp`, it must support the following command line options:

- **`-s <int> <int>`** (4-s) : Set the minimum and maximum valid component size. 
    - `[min default = 3, max = image width * image height i.e. unlimited]`

- **`-t <int>`** : Set the threshold for component detection. 
    - *(default = 128, limit to [0 . . . 255])*

- **`-p`** : Print out all the component data (entries do not have to be sorted) as well as the total component number and the sizes of the smallest and largest components.

- **`-w <outPGMfile>`** : Write out all retained components (as foreground/background pixels) to a new PGM file, `<outPGMfile>`.

**Note**: `<inputPGMfile>` is a valid PGM image.

<p align="center">Made with ❤️ with good ol' vim</p>
