# This is a Makefile comment

# Declare some variables to help construct our compile command
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref
SRCDIR=src
BINDIR=bin
INCDIR=include
BLDDIR=build

SOURCES = src/driver.cpp $(SRCDIR)/PGMimageProcessor.cpp $(SRCDIR)/ConnectedComponent.cpp
OBJECTS=$(SOURCES:.cpp=.o)


default: $(OBJECTS)
	$(CC)  $(SOURCES) -o build/findComp -std=c++2a -Wall
#	echo "Compiled Successfully. Exe file in build folder"
#	sudo cp $(SRCDIR)/*.o /$(BINDIR)
#	$<


# other rule; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f $(SRCDIR)/*.o
	@rm $(BLDDIR)/findComp
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
	@mv tagParser ~/bin
