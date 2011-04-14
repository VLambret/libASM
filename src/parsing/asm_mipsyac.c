
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         asm_mipsparse
#define yylex           asm_mipslex
#define yyerror         asm_mipserror
#define yylval          asm_mipslval
#define yychar          asm_mipschar
#define yydebug         asm_mipsdebug
#define yynerrs         asm_mipsnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 10 "asm_mips.yac"

#include <stdlib.h>
#include <stdio.h>
#include "utl200.h"
#include "asm200.h"
//#include UTL_H
//#include ASM_H

#undef  yylex
#define yylex         asm_mipslex
#define yyrestart     asm_mipsrestart
#define yyin          asm_mipsin

extern int            yylex     ();
extern void           yyrestart ();
extern int            yyparse   ();
extern FILE          *yyin        ;
/*
static int            PAS_NBR     = ASM_ASP__SIZEOF   ;	// pass number	
static char          *FIL_NAM     = NULL              ;	// file name	

static char          *PRG_NAM     = NULL              ;	// prg name	

static struct asfig  *PT_FIG      = NULL              ;
static struct asobj  *PT_OBJ      = NULL              ;

static struct utdic  *GLB_DIC     = NULL              ;	// global dict	
static struct uttyp  *GLB_SYM     = NULL              ;	// global symb	

static unsigned int   MCR_WRDS [8]                    ;	// macro words	
static int            MCR_WNBR    = 0                 ;	// macro word #	
static unsigned int   SET_FLAGS   = 0                 ;	// set direc	

static struct uttyp  *SEC_SYM     = NULL              ;	// current symb	
static unsigned int   CUR_ADR     = 0                 ;	// current adr	
static unsigned int   CUR_SIZ     = 0                 ;	// current size	
static struct asiss  *PT_ISS      = NULL              ;	// current a-sz	

static struct uttyp  *MEM_TAB     = NULL              ;	// memory table	
*/
// ###--------------------------------------------------------------### 
// function	: yyerror						
// description	: print yacc error messages				
// called func.	: none							
// ###--------------------------------------------------------------### 

//*

static unsigned int   ERR_FLG     = 0                 ;	// error flag	

static void yyerror (str)

char *str;
{
	printf("yyerror ligne=%d, flag=%d\n, str=%s",ASM_LINENO,ERR_FLG,str) ;
	ERR_FLG     = 0                 ;	// error flag	
}
/*
  {
  ERR_FLG += asm_error (16, FIL_NAM, ASM_LINENO, str, 0);

  if (ERR_FLG > ASM_MAXERR)
    ERR_FLG += asm_error (17, FIL_NAM, ASM_LINENO, NULL, 0);
  }
 */
//*/

// ###--------------------------------------------------------------### 
// function	: lcl_error						
// description	: print an error message				
// called func.	: asm_error						
// ###--------------------------------------------------------------### 
/*
static void lcl_error (code, str, nbr)

unsigned int  code;
char         *str ;
int           nbr ;

  {
  ERR_FLG += asm_error (code, FIL_NAM, ASM_LINENO, str, nbr);

  if (ERR_FLG > ASM_MAXERR)
    ERR_FLG += asm_error (17, FIL_NAM, ASM_LINENO, NULL, 0);
  }
*/
// ###--------------------------------------------------------------### 
// function	: lcl_isbch						
// description	: return non zero value if an instruction is a branch	
// ###--------------------------------------------------------------### 

static unsigned int lcl_isbch (ins_wrd)

unsigned int ins_wrd;

  {
  unsigned int flag = 0;

  if ((ins_wrd & ASM_MPS__I_MSK ) == ASM_MPS__BEQ   ) flag = 1 ;
  if ((ins_wrd & ASM_MPS__IB_MSK) == ASM_MPS__BGEZ  ) flag = 1 ;
  if ((ins_wrd & ASM_MPS__IB_MSK) == ASM_MPS__BGEZAL) flag = 1 ;
  if ((ins_wrd & ASM_MPS__I_MSK ) == ASM_MPS__BGTZ  ) flag = 1 ;
  if ((ins_wrd & ASM_MPS__I_MSK ) == ASM_MPS__BLEZ  ) flag = 1 ;
  if ((ins_wrd & ASM_MPS__IB_MSK) == ASM_MPS__BLTZ  ) flag = 1 ;
  if ((ins_wrd & ASM_MPS__IB_MSK) == ASM_MPS__BLTZAL) flag = 1 ;
  if ((ins_wrd & ASM_MPS__I_MSK ) == ASM_MPS__BNE   ) flag = 1 ;

  return (flag);
  }

// ###--------------------------------------------------------------### 
// function	: lcl_isjmp						
// description	: return non zero value if an instruction is a jump	
// ###--------------------------------------------------------------### 

static unsigned int lcl_isjmp (ins_wrd)

unsigned int ins_wrd;

  {
  unsigned int flag = 0;

  if ((ins_wrd & ASM_MPS__J_MSK ) == ASM_MPS__J     ) flag = 1;
  if ((ins_wrd & ASM_MPS__J_MSK ) == ASM_MPS__JAL   ) flag = 1;
  if ((ins_wrd & ASM_MPS__R_MSK ) == ASM_MPS__JR    ) flag = 1;
  if ((ins_wrd & ASM_MPS__R_MSK ) == ASM_MPS__JALR  ) flag = 1;

  return (flag);
  }

