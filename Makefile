# Main directories

BIN=bin
OBJ=obj
INCLUDE=include
SRC=src
TMP=tmp
EX=examples
C=c
CP=cpp

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
CCMIPS=mips-gcc
CPP=g++
YACC=yacc
#YACC=bison

CFLAGS=	-Wall \
		-I$(INCLUDE) \
		-DUTL_H='<$(UTL_H)>' \
		-DASM_H='<$(ASM_H)>' \
		-g

# Object et source files lists

LOCAL_OBJECTS   = asm_mipslex.o                \
                  asm_mipsyac.o                \
                  asm_ReadMipsAsmFiles.o       \

MAIN_CFILES		= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.c))
MAIN_CPPFILES	= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.cpp))
MAIN_CBIN		= $(addprefix $(BIN)/$(C)/,$(notdir $(MAIN_CFILES:%.c=%)))
MAIN_CPPBIN		= $(addprefix $(BIN)/$(CP)/,$(notdir $(MAIN_CPPFILES:%.cpp=%)))

UTL_CFILES		= $(foreach d,$(SRC_UTL),$(wildcard $(d)/*.c))
UTL_OBJECTS		= $(addprefix $(OBJ)/$(UTL)/,$(notdir $(UTL_CFILES:%.c=%.o)))

ASM_CFILES		= $(foreach d,$(SRC_ASM),$(wildcard $(d)/*.c))
ASM_OBJECTS		= $(addprefix $(OBJ)/$(ASM)/,$(notdir $(ASM_CFILES:%.c=%.o)))

BASE_CFILES		= $(foreach d,$(SRC_BASE),$(wildcard $(d)/*.cpp))
BASE_OBJECTS	= $(addprefix $(OBJ)/$(BASE)/,$(notdir $(BASE_CFILES:%.cpp=%.o)))

PARSE_CFILES	= asm_mipsyac.c asm_mipslex.c
PARSE_OBJECTS	= $(addprefix $(OBJ)/$(PARSE)/,$(notdir $(PARSE_CFILES:%.c=%.o)))

EX_CFILES		= $(foreach d,$(SRC)/$(EX)/,$(wildcard $(d)/*.c))
EX_SFILES		= $(addprefix $(TMP)/$(EX)/,$(notdir $(EX_CFILES:%.c=%.s)))

# Rules to make the world 

.PHONY : all lib clean

all: $(MAIN_CBIN) $(MAIN_CPPBIN)

LIB=$(UTL_OBJECTS) $(ASM_OBJECTS) $(BASE_OBJECTS) $(PARSE_OBJECTS)

lib : $(LIB)

# Build all mains

$(BIN)/$(C)/% : $(SRC)/$(MAIN)/%.c $(LIB)
	@mkdir -p $(BIN)/$(C)/
	@mkdir -p $(TMP)
	$(CPP) $(CFLAGS) -o $@ $^ 

$(BIN)/$(CP)/% : $(SRC)/$(MAIN)/%.cpp $(LIB)
	@mkdir -p $(BIN)/$(CP)/
	@mkdir -p $(TMP)
	$(CPP) $(CFLAGS) -o $@ $^

#	$(CPP) $(CFLAGS) -o $(BIN)/$@ $^

$(OBJ)/$(BASE)/%.o : $(SRC_BASE)/%.cpp
	@mkdir -p  $(OBJ)/$(BASE)
	$(CPP) $(CFLAGS) -c -o $@ $<

## All this stuff is useful for parsing asm mips source, it comes from an existing project

$(OBJ)/$(UTL)/%.o : $(SRC_UTL)/%.c 
	@mkdir -p $(OBJ)/$(UTL)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/$(ASM)/%.o : $(SRC_ASM)/%.c
	@mkdir -p  $(OBJ)/$(ASM)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/$(PARSE)/%.o : $(SRC_PARSE)/%.c
	@mkdir -p $(OBJ)/$(PARSE)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/$(PARSE)/asm_mipsyac.o : $(SRC_PARSE)/asm_mipsyac.cpp
	@mkdir -p $(OBJ)/$(PARSE)
	$(CPP) $(CFLAGS) -E -c -o $@.c $<
	$(CPP) $(CFLAGS) -c -o $@ $<

$(SRC_PARSE)/asm_mipsyac.cpp $(INCLUDE)/asm_mipsyac.h : $(SRC_PARSE)/asm_mips.yac
	cd $(SRC_PARSE) && $(YACC) -d -p asm_mips asm_mips.yac
	mv $(SRC_PARSE)/y.tab.c $@
	mv $(SRC_PARSE)/y.tab.h $(INCLUDE)/asm_mipsyac.h

$(SRC_PARSE)/asm_mipslex.c : $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mips.lex
	$(LEX) -Pasm_mips -o $@ $(SRC_PARSE)/asm_mips.lex

# Tests

.PHONY : testparse test1 test1a

testparse:$(SRC)/$(EX)/complete.s bin/cpp/main_test
	./bin/cpp/main_test

# Recette tests

test1:test1a

LAUNCHER1a=test_01a
GCCMIPS=mipsel-linux-gnu-gcc

$(SRC)/$(EX)/test/%.s:$(SRC)/$(EX)/test/%.c
	$(GCCMIPS) -S -o $@ $<
	

test1a:$(BIN)/$(CP)/$(LAUNCHER1a) $(SRC)/$(EX)/test/test_01a.s
	./$<


# Show tokens

.PHONY : tokens

tokens : $(SRC_PARSE)/asm_mips.yac
	@cat $< | tail -n+$$((`grep -n %% $< | head -n 1 | cut -d: -f1`+1)) | grep -ve '^[[:space:]]' | grep -ve '^$$' | head -n-1
	@#cat $< | tail -n+332 | grep -ve '^[[:space:]]' | grep -ve '^$$' | head -n-1
	@#grep -n %% $< | head -n 1 | cut -d: -f1
	@#echo toto $$((`grep -n %% $< | head -n 1 | cut -d: -f1`+1))

# produce ASM Tests files

.PHONY : examples

examples : $(EX_SFILES)

$(TMP)/$(EX)/%.s : $(SRC)/$(EX)/%.c
	mkdir -p $(TMP)/$(EX)/
	$(CCMIPS) -S -o $@ $<

# Project managment rules

clean :
	rm -rf $(OBJ) $(BIN) $(TMP)
	rm -f $(OBJ)/*.o $(OBJ)/$(ASM)/*.o $(OBJ)/$(UTL)/*.o $(BIN)/* $(OBJ)/$(PARSE)/*.o $(OBJ)/$(BASE)/*.o 
	rm -f $(SRC_PARSE)/asm_mipsyac.c* $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mipslex.c $(SRC_PARSE)/asm_mips.tab.*ac 
	rm -f lex.asm_mips.c

# Directories : git cant deal with empty directories, so we have to create them just in time
# Should work without this fix
#$(BIN) $(BIN)/$(C) $(BIN)/$(CP) $(OBJ) $(OBJ)/$(UTL) $(OBJ)/$(ASM) $(OBJ)/$(PARSE) $(OBJ)/$(BASE):
#	@mkdir -p $@

# GIT stuff

.PHONY : git-commit git-push git-pull

HOST="github.com"
PROJECT="VLambret/libASM.git"

git-commit :
	git add * ;	git commit -a

# Get changes on upstream
git-pull : 
	git pull

# Push changes to upstream
git-push :
	git add * ; git push git@$(HOST):$(PROJECT) master

