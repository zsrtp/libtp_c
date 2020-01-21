CC  := powerpc-eabi
SRC := src
INCLUDE := include
OBJ := build
DMP := dmp
DIR := $(lastword $(subst /, ,$(CURDIR)))

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
DUMPS   := $(patsubst $(OBJ)/%.o, $(DMP)/%.dmp, $(OBJECTS))

all: $(OBJECTS)
#	@echo "Done."

dump: $(DUMPS)
#	@echo "Done."

lib:
	$(CC)-ar rvs $(DIR).a $(OBJ)/*.o

clean:
	rm -rf ./build/*.o
	rm -rf ./dmp/*.dmp
	rm -rf ./*.a

$(OBJ)/%.o: $(SRC)/%.c
	$(CC)-gcc -I$(INCLUDE) -c $< -o $@

$(DMP)/%.dmp: $(OBJ)/%.o
	$(CC)-objdump -D $< > $@