int main() {
	ASM_LINENO = 0 ;
  	yyparse ();
	return 0 ;
}

// ###--------------------------------------------------------------### 
// function	: asm_ldmipsasm						
// description	: parse a Mips assembly program. Return the description	
//		  if the file has been successfully read. Return	
//		  NULL or a description with an error flag set in case	
//		  of error						
// called func.	: yyparse						
// ###--------------------------------------------------------------### 

struct asfig *asm_ldmipsasm (fp, fil_name, pt_fig, pas_nbr)

FILE          *fp      ;
char          *fil_name;
struct asfig  *pt_fig  ;
unsigned int   pas_nbr ;

  {
	// ###------------------------------------------------------### 
	//    initialize global and static variables			
	// ###------------------------------------------------------### 
/*
  PT_FIG        = pt_fig          ;
  PT_FIG->FLAG |= ASM_FIG__ERROR  ;

  PAS_NBR       = pas_nbr         ;
  ERR_FLG       = 0               ;
  ASM_LINENO    = 1               ;
  FIL_NAM       = fil_name        ;

  PRG_NAM       = NULL            ;

  MCR_WNBR      = 0               ;
  SET_FLAGS     = ASM_SET_FLAGS   ;
  SEC_SYM       = NULL            ;
  CUR_ADR       = 0               ;
  CUR_SIZ       = 0               ;
  PT_ISS        = NULL            ;

  PT_FIG        = pt_fig          ;
  GLB_DIC       = pt_fig->GLB_DIC ;
  GLB_SYM       = pt_fig->GLB_SYM ;
  MEM_TAB       = pt_fig->MEM_TAB ;
  PT_OBJ        = asm_GetObject   (pt_fig, fil_name);
*/
  yyin          = fp              ;

  yyrestart (yyin);

	// ###------------------------------------------------------### 
	//   parse the input file					
	// ###------------------------------------------------------### 

  yyparse ();

	// ###------------------------------------------------------### 
	//   release the dictionary					
	// ###------------------------------------------------------### 
/*
  if (ERR_FLG == 0)
    {
    if (PT_ISS != NULL)
      PT_ISS->SIZE = CUR_SIZ;

    pt_fig->GLB_SYM  =  GLB_SYM       ;
    pt_fig->MEM_TAB  =  MEM_TAB       ;
    pt_fig->FLAG    &= ~ASM_FIG__ERROR;
    }

  return (pt_fig);
*/
	return NULL ;
  }



/* Line 189 of yacc.c  */
#line 293 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ALIGN_ = 258,
     _ASCII_ = 259,
     _ASCIIZ_ = 260,
     _BYTE_ = 261,
     _COMM_ = 262,
     _END_ = 263,
     _ENT_ = 264,
     _EQU_ = 265,
     _EXTERN_ = 266,
     _GLOBAL_ = 267,
     _LCOMM_ = 268,
     _NOREORDER_ = 269,
     _REORDER_ = 270,
     _SECTION_ = 271,
     _SET_ = 272,
     _SKIP_ = 273,
     _SPACE_ = 274,
     _WORD_ = 275,
     ARegister = 276,
     Ampersand = 277,
     Bar = 278,
     CarriageReturn = 279,
     Circomflex = 280,
     Codop_hint_mem = 281,
     Codop_label = 282,
     Codop_n = 283,
     Codop_od_rs = 284,
     Codop_rd = 285,
     Codop_rd_si16 = 286,
     Codop_rd_rs = 287,
     Codop_rd_rs_rt = 288,
     Codop_rd_rt_sham = 289,
     Codop_rd_rt_rs = 290,
     Codop_rd_rs_si16 = 291,
     Codop_rd_rs_ui16 = 292,
     Codop_rd_mem = 293,
     Codop_rs = 294,
     Codop_rs_label = 295,
     Codop_rs_rt = 296,
     Codop_rs_rt_label = 297,
     Codop_rs_si16 = 298,
     Codop_rt_cop0r = 299,
     Codop_rt_cop2r = 300,
     Codop_rt_mem = 301,
     Codop_ui20 = 302,
     Colon = 303,
     Comma = 304,
     Cop0Register = 305,
     DoubleGreat = 306,
     DoubleLess = 307,
     Identifier = 308,
     IntegerRegister = 309,
     LeftParen = 310,
     Litteral = 311,
     Macro_label = 312,
     Macro_n = 313,
     Macro_rd_i32 = 314,
     Macro_rd_rs = 315,
     Macro_rd_rt = 316,
     Macro_rd_label = 317,
     Macro_rs_label = 318,
     Minus = 319,
     Plus = 320,
     Register = 321,
     RightParen = 322,
     Slash = 323,
     Star = 324,
     String = 325,
     Tilda = 326
   };
