#ke This is a Makefile comment

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
#	@xdg-open dump_files/connectedComponents.pgm
#	echo "Compiled Successfully. Exe file in build folder"
#	sudo cp $(SRCDIR)/*.o /$(BINDIR)
#	$<


# other rule; invoked by make clean etc 
runWriteOnly:
	./build/findComp -s 10 100 -t 150 -w output.pgm ./data/baboon.pgm
runPrintAllComponents:
		./build/findComp -s 10 100 -t 150 -p ./data/baboon.pgm
runAllArguments:
	./build/findComp -s 11 100 -t 32 -p -w output.pgm ./data/nfts/MountainsNFT.pgm

runMakeNFT:
	./build/findComp -s 11 100 -t 150 -p -w output.pgm ./data/nfts/NFTIdea.pgm

# deletes all the object code files
clean:
	@rm -f $(SRCDIR)/*.o
	@rm $(BLDDIR)/findComp
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
	@mv tagParser ~/bin
