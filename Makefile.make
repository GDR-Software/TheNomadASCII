CC         = g++
CFLAGS     = -lposix -lpthread -g -logg -O3 -Wall
ODIR       = bin
SDIR       = src
EXE        = $(ODIR)/nomadascii
EDITOR     = $(ODIR)/mapmaker
CMD        = launcher
LDFLAGS    = -L/libs/libsndfile.a -L/libs/libogg.a -I/libogg/include
SRC        = $(wildcard $(SDIR)/*.c $(SDIR)/*.h $(SDIR)/*.cpp $(SDIR)/game/*.c $(SDIR)/game/*.h $(SDIR)/game/*.cpp)
MAPSRC     = $(wildcard $(SDIR)/mapmaker/*.c $(SDIR)/mapmaker/*.h $(SDIR)/mapmaker/*.cpp)


OBJ= \
	$(ODIR)/\

ifeq ($(build), debug_main)
	DEFS := -DNDEBUG -DNMAIN
else ifeq ($(build), testbuild_main)
	DEFS := -DNTESTBUILD -DNMAIN
else ifeq ($(build), debug_editor)
	DEFS := -DNDEBUG -DNEDITOR
else ifeq ($(build), testbuild_editor)
	DEFS := -DNTESTBUILD -DNEDITOR
endif

$(EXE): $(SRC)
	$(CC) $(DEFS) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(EXE)

$(EDITOR): $(MAPSRC)
	$(CC) $(DEFS) $(CFLAGS) $(SDIR)/*.h $(SDIR)/*.c $(MAPSRC) $(LDFLAGS) -o $(EDITOR)

.PHONY: mapmaker clean run main

main:
	chmod +x $(EXE)
	./$(EXE)

mapmaker:
	chmod +x $(EDITOR)
	./$(EDITOR)

clean:
    rm -rf $(ODIR)/*

run: $(APP)
    chmod +x $(ODIR)/$(APP)
    ./$(ODIR)/$(APP)