#endif
/* Tokens.  */
#define _ALIGN_ 258
#define _ASCII_ 259
#define _ASCIIZ_ 260
#define _BYTE_ 261
#define _COMM_ 262
#define _END_ 263
#define _ENT_ 264
#define _EQU_ 265
#define _EXTERN_ 266
#define _GLOBAL_ 267
#define _LCOMM_ 268
#define _NOREORDER_ 269
#define _REORDER_ 270
#define _SECTION_ 271
#define _SET_ 272
#define _SKIP_ 273
#define _SPACE_ 274
#define _WORD_ 275
#define ARegister 276
#define Ampersand 277
#define Bar 278
#define CarriageReturn 279
#define Circomflex 280
#define Codop_hint_mem 281
#define Codop_label 282
#define Codop_n 283
#define Codop_od_rs 284
#define Codop_rd 285
#define Codop_rd_si16 286
#define Codop_rd_rs 287
#define Codop_rd_rs_rt 288
#define Codop_rd_rt_sham 289
#define Codop_rd_rt_rs 290
#define Codop_rd_rs_si16 291
#define Codop_rd_rs_ui16 292
#define Codop_rd_mem 293
#define Codop_rs 294
#define Codop_rs_label 295
#define Codop_rs_rt 296
#define Codop_rs_rt_label 297
#define Codop_rs_si16 298
#define Codop_rt_cop0r 299
#define Codop_rt_cop2r 300
#define Codop_rt_mem 301
#define Codop_ui20 302
#define Colon 303
#define Comma 304
#define Cop0Register 305
#define DoubleGreat 306
#define DoubleLess 307
#define Identifier 308
#define IntegerRegister 309
#define LeftParen 310
#define Litteral 311
#define Macro_label 312
#define Macro_n 313
#define Macro_rd_i32 314
#define Macro_rd_rs 315
#define Macro_rd_rt 316
#define Macro_rd_label 317
#define Macro_rs_label 318
#define Minus 319
#define Plus 320
#define Register 321
#define RightParen 322
#define Slash 323
#define Star 324
#define String 325
#define Tilda 326




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 222 "asm_mips.yac"

  struct utchn  *pchn    ;
  unsigned int   uval    ;
  char          *text    ;
  


