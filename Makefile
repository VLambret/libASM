# Main directories

BIN=bin
OBJ=obj
INCLUDE=include
SRC=src

# Sources directories

UTL=utl
ASM=asm
BASE=base
PARSE=parsing
MAIN=mains

SRC_BASE=$(SRC)/$(BASE)
SRC_PARSE=$(SRC)/$(PARSE)
SRC_UTL=$(SRC_PARSE)/$(UTL)
SRC_ASM=$(SRC_PARSE)/$(ASM)

# Commands and Options

UTL_H=utl200.h
ASM_H=asm200.h

CC=gcc
CPP=g++
YACC=yacc

CFLAGS=	-Wall \
		-I$(INCLUDE) \
		-DUTL_H='<$(UTL_H)>' \
		-DASM_H='<$(ASM_H)>'

# Object et source files lists

LOCAL_OBJECTS   = asm_mipslex.o                \
                  asm_mipsyac.o                \
                  asm_ReadMipsAsmFiles.o       \

MAIN_CFILES		= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.c))
MAIN_CPPFILES	= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.cpp))
MAIN_CBIN		= $(addprefix $(BIN)/,$(notdir $(MAIN_CFILES:%.c=%)))
MAIN_CPPBIN		= $(addprefix $(BIN)/,$(notdir $(MAIN_CPPFILES:%.cpp=%)))

UTL_CFILES		= $(foreach d,$(SRC_UTL),$(wildcard $(d)/*.c))
UTL_OBJECTS		= $(addprefix $(OBJ)/$(UTL)/,$(notdir $(UTL_CFILES:%.c=%.o)))

ASM_CFILES		= $(foreach d,$(SRC_ASM),$(wildcard $(d)/*.c))
ASM_OBJECTS		= $(addprefix $(OBJ)/$(ASM)/,$(notdir $(ASM_CFILES:%.c=%.o)))

BASE_CFILES		= $(foreach d,$(SRC_BASE),$(wildcard $(d)/*.cpp))
BASE_OBJECTS	= $(addprefix $(OBJ)/$(BASE)/,$(notdir $(BASE_CFILES:%.cpp=%.o)))

PARSE_CFILES	= asm_mipsyac.c asm_mipslex.c
PARSE_OBJECTS	= $(addprefix $(OBJ)/$(PARSE)/,$(notdir $(PARSE_CFILES:%.c=%.o)))

# Rules to make the world 

.PHONY : all lib clean

all: $(MAIN_CBIN) $(MAIN_CPPBIN)

LIB=$(UTL_OBJECTS) $(ASM_OBJECTS) $(BASE_OBJECTS) $(PARSE_OBJECTS)

# Build all mains

$(BIN)/% : $(SRC)/$(MAIN)/%.c $(BIN) $(LIB)
	$(CPP) $(CFLAGS) -o $@ $< $(LIB) 

#	$(CPP) $(CFLAGS) -o $(BIN)/$@ $^

$(OBJ)/$(BASE)/%.o : $(SRC_BASE)/%.cpp $(OBJ)/$(BASE)
	$(CPP) $(CFLAGS) -c -o $@ $<

## All this stuff is useful for parsing asm mips source, it comes from an existing project

$(OBJ)/$(UTL)/%.o : $(SRC_UTL)/%.c $(OBJ)/$(UTL)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/$(ASM)/%.o : $(SRC_ASM)/%.c $(OBJ)/$(ASM)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/$(PARSE)/%.o : $(SRC_PARSE)/%.c $(OBJ)/$(PARSE)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SRC_PARSE)/asm_mipsyac.c $(INCLUDE)/asm_mipsyac.h : $(SRC_PARSE)/asm_mips.yac
	cd $(SRC_PARSE) && $(YACC) -d -p asm_mips asm_mips.yac
	mv $(SRC_PARSE)/y.tab.c $(SRC_PARSE)/asm_mipsyac.c
	mv $(SRC_PARSE)/y.tab.h $(INCLUDE)/asm_mipsyac.h

$(SRC_PARSE)/asm_mipslex.c : $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mips.lex
	$(LEX) -Pasm_mips $(SRC_PARSE)/asm_mips.lex > $(SRC_PARSE)/asm_mipslex.c

clean :
	rm -rf $(OBJ) $(BIN)
	rm -f $(OBJ)/*.o $(OBJ)/$(ASM)/*.o $(OBJ)/$(UTL)/*.o $(BIN)/* $(OBJ)/$(PARSE)/*.o $(OBJ)/$(BASE)/*.o 
	rm -f $(SRC_PARSE)/asm_mipsyac.c $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mipslex.c
	rm -f lex.asm_mips.c

# Directories : git cant deal with empty directories, so we have to create them just in time

$(BIN) $(OBJ) $(OBJ)/$(UTL) $(OBJ)/$(ASM) $(OBJ)/$(PARSE) $(OBJ)/$(BASE):
	mkdir -p $@

# GIT stuff

.PHONY : git-commit git-push git-pull

HOST="github.com"
PROJECT="VLambret/libASM.git"

git-commit :
	git commit -a

# Get changes on upstream
git-pull : 
	git pull

# Push changes to upstream
git-push : clean
	git add *
	git push git@$(HOST):$(PROJECT) master

