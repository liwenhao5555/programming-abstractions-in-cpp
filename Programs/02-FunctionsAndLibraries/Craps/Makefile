# Makefile for 02-FunctionsAndLibraries/programs/Craps
#****************************************************************

PROGRAMS = \
    Craps

CPPOPTIONS = -IStanfordCPPLib  -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib 
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

Craps: Craps.o
	g++ $(LDOPTIONS) -o Craps Craps.o $(LIB)

Craps.o: Craps.cpp
	g++ $(CPPOPTIONS) -c Craps.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