/* Line 214 of yacc.c  */
#line 479 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 491 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    14,    15,    18,
      22,    25,    28,    30,    32,    35,    36,    40,    42,    44,
      46,    48,    50,    53,    56,    57,    59,    63,    65,    69,
      73,    78,    83,    85,    89,    93,    97,   101,   105,   108,
     116,   119,   121,   124,   129,   132,   140,   147,   152,   157,
     162,   169,   176,   183,   190,   197,   200,   205,   210,   217,
     222,   227,   232,   240,   247,   252,   255,   258,   260,   262,
     264,   266,   268,   270,   272,   274,   276,   278,   280,   282,
     284,   286,   288,   290,   292,   294,   296,   299,   301,   306,
     311,   316,   321,   326,   328,   330,   332,   334,   336,   338,
     340,   342,   345,   348,   351,   356,   363,   366,   369,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   427,   429,   432,   435,
     437,   439,   441,   444,   447,   449,   451,   453,   455,   457,
     459,   461,   463,   464,   466,   468,   470,   473,   474
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      78,     0,    -1,    65,    -1,    64,    -1,    -1,   122,    48,
      -1,     3,    56,    -1,    -1,    76,    77,    -1,    74,   150,
      82,    -1,   149,    82,    -1,     1,    82,    -1,    79,    -1,
      76,    -1,   120,    81,    -1,    -1,    81,    49,   120,    -1,
      24,    -1,    50,    -1,    21,    -1,   142,    -1,   125,    -1,
       8,    88,    -1,     9,    53,    -1,    -1,    53,    -1,    53,
      10,   120,    -1,    91,    -1,    90,    73,    91,    -1,    55,
     120,    67,    -1,    71,    55,   120,    67,    -1,    64,    55,
     120,    67,    -1,   148,    -1,    91,   124,    91,    -1,    92,
     124,    91,    -1,    91,   143,    91,    -1,    93,    69,    91,
      -1,    91,   147,    91,    -1,    11,   122,    -1,    26,   120,
      49,   119,    55,   121,    67,    -1,    27,   120,    -1,    28,
      -1,    29,   121,    -1,    29,   121,    49,   121,    -1,    30,
     121,    -1,    38,   121,    49,   119,    55,   121,    67,    -1,
      38,   121,    49,    55,   121,    67,    -1,    38,   121,    49,
     120,    -1,    31,   121,    49,   119,    -1,    32,   121,    49,
     121,    -1,    33,   121,    49,   121,    49,   121,    -1,    36,
     121,    49,   121,    49,   119,    -1,    37,   121,    49,   121,
      49,   151,    -1,    35,   121,    49,   121,    49,   121,    -1,
      34,   121,    49,   121,    49,   120,    -1,    39,   121,    -1,
      40,   121,    49,   120,    -1,    41,   121,    49,   121,    -1,
      42,   121,    49,   121,    49,   120,    -1,    43,   121,    49,
     119,    -1,    44,   121,    49,    83,    -1,    45,   121,    49,
      84,    -1,    46,   121,    49,   119,    55,   121,    67,    -1,
      46,   121,    49,    55,   121,    67,    -1,    46,   121,    49,
     120,    -1,    47,   120,    -1,    12,   122,    -1,   120,    -1,
      90,    -1,    93,    -1,    92,    -1,    94,    -1,    54,    -1,
      21,    -1,    53,    -1,   133,    -1,    23,    -1,    22,    -1,
      25,    -1,   128,    -1,   129,    -1,   130,    -1,   131,    -1,
     132,    -1,   126,    -1,   127,    -1,    57,   120,    -1,    58,
      -1,    59,   121,    49,   120,    -1,    62,   121,    49,   120,
      -1,    60,   121,    49,   121,    -1,    61,   121,    49,   121,
      -1,    63,   121,    49,   120,    -1,   141,    -1,   136,    -1,
     134,    -1,   135,    -1,   140,    -1,   139,    -1,   138,    -1,
     137,    -1,     4,    70,    -1,     5,    70,    -1,     6,    80,
      -1,    13,    53,    49,    56,    -1,     7,    53,    49,    56,
      49,    56,    -1,    19,    56,    -1,    18,    56,    -1,    20,
     152,    -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,
     100,    -1,   101,    -1,   103,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   102,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    -1,   116,    -1,
     114,    -1,   115,    -1,   117,    -1,    69,    -1,    68,    -1,
      56,    -1,    53,    -1,    16,    53,    -1,    53,    -1,    17,
      15,    -1,    17,    14,    -1,    52,    -1,    51,    -1,   144,
      -1,    64,   144,    -1,    71,   144,    -1,    75,    -1,   145,
      -1,    89,    -1,   118,    -1,    95,    -1,   146,    -1,    87,
      -1,    86,    -1,    -1,   123,    -1,    85,    -1,   120,    -1,
     120,   153,    -1,    -1,   153,    49,   120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   330,   330,   333,   338,   340,   393,   416,   418,   423,
     426,   428,   433,   447,   451,   467,   468,   479,   485,   491,
     502,   503,   507,   519,   533,   534,   540,   575,   578,   589,
     594,   600,   606,   612,   621,   633,   641,   651,   662,   667,
     688,   703,   711,   717,   728,   737,   748,   758,   777,   788,
     799,   812,   825,   847,   860,   882,   891,   914,   925,   950,
     961,   972,   983,   994,  1004,  1022,  1037,  1057,  1071,  1073,
    1075,  1077,  1082,  1084,  1094,  1099,  1103,  1105,  1107,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1122,  1143,  1151,  1169,
    1187,  1198,  1209,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1243,  1263,  1284,  1304,  1391,  1488,  1497,  1506,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1551,  1553,  1558,  1560,  1587,  1628,  1671,  1677,  1686,
    1688,  1693,  1695,  1698,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1714,  1716,  1717,  1753,  1766,  1783,  1784
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ALIGN_", "_ASCII_", "_ASCIIZ_",
  "_BYTE_", "_COMM_", "_END_", "_ENT_", "_EQU_", "_EXTERN_", "_GLOBAL_",
  "_LCOMM_", "_NOREORDER_", "_REORDER_", "_SECTION_", "_SET_", "_SKIP_",
  "_SPACE_", "_WORD_", "ARegister", "Ampersand", "Bar", "CarriageReturn",
  "Circomflex", "Codop_hint_mem", "Codop_label", "Codop_n", "Codop_od_rs",
  "Codop_rd", "Codop_rd_si16", "Codop_rd_rs", "Codop_rd_rs_rt",
  "Codop_rd_rt_sham", "Codop_rd_rt_rs", "Codop_rd_rs_si16",
  "Codop_rd_rs_ui16", "Codop_rd_mem", "Codop_rs", "Codop_rs_label",
  "Codop_rs_rt", "Codop_rs_rt_label", "Codop_rs_si16", "Codop_rt_cop0r",
  "Codop_rt_cop2r", "Codop_rt_mem", "Codop_ui20", "Colon", "Comma",
  "Cop0Register", "DoubleGreat", "DoubleLess", "Identifier",
  "IntegerRegister", "LeftParen", "Litteral", "Macro_label", "Macro_n",
  "Macro_rd_i32", "Macro_rd_rs", "Macro_rd_rt", "Macro_rd_label",
  "Macro_rs_label", "Minus", "Plus", "Register", "RightParen", "Slash",
  "Star", "String", "Tilda", "$accept", "adding_operator", ".a_label.",
  "align_directive", "..an_instruction..", "an_instruction",
  "assembly_file", "assembly_instructions", "byte_immediate_list",
  "...byte_immediate..", "CarriageReturn_ERR", "cop0_reg", "cop2_reg",
  "effective_instruction", "end_directive", "ent_directive",
  ".Identifier.", "equ_directive", "expr..addop__expr..", "expression",
  "expr__logop__expr..logop__expr..", "expr__mulop__expr..mulop__expr..",
  "expr__shfop__expr", "extern_directive", "format_hint_mem",
  "format_label", "format_n", "format_od_rs", "format_rd", "format_rd_mem",
  "format_rd_si16", "format_rd_rs", "format_rd_rs_rt", "format_rd_rs_si16",
  "format_rd_rs_ui16", "format_rd_rt_rs", "format_rd_rt_sham", "format_rs",
  "format_rs_label", "format_rs_rt", "format_rs_rt_label",
  "format_rs_si16", "format_rt_cop0r", "format_rt_cop2r", "format_rt_mem",
  "format_ui20", "global_directive", "signed_16_bit_immediate",
  "immediate", "integer_register", "label", "labelable_directive",
  "logic_operator", "macro_instruction", "macro_label", "macro_n",
  "macro_rd_i32", "macro_rd_label", "macro_rd_rs", "macro_rd_rt",
  "macro_rs_label", "memory_alloc_directive", "memory_ascii_alloc",
  "memory_asciiz_alloc", "memory_byte_alloc", "memory_lcomm_alloc",
  "memory_comm_alloc", "memory_space_alloc", "memory_skip_alloc",
  "memory_word_alloc", "mips_instruction", "mul_div_operator", "primary",
  "section_specification_directive", "set_directive", "shift_operator",
  "term", "unlabeled_directive", ".unlabeled_instruction.",
  "unsigned_16_bit_immediate", "word_immediate_list",
  "...word_immediate..", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      77,    77,    78,    79,    80,    81,    81,    82,    83,    84,
      85,    85,    86,    87,    88,    88,    89,    90,    90,    91,
      91,    91,    91,    92,    92,    93,    93,    94,    95,    96,
      97,    98,    99,    99,   100,   101,   101,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   116,   116,   117,   118,   119,   120,   120,
     120,   120,   121,   121,   122,   123,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   148,   149,   149,   149,   149,   149,   149,
     149,   149,   150,   150,   150,   151,   152,   153,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     0,     2,     3,
       2,     2,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     2,     2,     0,     1,     3,     1,     3,     3,
       4,     4,     1,     3,     3,     3,     3,     3,     2,     7,
       2,     1,     2,     4,     2,     7,     6,     4,     4,     4,
       6,     6,     6,     6,     6,     2,     4,     4,     6,     4,
       4,     4,     7,     6,     4,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     6,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    12,     0,     0,    24,     0,     0,     0,
       0,     0,    74,   152,   144,     8,   151,   150,   146,   148,
     147,     0,   145,   149,     0,     1,    17,    11,     6,    25,
      22,    23,    74,    38,    66,   135,   138,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,   154,   109,   110,   111,
     112,   113,   114,   121,   115,   116,   117,   118,   119,   120,
     122,   123,   124,   125,   126,   128,   129,   127,   130,   153,
      21,    84,    85,    79,    80,    81,    82,    83,    75,    95,
      96,    94,   100,    99,    98,    97,    93,    20,     0,     5,
      10,   134,     0,   133,     0,     0,    68,    27,    70,    69,
      71,    26,   141,    32,   101,   102,   103,    15,     0,     0,
     107,   106,   157,   108,     0,    40,    73,    72,    42,    44,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    65,    86,     0,     0,
       0,     0,     0,     9,     0,     0,   142,     0,   143,     3,
       2,     0,    77,    76,    78,   140,   139,   132,   131,     0,
       0,     0,     0,     0,    14,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    28,    33,    35,    37,    34,    36,     0,
       0,   104,     0,     0,    67,    43,    48,    49,     0,     0,
       0,     0,     0,     0,     0,    47,    56,    57,     0,    59,
      18,    60,    19,    61,     0,     0,    64,    88,    90,    91,
      89,    92,    31,    30,    16,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
      50,    54,    53,    51,   155,    52,    46,     0,    58,    63,
       0,    39,    45,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   181,    13,    14,     1,    15,     2,     3,   136,   194,
      27,   251,   253,    76,    16,    17,    30,    18,   126,   127,
     128,   129,   130,    19,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    20,   233,   234,   148,
      21,    99,   189,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   190,   132,    22,    23,   191,   133,    24,   118,   285,
     143,   197
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -197
static const yytype_int16 yypact[] =
{
    -197,    85,    13,  -197,     3,   -12,    23,    24,    25,    25,
      26,    -8,    -5,   250,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,    19,  -197,  -197,     3,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   -39,    10,
      11,   -39,    34,    46,    44,    50,   -39,   -39,   -39,  -197,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -39,   -39,
    -197,   -19,   -19,   -19,   -19,   -19,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,     3,  -197,
    -197,  -197,   -39,  -197,   -27,   -15,   -31,    14,    20,    39,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,    58,    61,
    -197,  -197,  -197,  -197,    84,  -197,  -197,  -197,    86,  -197,
      87,    92,   101,   105,   108,   109,   110,   112,  -197,   113,
     114,   116,   117,   129,   130,   133,  -197,  -197,   135,   136,
     137,   138,   139,  -197,    67,   -39,  -197,   -39,  -197,  -197,
    -197,   -39,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   -39,
     -39,   -39,   -39,   -39,   140,   141,   148,   143,   -39,   -19,
     -39,   -19,   -19,   -19,   -19,   -19,   -19,    96,   -39,   -19,
     -19,   -39,   118,   172,   100,   -39,   -19,   -19,   -39,   -39,
    -197,   128,   142,  -197,  -197,  -197,  -197,  -197,  -197,   -39,
     159,  -197,   -39,   155,  -197,  -197,  -197,  -197,   162,   163,
     166,   168,   169,   119,   164,   165,  -197,  -197,   173,  -197,
    -197,  -197,  -197,  -197,   119,   170,   165,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,   167,  -197,   -19,   -19,   -39,
     -19,   -39,   -39,   154,   -19,   -39,   157,   -19,  -197,   160,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,   161,  -197,  -197,
     171,  -197,  -197,  -197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
     -23,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -169,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -196,   -38,    -3,
      38,  -197,    98,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   -51,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -137
static const yytype_int16 yytable[] =
{
     131,   120,   146,   137,   236,    38,    36,    37,   142,   144,
     145,   244,   223,    25,   121,   249,   122,   123,   255,  -136,
     224,   225,   226,   227,   228,   124,   121,    26,   175,   123,
     166,   167,   125,   179,   180,   147,   182,   183,   121,   184,
     177,   123,   182,   183,    28,   184,    33,    34,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   185,   186,   119,   168,   169,
     170,   171,   172,   176,   178,   283,    29,    31,    32,    35,
     134,   135,   187,   188,   174,   -13,     4,   138,     5,    -4,
      -4,    -4,    -4,     6,     7,   173,     8,     9,    -4,   139,
     140,    10,    11,    -4,    -4,    -4,   141,   195,   193,    -4,
     196,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   198,   220,   199,   200,   221,    12,   222,
     146,   201,    -4,    -4,    -4,    -4,    -4,    -4,    -4,   121,
     202,   243,   123,   121,   203,   254,   123,   204,   205,   206,
     124,   207,   208,   209,   124,   210,   211,   125,   250,   245,
     246,   125,   121,   147,   122,   123,   256,   257,   212,   213,
     260,   261,   214,   124,   215,   216,   217,   218,   219,   229,
     125,   264,   232,   252,   266,   262,   235,   230,   237,   238,
     239,   240,   241,   242,   231,   174,   247,   248,   265,   263,
     267,   268,   269,   258,   259,   270,   174,   271,   272,   274,
     -67,   286,   275,   278,   289,   277,   192,   291,   292,     0,
       0,   281,     0,     0,   284,     0,     0,   288,   293,     0,
     273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,    39,    40,    41,    42,     0,     0,
       0,     0,     0,    43,   279,   280,     0,   282,    44,    45,
      46,   287,     0,     0,   290,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      38,    24,    21,    41,   200,    10,    14,    15,    46,    47,
      48,   207,   181,     0,    53,   211,    55,    56,   214,    24,
     189,   190,   191,   192,   193,    64,    53,    24,    55,    56,
      68,    69,    71,    64,    65,    54,    22,    23,    53,    25,
      55,    56,    22,    23,    56,    25,     8,     9,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    51,    52,    48,    71,    72,
      73,    74,    75,   124,   125,   271,    53,    53,    53,    53,
      70,    70,    68,    69,   122,     0,     1,    53,     3,     4,
       5,     6,     7,     8,     9,   118,    11,    12,    13,    53,
      56,    16,    17,    18,    19,    20,    56,    49,    69,    24,
      49,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,    67,    49,    49,   175,    53,   177,
      21,    49,    57,    58,    59,    60,    61,    62,    63,    53,
      49,    55,    56,    53,    49,    55,    56,    49,    49,    49,
      64,    49,    49,    49,    64,    49,    49,    71,    50,   207,
     208,    71,    53,    54,    55,    56,   214,   215,    49,    49,
     218,   219,    49,    64,    49,    49,    49,    49,    49,    49,
      71,   229,    49,    21,   232,    67,   199,    56,   201,   202,
     203,   204,   205,   206,    56,   243,   209,   210,    49,    67,
      55,    49,    49,   216,   217,    49,   254,    49,    49,    55,
      55,    67,    49,    56,    67,    55,   128,    67,    67,    -1,
      -1,   269,    -1,    -1,   272,    -1,    -1,   275,    67,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,   267,   268,    -1,   270,    18,    19,
      20,   274,    -1,    -1,   277,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,    78,    79,     1,     3,     8,     9,    11,    12,
      16,    17,    53,    74,    75,    77,    86,    87,    89,    95,
     118,   122,   145,   146,   149,     0,    24,    82,    56,    53,
      88,    53,    53,   122,   122,    53,    14,    15,    10,     4,
       5,     6,     7,    13,    18,    19,    20,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    57,
      58,    59,    60,    61,    62,    63,    85,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   123,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   150,    48,
      82,    53,    55,    56,    64,    71,    90,    91,    92,    93,
      94,   120,   144,   148,    70,    70,    80,   120,    53,    53,
      56,    56,   120,   152,   120,   120,    21,    54,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   120,   120,   121,   121,
     121,   121,   121,    82,   120,    55,   144,    55,   144,    64,
      65,    73,    22,    23,    25,    51,    52,    68,    69,   124,
     143,   147,   124,    69,    81,    49,    49,   153,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      67,   120,   120,    91,    91,    91,    91,    91,    91,    49,
      56,    56,    49,   119,   120,   121,   119,   121,   121,   121,
     121,   121,   121,    55,   119,   120,   120,   121,   121,   119,
      50,    83,    21,    84,    55,   119,   120,   120,   121,   121,
     120,   120,    67,    67,   120,    49,   120,    55,    49,    49,
      49,    49,    49,   121,    55,    49,   121,    55,    56,   121,
     121,   120,   121,   119,   120,   151,    67,   121,   120,    67,
     121,    67,    67,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 331 "asm_mips.yac"
    { printf("adding_operator plus\n") ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 334 "asm_mips.yac"
    { printf("adding_operator minus\n") ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 342 "asm_mips.yac"
    {
		/*
		struct utdic *dic     = NULL;
		struct uttyp *sym_lst = NULL;
		unsigned int  status  ;

		// ###----------------------------------------------### 
		//   check that the label is unique. Save its address	
		// in the dictionary.					
		// ###----------------------------------------------### 

		if (PAS_NBR == ASM_ASP__LABELS)
		  {
		  dic    = PT_OBJ->SYM_DIC;
		  status = utl_GetDicItemStatus (dic, $1);

		  if (status == UTL_DIC__FAILED)
		    {
		    if (SEC_SYM != NULL)
		      {
		      utl_AddDicItem (dic, $1, CUR_ADR);

		// ###----------------------------------------------### 
		//   if the label is declared as global, save it in the	
		// global symbols dictionary				
		// ###----------------------------------------------### 

		      status = utl_GetDicItemStatus (GLB_DIC, $1);

		      if (status == UTL_DIC__SUCCEED)
		        utl_AddDicItem (GLB_DIC, $1, CUR_ADR);

		// ###----------------------------------------------### 
		//   save the label's address in the symbol's list	
		// ###----------------------------------------------### 

		      sym_lst            = (struct uttyp *) SEC_SYM->DAT2.VPNT;
		      SEC_SYM->DAT2.VPNT = utl_adduttyp (sym_lst, $1, CUR_ADR);
		      }
		    else
		      lcl_error (13, NULL, 0);
		    }
		  else
		    lcl_error (2, $1, 0);
		  }
		  */
		  printf("label\n");
		}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 395 "asm_mips.yac"
    {
		/*
		unsigned int msk = 0x00000001;
		unsigned int adr ;

		// ###----------------------------------------------### 
		//   align the current address				
		// ###----------------------------------------------### 

		if ($2 > 31)
		  lcl_error (18, NULL, $2);

		msk      = msk << $2 ;
		adr      = (CUR_ADR + (msk - 1)) & (~ (msk - 1));
		CUR_SIZ += (adr     -  CUR_ADR )                ;
		CUR_ADR  =  adr                                 ;
		*/
		printf("align\n") ;
		}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 434 "asm_mips.yac"
    {
		/*
		if  (PRG_NAM != NULL)
		  lcl_error (19, NULL, 0);

		if  (PAS_NBR == ASM_ASP__SIZEOF )
		  PT_FIG->OBJECTS = asm_addasobj (PT_FIG->OBJECTS, FIL_NAM);
		 */
		 printf("programme assembleur\n") ;
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 453 "asm_mips.yac"
    {
		/*
		struct utchn *pt_chn;

		pt_chn = utl_revutchn ($2                     );
		$$     = utl_addutchn (pt_chn, $1 & 0x000000ff);
		*/
		printf("byte_immediate_list\n") ;
		}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 467 "asm_mips.yac"
    { printf("byte_immediate NULL\n") ; }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 471 "asm_mips.yac"
    {
		//$$ = utl_addutchn ($1, $3 & 0x000000ff);
		printf("byte_immediate\n") ;
		}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 481 "asm_mips.yac"
    { printf("CariageReturn_ERR\n") ; }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 487 "asm_mips.yac"
    { printf("cop0_reg\n") ; }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 492 "asm_mips.yac"
    { printf("cop2_reg\n") ; }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 509 "asm_mips.yac"
    { printf("end_directive\n") ; }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 521 "asm_mips.yac"
    { printf("ent_directive\n") ; }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 533 "asm_mips.yac"
    { printf("Identifier NULL\n") ; }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 536 "asm_mips.yac"
    { printf("Identifier\n") ; }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 543 "asm_mips.yac"
    { printf("equ_directive\n") ; }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 576 "asm_mips.yac"
    { printf("expr..addop__expr.. expression\n") ; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 581 "asm_mips.yac"
    { printf("expr..addop__expr.. add\n") ; }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 592 "asm_mips.yac"
    { printf("expression\n") ; }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 598 "asm_mips.yac"
    { printf("expression ~\n") ; }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 604 "asm_mips.yac"
    { printf("expression minus\n") ; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 607 "asm_mips.yac"
    { printf("expression term\n") ; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 615 "asm_mips.yac"
    { printf("expr__logop__expr..logop__expr..\n") ; }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 624 "asm_mips.yac"
    { printf("expr__logop__expr..logop__expr..\n") ; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 636 "asm_mips.yac"
    { printf("expr__mulop__expr..mulop__expr..\n") ; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 644 "asm_mips.yac"
    { printf("expr__mulop__expr..mulop__expr..\n") ; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 654 "asm_mips.yac"
    { printf("expr__shfop__expr\n") ; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 674 "asm_mips.yac"
    { printf("format_hint_mem\n") ; }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 690 "asm_mips.yac"
    { printf("format_label\n") ; }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 704 "asm_mips.yac"
    { printf("format_n\n") ; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 713 "asm_mips.yac"
    { printf("format_od_rs\n") ; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 721 "asm_mips.yac"
    { printf("format_od_rs negation\n") ; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 730 "asm_mips.yac"
    { printf("format_rd\n") ; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 744 "asm_mips.yac"
    { printf("format_rd_mem\n") ; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 754 "asm_mips.yac"
    { printf("format_rd_mem\n") ; }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 762 "asm_mips.yac"
    { printf("format_rd_mem\n") ; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 781 "asm_mips.yac"
    { printf("format_rd_si6\n") ; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 792 "asm_mips.yac"
    { printf("format_rd_rs\n") ; }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 805 "asm_mips.yac"
    { printf("format_rd_rs_rt\n") ; }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 818 "asm_mips.yac"
    { printf("format_rd_rs_si16\n") ; }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 831 "asm_mips.yac"
    { printf("format_rd_rs_ui16\n") ; }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 853 "asm_mips.yac"
    { printf("format_rd_rt_rs\n") ; }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 866 "asm_mips.yac"
    { printf("format_rd_rt_sham\n") ; }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 884 "asm_mips.yac"
    { printf("format_rs\n") ; }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 895 "asm_mips.yac"
    { printf("format_rs_label\n") ; }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 918 "asm_mips.yac"
    { printf("format_rs_rt\n") ; }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 931 "asm_mips.yac"
    { printf("format_rs_rt_label\n") ; }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 954 "asm_mips.yac"
    { printf("format_rs_si16\n") ; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 965 "asm_mips.yac"
    { printf("format_rt_cop0r\n") ; }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 976 "asm_mips.yac"
    { printf("format_rt_cop2r\n") ; }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 990 "asm_mips.yac"
    { printf("format_rt_mem\n") ; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1000 "asm_mips.yac"
    { printf("format_rt_mem\n") ; }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1008 "asm_mips.yac"
    { printf("format_rt_mem\n") ; }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1024 "asm_mips.yac"
    { printf("format_ui20\n") ; }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1039 "asm_mips.yac"
    { printf("global_directive\n") ; }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1058 "asm_mips.yac"
    { printf("signed_16_bit_immediate\n") ; }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1072 "asm_mips.yac"
    { printf("immediate\n") ; }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1074 "asm_mips.yac"
    { printf("immediate\n") ; }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1076 "asm_mips.yac"
    { printf("immediate\n") ; }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1078 "asm_mips.yac"
    { printf("immediate\n") ; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1083 "asm_mips.yac"
    { printf("integer_register\n") ; }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1085 "asm_mips.yac"
    { printf("integer_register\n") ; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1095 "asm_mips.yac"
    { printf("label\n") ; }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1104 "asm_mips.yac"
    { printf("logic_operator bar\n") ; }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1106 "asm_mips.yac"
    { printf("logic operator Ampersand\n") ; }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1108 "asm_mips.yac"
    { printf("logic_operator Circomflex\n") ; }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1124 "asm_mips.yac"
    { printf("macro_label\n") ; }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1144 "asm_mips.yac"
    { printf("macro_n\n") ; }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1155 "asm_mips.yac"
    { printf("macro_rd_i32\n") ; }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1173 "asm_mips.yac"
    { printf("macro_rd_label\n") ; }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1191 "asm_mips.yac"
    { printf("macro_rd_rs\n") ; }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1202 "asm_mips.yac"
    { printf("macro_rd_rt\n") ; }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1213 "asm_mips.yac"
    { printf("macro_rs_label\n") ; }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1245 "asm_mips.yac"
    { printf("memory_ascii_alloc\n") ; }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1265 "asm_mips.yac"
    { printf("memory_asciiz_alloc\n") ; }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1286 "asm_mips.yac"
    { printf("memory_byte_alloc\n") ; }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1308 "asm_mips.yac"
    { printf("memory_lcomm_alloc\n") ; }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1397 "asm_mips.yac"
    { printf("memory_comm_alloc\n") ; }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1490 "asm_mips.yac"
    { printf("memory_space_alloc\n") ; }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1499 "asm_mips.yac"
    { printf("memory_skip_alloc\n") ; }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1508 "asm_mips.yac"
    { printf("memory_word_alloc\n") ; }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1552 "asm_mips.yac"
    { printf("mul_div_operator *\n") ; }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1554 "asm_mips.yac"
    { printf("mul_div_operator /\n") ; }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1559 "asm_mips.yac"
    { printf("primary Litteral\n") ; }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1561 "asm_mips.yac"
    { printf("primary Identifier\n") ; }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1589 "asm_mips.yac"
    { printf("section_specification_directive SECTION\n") ; }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1629 "asm_mips.yac"
    { printf("section_specification_direction Identifier\n") ; }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1673 "asm_mips.yac"
    { printf("set_directive reorder\n") ; }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1679 "asm_mips.yac"
    { printf("set directive noreorder\n") ; }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1687 "asm_mips.yac"
    { printf("shift_operator <<\n") ; }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1689 "asm_mips.yac"
    { printf("shift_operator >>\n") ; }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1694 "asm_mips.yac"
    { printf("term primary\n") ; }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1697 "asm_mips.yac"
    { printf("term minus primary\n") ; }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1700 "asm_mips.yac"
    { printf("term ~\n") ; }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1718 "asm_mips.yac"
    { printf("unlabeled instruction\n") ; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1754 "asm_mips.yac"
    { printf("unsigned_16_bit_immediate\n") ; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1768 "asm_mips.yac"
    { printf("word_immediate_list\n") ; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1783 "asm_mips.yac"
    { printf("...word_immediate.. empty\n") ; }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1787 "asm_mips.yac"
    { printf("...word_immediate..\n") ; }
    break;



/* Line 1455 of yacc.c  */
#line 2768 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1798 "asm_mips.yac"


